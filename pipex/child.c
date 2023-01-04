/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:52:05 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/04 13:38:56 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
Then, we want a function that adds our command to the different possible paths with ft_strjoin. 
This function should also check each path to see if it is valid and accessible. 
The following system call from the <unistd.h> library will help with testing:

int access(const char *pathname, int mode);
Code language: C++ (cpp)
pathname is the path where we think the binary files of the program we want to execute are.
mode is what we want to know about this path. 
Here, we will want to check F_OK | X_OK to know if the file exists (F_OK) and if we can execute it (X_OK). 
We could also check its read and write permissions with R_OK and W_OK respectively.
This function will return 0 if all is well. 
If the file doesn’t exist or doesn’t have the correct permissions, it returns -1 instead.

*/

char *get_command(char **paths, char *cmd_args){
	char *aux;
	char *command;
	while (*paths){
		aux = ft_strjoin(*paths, "/");
		command = ft_strjoin(aux, cmd_args);
		//free(aux);
		if (access(command, F_OK | X_OK) == 0) // devuelve 0 si se ha permitido acceso, testear si el path es testeable y ejecutable
			return command;
		free(command);
		paths++;
	}
	return (NULL);
}

char *envp_path(int argc, char **envp){
	int i;

	i = 0;
	while (envp != NULL){
		if(ft_strncmp(envp[i], "PATH", 4) == 0)
			return (&envp[i][argc]);
		i++;
	}
	return (0);
}


/*
** Redirects standard output of the first command to the standard input of second command
** First command should write the result on pipe, later the second command are going to search this data on pipe

** We are going to call fork function to make a copy to the parent process for avoid overwrite the process with execve
** execve executes the program that makes reference the pathname
** First child is goint to work with the first command that we receives for console.
** Later, should close our pipes in children process to avoid future problems.

** With the first split we are going to catch the first command
*/

void child_work(char **argv, int identifier_child, char **envp)
{
	t_pipex pipex;
	if (identifier_child == 1) {
		dup2(pipex.pipefd[1], STDOUT_FILENO);
		close(pipex.pipefd[0]);
		dup2(pipex.fd_infile, STDIN_FILENO);
		pipex.cmd_args = ft_split(argv[2], ' '); //catch the first command
		pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
		error_cmd_args(pipex);
		execve(*pipex.cmd_paths, pipex.cmd_args, envp); //&argv[1]
	}
	else if (identifier_child == 2) {
		dup2(pipex.fd_outfile, STDOUT_FILENO);
		dup2(pipex.pipefd[0], STDIN_FILENO);
		close(pipex.pipefd[1]);
		pipex.cmd_args = ft_split(argv[3], ' '); //catch the second command
		pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
		error_cmd_args(pipex);
		execve(*pipex.cmd_paths, pipex.cmd_args, envp); //&argv[4] //envp is an array of pointers to environment variables
	}
}

void error_cmd_args(t_pipex pipex){
	if (!pipex.cmd_args){
		frees_process(pipex);
		printf("Failed, introduce a valid arg");
		exit(1);
	} else{
		write(2, "-bash: ", 7);
		write(2, pipex.cmd, ft_strlen(pipex.cmd));
		write(2, ": ", 2);
		write(2, ERR_ARGS, ft_strlen(ERR_ARGS));
	}
}
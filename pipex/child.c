/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:52:05 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/15 10:46:16 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char get_command(){
	
}


/*
** Redirects standard output of the first command to the standard input of second command
** First command should write the result on pipe, later the second command are going to search this data on pipe

** We are going to call fork function to make a copy to the parent process for avoid overwrite the process with execve
** execve executes the program that makes reference the pathname
** First child is goint to work with the first command that we receives for console.
** Later, should close our pipes in children process to avoid future problems
*/

void child_work(t_pipex pipex, char **argv, int identifier_child){
	if (identifier_child == 1) { //primer hijo
		dup2(pipex.fd_infile, STDIN_FILENO);
		dup2(pipex.pipefd[1], STDOUT_FILENO);
		close(pipex.pipefd[0]);
		pipex.cmd_args = ft_split(argv[2], ' '); //catch the first command
		pipex.cmd = get_command(pipex.cmd_args);
		error_cmd_args(pipex);
		execve(pipex.cmd_paths, argv[1], *envp);
	}
	else if (identifier_child == 2){
		dup2(pipex.fd_outfile, STDOUT_FILENO);
		dup2(pipex.pipefd[0], STDIN_FILENO);
		close(pipex.pipefd[1]);
		pipex.cmd_args = ft_split(argv[3], ' '); //catch the second command
		pipex.cmd = get_command(pipex.cmd_args);
		error_cmd_args(pipex);
		execve(pipex.cmd_paths, argv[4], *envp); //envp is an array of pointers to environment variables
	}
}

void error_cmd_args(t_pipex pipex){
	if (!pipex.cmd_args){
		free_child();
		printf("Failed, introduce a valid arg");
		exit(1);
	}
}
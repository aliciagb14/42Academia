/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:17:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 09:05:46 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	We are going to read file1 command1 command2 file2" that traduces like:
**	<file1 command1 | file2 command2>
*/

/*void	valgrind(void)
{
	system("leaks pipex");
}*/

int main(int argc, char **argv, char **envp)
{
	//atexit(valgrind);
	t_pipex pipe;
	//checkppath(env)
	error_number_args(argc, argv);
	pipe.path = envp_path(envp);
	pipe.position_path = 0;
	start_pipe(argc, argv, envp);
	return (0);
}

void error_number_args(int argc, char **argv){
	t_pipex pipe;
	if (argc != 5)
		msg_error(ERR_ARGS);
	pipe.fd_infile = open(argv[1], O_RDONLY);
	if (pipe.fd_infile < 0){
		msg_error(ERR_INFILE);
		close(pipe.fd_infile);
	}
	pipe.fd_outfile = open(argv[4], O_CREAT | O_WRONLY, 0666);
	if (pipe.fd_outfile < 0){
		msg_error(ERR_OUTFILE);
		close(pipe.fd_outfile);
	}
}


/*
static char	*only_path(char *cmd, char **env)
{
	int		i;
	char	**env_paths;
	char	*path;
	char	*path_cmd;

	i = check_path(env);
	env_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (env_paths[i])
	{
		path = ft_strjoin(env_paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		if (access(path_cmd, X_OK) == 0)
		{
			ft_free_matrix(env_paths);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	ft_free_matrix(env_paths);
	ft_print_error("command not found");
	return (EXIT_SUCCESS);
}
*/

int start_pipe(int argc, char **argv, char **envp) //=only path
{
	t_pipex pipe;
	int i;

	i = 0;
	pipe.path = envp_path(envp); //envp paths
	pipe.cmd_path = ft_split(pipe.path, ':'); //en vez de pipe.paths -> envp[i]+5//progress path
	pipe.pid_first_child = fork();
	if (pipe.pid_first_child == 0)
		child_work(argv, 1, envp, argc);
	pipe.pid_second_child = fork();
	if (pipe.pid_second_child == 0)
		child_work(argv, 2, envp, argc);
	//pipe.cmd = get_command(&pipe.cmd_path, pipe.cmd_args[0]);
	/*while(pipe.cmd_path[i])
	{
		pipe.path = ft_strjoin(&pipe.cmd_path[i], "/");
		pipe.cmd_path = ft_strjoin(pipe.path, pipe.cmd);
		if (access(pipe.cmd_path, X_OK) < 0){
			msg_error(ERR_X_OK);
			free(envp);
			return(pipe.cmd_path);
		}
		if (pipe.pid_second_child == 0)
			child_work(argv, 2, envp, argc);
		parent_work(pipe);
		free(pipe.cmd_args);
	}*/
	free(pipe.path);
	msg_error(ERR_CMMND);
	return (EXIT_SUCCESS);
}


void	ft_exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_command(&pipe.cmd_path, pipe.cmd_args[0]);
	if (execve(path, cmd, env) == -1)
		ft_perror("");
}

/*
 * Waitpid = Espera por el final de un proceso 
 * */

void parent_work(t_pipex pipe){
	if (pipe.pipefd < 0)
		msg_error(NULL);
		//llama a hijos
	close(pipe.pipefd[0]);
	close(pipe.pipefd[1]);
	waitpid(pipe.pid_first_child, &pipe.status, 0); //-1
	waitpid(pipe.pid_second_child, &pipe.status, 0); //-1
}

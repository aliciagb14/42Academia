/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:17:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/04 15:03:15 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	We are going to read file1 command1 command2 file2" that traduces like:
**	<file1 command1 | file2 command2>
*/

void	valgrind(void)
{
	system("leaks pipex");
}

/*static void init_cmd(t_pipex *pipex, int status){
	pipex->status = status;
	pipex->paths = 0;
	pipex->cmd = 0;
	pipex->cmd_args[0] = 0;
}*/

int main(int argc, char **argv, char **envp)
{
	//atexit(valgrind);
	char *path;
	msg_error(ERR_ARGS);
	path = envp_path(argc, envp);
    error_number_args(argc, argv);
	start_pipe(argc, argv, envp);
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

void start_pipe(int argc, char **argv, char **envp){
	t_pipex pipe;

	pipe.paths = envp_path(argc, envp);
	pipe.cmd_paths = ft_split(pipe.paths, ':');
	pipe.pid_first_child = fork();
	if (pipe.pid_first_child == 0)
		child_work(argv, 1, envp);
	pipe.pid_second_child = fork();
	if (pipe.pid_second_child == 0)
		child_work(argv, 2, envp);
	frees_process(pipe);
}


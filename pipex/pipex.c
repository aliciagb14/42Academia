/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:01:27 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 08:13:47 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	We are going to read file1 command1 command2 file2" that traduces like:
**	<file1 command1 | file2 command2>
*/

int main(int argc, char **argv, char **envp)
{
	char *string_aux1;
	char *path;
	t_pipex pipe;
	
	path = envp_path(argc, envp);
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
	start_pipe(argc, argv, envp);
}

void start_pipe(int argc, char **argv, char **envp){
	t_pipex pipe;
	int status;

	pipe.paths = envp_path(argc, envp);
	pipe.cmd_paths = ft_split(pipe.paths, ':');
	pipe.pid_first_child = fork();
	if (pipe.pid_first_child == 0)
		child_work(argc, argv, 1, envp);
	pipe.pid_second_child = fork();
	if (pipe.pid_second_child == 0)
		child_work(argc, argv, 2, envp);
	frees_process(pipe);
}


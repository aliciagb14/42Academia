/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:18:16 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 08:55:26 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INFILE "Cant open infile\n"
# define ERR_OUTFILE "Cant open outfile\n"
# define ERR_ARGS "Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"
# define ERR_CMMND "Command not found\n"
# define ERR_F_OK "File not exits\n"
# define ERR_X_OK "Cant access to the file for the execution\n"
# define ERR_PATH_UNDEFINED "The path is undefined in the environment"
# define ERR_W_OK "Permission denied\n"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid_first_child;
	pid_t	pid_second_child;
	int		pipefd[2];
	int		fd_infile;
	int		fd_outfile;
	char	*path;
	char	*cmd_path;
	char	**cmd_args;
	char	*cmd;
	int		position_path;
	int		status;
}t_pipex;

int		start_pipe(int argc, char **argv, char **envp);
void	error_number_args(int argc, char **argv);

void	error_cmd_args(t_pipex pipex, char **argv, int argc);
void	child_work(char **argv, int identifier_child, char **envp, int argc);
int		envp_path(char **envp);
char	*get_command(char **paths, char *cmd_args);

void	msg_error(char *error);
void	close_fd(t_pipex *tube);
void	frees_process(t_pipex pipex);

void	ft_exec(char *argv, char **env);
# endif
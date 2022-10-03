/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:18:16 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 14:19:38 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INFILE "Cant open infile"
# define ERR_OUTFILE "Cant open outfile"
# define ERR_ARGS "Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_pipex
{
	pid_t	pid_first_child;
	pid_t	pid_second_child;
	int		pipefd[2];
	int		fd_infile;
	int		fd_outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	msg_error(char *error);
void	close_fd(t_pipex *tube);
void	frees_process(t_pipex pipex);
void	parent_work(t_pipex tube);
void	start_pipe(int argc, char **argv, char **envp);
void	child_work(int argc, char **argv, int identifier_child, char **envp);
char	*envp_path(int argc, char **envp);
char	get_command(t_pipex *pipex, int argc, char **envp);

char	*ft_substr(char const *s, unsigned int start, size_t len);
//void	error_cmd_args(t_pipex pipex);
# endif
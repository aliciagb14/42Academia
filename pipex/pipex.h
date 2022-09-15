/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:18:16 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/15 13:10:48 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INFILE "Cant open infile"
# define ERR_OUTFILE "Cant open outfile"
# define ERR_ARGS "Invalid number of args"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_pipex
{
	pid_t	pid_first_child; //pid1
	pid_t	pid_second_child; //pid2
	int		pipefd[2];
	int		fd_infile;
	int		fd_outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	msg_error(char *error);

# endif
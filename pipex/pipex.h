/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:18:16 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/15 10:39:31 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"


# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdarg.h>
char *const envp[] = ;
typedef struct s_pipex
{
	pid_t	pid_infile;
	pid_t	pid_outfile;
	int		pipefd[2];
	int		fd_infile;
	int		fd_outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;


# endif
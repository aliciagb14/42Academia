/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:18:16 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/04 10:04:48 by agonzale         ###   ########.fr       */
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
# include "libft/libft.h"

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
void	child_work(char **argv, int identifier_child, char **envp);
char	*envp_path(int argc, char **envp);
char	*get_command(char **paths, char *cmd_args);

unsigned int	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
unsigned int	get_word_count(char *string, char delimiter);
unsigned int	word_length(char *string, unsigned int index, char delimiter);
char	*get_next_word(char *string, unsigned int *index, char delimiter, unsigned int *word_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	error_cmd_args(t_pipex pipex);
# endif
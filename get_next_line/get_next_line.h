/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 07:46:18 by agonzale          #+#    #+#             */
/*   Updated: 2020/01/30 11:47:53 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int			read_lines(char **line, char **s, int fd);
int			output(char **line, char **s, int ret, int fd);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strchr(char *str, int c);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 2442
#	endif

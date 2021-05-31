/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 07:35:08 by agonzale          #+#    #+#             */
/*   Updated: 2020/11/05 23:56:32 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 42

int		read_lines(char **line, char **s, int fd)
{
	int		len;
	char	*temp;

	len = 0;
	if (ft_strchr(s[fd], '\n'))
	{
		len = ft_strchr(s[fd], '\n') - s[fd];
		*line = ft_substr(s[fd], 0, len);
		temp = ft_strdup(&((s[fd])[len + 1]));
		free(s[fd]);
		s[fd] = temp;
	}
	else
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	return (1);
}

int		output(char **line, char **s, int fd)
{
	int		ret = 0;
	if (ret < 0)
	{
		free(s[fd]);
		return (-1);
	}
	else if (ret == 0 && !s[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (read_lines(line, s, fd));
}

int		get_next_line(int fd, char **line) //line es dir de puntero de char que guarda lo q tiene fd
{
	int				numbytes;
	char			*temp;
	static char		*s[4096];
	char			buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	while ((numbytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[numbytes] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return ((numbytes == -1) ? -1 : output(line, s, fd));
}

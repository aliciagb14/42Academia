/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:28:27 by agonzale          #+#    #+#             */
/*   Updated: 2020/01/28 11:40:55 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int		output(char **line, char **s, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !s[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (read_lines(line, s, fd));
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	int				numbytes;
	char			*temp;
	static char		*s[4096];
	char			buf[BUFFER_SIZE + 1];

	ret = 0;
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
	return ((numbytes == -1) ? -1 : output(line, s, ret, fd));
}

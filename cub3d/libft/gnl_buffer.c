/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:10 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 14:12:37 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			fill_gnl_buffer(t_gnl_buffer **buffer, char *line)
{
	t_gnl_buffer	*aux;

	if (!*buffer)
	{
		if (!(*buffer = ft_calloc(1, sizeof(t_gnl_buffer))))
			return (0);
		(*buffer)->line = line;
	}
	else
	{
		aux = *buffer;
		while (aux->next)
			aux = aux->next;
		if (!(aux->next = ft_calloc(1, sizeof(t_gnl_buffer))))
			return (0);
		aux->next->line = line;
	}
	return (1);
}

void		free_gnl_buffer(t_gnl_buffer *buffer, t_bool erase_mode)
{
	if (buffer)
	{
		if (erase_mode && buffer->line)
			free(buffer->line);
		if (buffer->next)
			free_gnl_buffer(buffer->next, erase_mode);
		free(buffer);
	}
}

int			gnl_buffer(int fd, int n, t_gnl_buffer **buffer)
{
	char	*line;
	int		continuous;
	int		i;

	if (n < 0)
		return (-1);
	continuous = n ? 0 : 1;
	while ((n > 0 || continuous) && (i = get_next_line(fd, &line)) >= 0)
	{
		if (!fill_gnl_buffer(buffer, line))
		{
			free_gnl_buffer(*buffer, 1);
			return (-1);
		}
		n--;
		if (i == 0)
			break ;
	}
	return (0);
}

/*
** WARNING: only use if close is allowed!
*/

void		end_get_next_line(int fd)
{
	char *line;

	close(fd);
	get_next_line(fd, &line);
}

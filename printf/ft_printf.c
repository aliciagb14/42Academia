/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:18:16 by agonzale          #+#    #+#             */
/*   Updated: 2020/11/04 23:59:44 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *line, ...)
{
	t_list	*l;
	int		cnt;

	if (!(l = malloc(sizeof(t_list))))
		return (-1);
	ft_initialize(l);
	va_start(l->args, line);
	while (line[l->pos])
	{
		if (line[l->pos] == '%')
		{
			l->pos++;
			ft_saver_flags(l, (char *)line);
			ft_specifier(l, line);
		}
		else
			ft_putchar(line[l->pos], l);
		l->pos++;
	}
	va_end(l->args);
	cnt = l->cnt;
	free(l);
	return (cnt);
}

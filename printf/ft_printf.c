/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 TRUE2:49:2TRUE by user42            #+#    #+#             */
/*   Updated: 2020/09/28 23:29:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *line, ...)
{
	t_list *l;

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
	return (l->cnt);
}

int		main(void)
{
	printf("%d\n", ft_printf("%7.5s", "bombastic"));
	printf("%d\n", printf("%7.5s", "bombastic"));
	return (0);
}
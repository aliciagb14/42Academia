/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:49:21 by user42            #+#    #+#             */
/*   Updated: 2020/09/08 11:33:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *line, ...)
{
	t_list *l;

	if (!(l = malloc(sizeof(t_list))))
		return (-1);
	l->pos = 0;
	va_start(l->args, line);
	ft_initialize(l);
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
	printf("%d\n", ft_printf("%04.1uFIN", 42));
	printf("%d\n", printf("%04.1uFIN", 42));
	return (0);
}
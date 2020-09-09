/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:38:19 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 20:29:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
	l->cnt++;
}

void ft_printer_char(t_list *l, const char *line)
{
	char next;
	next = (char)va_arg(l->args, int);

	if ((l->flags.minus == TRUE && l->flags.zero == TRUE) || l->flags.minus == TRUE)
	{
		ft_putchar(next, l);
		ft_printer_spaces(l, l->width - 1, line);
	}
	else if (l->flags.zero == TRUE)
	{
		ft_printer_spaces(l, l->width - 1, line);
		ft_putchar(next, l);
	}
	else //no funciona cuando es %4c o cosas así
	{
		ft_printer_spaces(l, l->width - 1, line);
		ft_putchar(next, l);
	}
	
}
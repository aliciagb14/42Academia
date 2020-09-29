/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:38:19 by user42            #+#    #+#             */
/*   Updated: 2020/09/29 18:46:04 by user42           ###   ########.fr       */
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
	char c;

	c = va_arg(l->args, int);
	if ((l->flags.zero == 1 && l->precision < 0) || 
		(l->width > 0 && l->flags.minus == FALSE))
	{
		ft_printer_spaces(l, l->width - 1, line);
		ft_putchar(c, l);
	}
	else if (l->flags.minus == 1)
	{
		ft_putchar(c, l);
		ft_printer_spaces(l, l->width - 1, line);
	}
	else
		ft_putchar(c, l);
}

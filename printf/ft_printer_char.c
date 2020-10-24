/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:15:17 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/24 12:24:29 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
	l->cnt++;
}

void	ft_printer_char(t_list *l)
{
	char c;

	c = va_arg(l->args, int);
	if ((l->flags.zero == 1 && l->precision < 0) ||
		(l->width > 0 && l->flags.minus == FALSE))
	{
		ft_printer_spaces(l, l->width - 1);
		ft_putchar(c, l);
	}
	else if (l->flags.minus == TRUE)
	{
		ft_putchar(c, l);
		ft_printer_spaces(l, l->width - 1);
	}
	else
		ft_putchar(c, l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:46:54 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 13:03:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_zero(t_list *l, int number, int size)
{
	while (size > 0)
	{
		ft_putchar('0', l);
		size--;
	}
}

void ft_printer_spaces(t_list *l, int size, const char *line)
{
	while (size > 0)
	{
		ft_putchar(' ', l);
		size--;
	}
}

void ft_printer_minus(t_list *l, int number)
{
	if (number < 0)
		ft_putchar('-', l);
}

void ft_printer_character(t_list *l, char *str)
{
	while (*str)
	{
		ft_putchar(*str, l);
		str++;
	}
}

void	ft_putnbr(t_list *l, int number)
{
	if (number < 0)
		number = -number;
	if (number > 9)
	{
		ft_putnbr(l, number / 10);
		ft_putchar(number % 10 + 48, l);
	}
	else
		ft_putchar(number + 48, l);
}
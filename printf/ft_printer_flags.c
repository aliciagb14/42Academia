/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:17:52 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/24 12:22:50 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_zero(t_list *l, int size)
{
	while (size > 0)
	{
		ft_putchar('0', l);
		size--;
	}
}

void	ft_printer_spaces(t_list *l, int size)
{
	while (size > 0)
	{
		ft_putchar(' ', l);
		size--;
	}
}

void	ft_printer_minus(t_list *l, int number)
{
	if (number < 0)
		ft_putchar('-', l);
}

void	ft_printer_character(t_list *l, char *str)
{
	while (*str)
	{
		ft_putchar(*str, l);
		str++;
	}
}

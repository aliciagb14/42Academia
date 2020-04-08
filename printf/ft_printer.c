/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 13:41:35 by agonzale          #+#    #+#             */
/*   Updated: 2020/04/08 11:14:38 by agonzale         ###   ########.fr       */
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

void ft_printer_spaces(t_list *l, int number, int size)
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

void ft_printer_character(t_list *l, const char *line)	{
	while (line[l->pos])	{
		ft_putchar(line[l->pos], l);
		l->pos++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:28:46 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/05 08:32:06 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int number, t_list *l)
{
	if (number < 0)
	{
		number = -number;
		ft_putchar('-', l);
	}
	if (number > 9)
	{
		ft_putnbr(number / 10, l);
		ft_putchar(number % 10 + 48, l);
	}
	else
		ft_putchar(number + 48, l);
}

void	ft_case_d(t_list *l)
{
	int number;

	number = va_arg(l->args, int);
	ft_putnbr(number, l);
}

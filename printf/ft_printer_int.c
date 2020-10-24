/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:16:05 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/24 12:51:12 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_case_width(t_list *l, int number)
{
	if (l->flags.minus == TRUE)
	{
		if (l->flags.point == TRUE && l->width >= l->precision && number == 0)
			ft_printer_spaces(l, l->width);
		else
		{
			ft_printer_minus(l, number);
			ft_putnbr(l, number);
			ft_printer_spaces(l, l->width - l->len);
		}
	}
	else if (l->flags.zero == TRUE)
	{
		if (number < 0)
			ft_printer_minus(l, number);
		ft_printer_zero(l, l->width - l->len);
		ft_putnbr(l, number);
	}
	else if (l->flags.minus == FALSE)
		ft_case_minus_width(l, number);
}

void	ft_case_minus_width(t_list *l, int number)
{
	if (l->flags.point == TRUE && l->width >= l->precision && number == 0)
	{
		if (l->precision < 0)
			ft_printer_zero(l, l->len);
		else
			ft_printer_spaces(l, l->width);
	}
	else
	{
		ft_printer_spaces(l, l->width - l->len);
		ft_printer_minus(l, number);
		ft_putnbr(l, number);
	}
}

void	ft_case_width_prec(t_list *l, int number)
{
	if (l->width <= l->precision && l->flags.minus == TRUE)
	{
		if (number > 0 || l->width > l->len)
			ft_printer_zero(l, l->precision - l->len);
		else
		{
			ft_printer_minus(l, number);
			ft_printer_zero(l, l->precision - l->len + 1);
		}
	}
	else
	{
		if (l->width > l->precision)
			ft_case_width_prec_aux(l, number);
		else
		{
			if (number < 0)
			{
				ft_printer_minus(l, number);
				l->len--;
			}
			ft_printer_zero(l, l->precision - l->len);
		}
	}
	ft_putnbr(l, number);
}

void	ft_case_width_prec_minus(t_list *l, int number)
{
	ft_printer_minus(l, number);
	if (number < 0)
	{
		ft_printer_zero(l, l->precision - l->len + 1);
		ft_putnbr(l, number);
		if (l->precision > l->len)
			ft_printer_spaces(l, l->precision - 1);
		else
			ft_printer_spaces(l, l->precision);
	}
	else
	{
		ft_printer_zero(l, l->precision - l->len);
		ft_putnbr(l, number);
		if (l->precision > l->len)
			ft_printer_spaces(l, l->width - l->precision);
		else
			ft_printer_spaces(l, l->width - l->len);
	}
}

void	ft_case_width_prec_aux(t_list *l, int number)
{
	if (number < 0)
	{
		if (l->precision < l->len)
			ft_printer_spaces(l, l->precision);
		else
			ft_printer_spaces(l, l->len);
		ft_printer_minus(l, number);
		ft_printer_zero(l, l->precision - l->len + 1);
	}
	else
	{
		if (l->precision > l->len)
			ft_printer_spaces(l, l->width - l->precision);
		else
			ft_printer_spaces(l, l->width - l->len);
		ft_printer_minus(l, number);
		ft_printer_zero(l, l->precision - l->len);
	}
}

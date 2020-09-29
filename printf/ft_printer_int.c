/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:48:03 by user42            #+#    #+#             */
/*   Updated: 2020/09/29 18:46:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_int(t_list *l, const char *line)
{
	int number;
	int size;
	number = va_arg(l->args, int);
	l->len = ft_get_size_num(l, number);
	if (l->flags.minus == 1 && l->flags.zero == 1)
		ft_case_zero_width(l, line, number);
	else if (l->width >= 0 && l->precision == FALSE && l->flags.zero == FALSE)
		ft_case_width(l, line, number);
	else if (l->width >= 0 && l->precision == FALSE && l->flags.zero == 1)
		ft_case_zero_width(l, line, number);
	else if (l->precision >= 0 && l->width >= 0 && l->flags.zero == 1)
		ft_case_zero_width_prec(l, line, number);
	else if (l->precision >= 0 && l->width >= 0)
		ft_case_width_prec(l, line, number);
}

void ft_case_width(t_list *l, const char *line, int number)
{
	if (l->flags.minus == 1)
	{
		ft_printer_minus(l, number);
		ft_putnbr(l, number);
		ft_printer_spaces(l, l->width - l->len, line);
	}
	else
	{
		ft_printer_spaces(l, l->width - l->len, line);
		ft_printer_minus(l, number);
		ft_putnbr(l, number);
	}
}

void ft_case_zero_width(t_list *l, const char *line, int number)
{
	if (l->flags.minus == 1 && l->flags.zero == 1)
		ft_putnbr(l, number);
	else
	{
		ft_printer_minus(l, number);
		ft_printer_zero(l, number, l->width - l->len);
		ft_putnbr(l, number);	
	}
}

void ft_case_width_prec(t_list *l, const char *line, int number)	
{
	if (l->flags.minus == 1)	{
		if (l->width > l->precision)
		{
			ft_printer_minus(l, number);
			ft_printer_zero(l, number, l->precision - l-> len + 1);
			ft_putnbr(l, number);
			ft_printer_spaces(l, l->width - l->precision - 1, line);
		}
		else if (l->width <= l->precision && (l->precision > l->len || l->width <= l->len))
		{
			ft_printer_zero(l, number, l->precision - l->width);
			ft_putnbr(l, number);
		}
		else if (l->precision <= l->len)
			ft_putnbr(l, number);
	}
	else
	{
		if (l->width > l->precision)
		{
			ft_printer_spaces(l, l->precision + l->len - l->width, line);
			ft_printer_minus(l, number);
			ft_printer_zero(l, number, l->precision - l->len + 1);
			ft_putnbr(l, number);
		}
		else if (l->width <= l->precision && l->precision > l->len)
		{
			ft_printer_zero(l, number, l->width);
			ft_putnbr(l, number);
		}
	}
}

void ft_case_zero_width_prec(t_list *l, const char *line, int number)	
{
	if (l->flags.minus == 1)
	{
		if (l->width > l->precision && l->precision > l->len)
		{
			ft_printer_zero(l, number, l->width - l->precision);
			ft_putnbr(l, number);
			ft_printer_spaces(l, l->precision - l->len, line);
		}
		else if (l->width > l->precision && l->len >= l->precision)
		{
			ft_putnbr(l, number);
			ft_printer_spaces(l, l->width - l->len, line);
		}
	}
	else
	{
		if (l->width > l->precision)
		{
			ft_printer_spaces(l, l->width - l->len, line);
			ft_printer_minus(l, number);
			ft_putnbr(l, number);
		}	
	}
}
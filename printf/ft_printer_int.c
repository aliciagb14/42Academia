/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:45:11 by agonzale          #+#    #+#             */
/*   Updated: 2020/04/08 12:47:49 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_int(t_list *l, const char *line)
{
	int number;
	int size;
	number = va_arg(l->args, int);
	l->len = ft_get_size_num(l, number);
	if (l->flags.minus == TRUE && l->flags.zero == TRUE)
		ft_case_zero_width(l, line, number, size);
	else if (l->width >= 0 && l->precision == FALSE && l->flags.zero == FALSE)
		ft_case_width(l, line, number, size);
	else if (l->width >= 0 && l->precision == FALSE && l->flags.zero == TRUE)
		ft_case_zero_width(l, line, number, size);
	else if (l->precision >= 0 && l->width >= 0 && l->flags.zero == TRUE)
		ft_case_zero_width_prec(l, line, number, size);
	else if (l->precision >= 0 && l->width >= 0)
		ft_case_width_prec(l, line, number, size);
}

void ft_case_width(t_list *l, const char *line, int number, int size)
{
	if (l->flags.minus == TRUE)
	{
		ft_printer_minus(l, number);
		ft_putnbr(l, number);
		ft_printer_spaces(l, number, l->width - l->len);
	}
	else
	{
		ft_printer_spaces(l, number, l->width - l->len);
		ft_printer_minus(l, number);
		ft_putnbr(l, number);
	}
}

void ft_case_zero_width(t_list *l, const char *line, int number, int size)
{
	if (l->flags.minus == TRUE && l->flags.zero == TRUE)
		ft_putnbr(l, number);
	else
	{
		ft_printer_minus(l, number);
		ft_printer_zero(l, number, l->width - l->len);
		ft_putnbr(l, number);	
	}
}

void ft_case_width_prec(t_list *l, const char *line, int number, int size)	
{
	if (l->flags.minus == TRUE)	{
		if (l->width > l->precision)
		{
			ft_printer_minus(l, number);
			ft_printer_zero(l, number, l->precision - l-> len + 1);
			ft_putnbr(l, number);
			ft_printer_spaces(l, number, l->width - l->precision - 1);
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
			ft_printer_spaces(l, number, l->precision + l->len - l->width);
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

void ft_case_zero_width_prec(t_list *l, const char *line, int number, int size)	
{
	if (l->flags.minus == TRUE)
	{
		if (l->width > l->precision && l->precision > l->len)
		{
			ft_printer_zero(l, number, l->width - l->precision);
			ft_putnbr(l, number);
			ft_printer_spaces(l, number, l->precision - l->len);
		}
		else if (l->width > l->precision && l->len >= l->precision)
		{
			ft_putnbr(l, number);
			ft_printer_spaces(l, number, l->width - l->len);
		}
	}
	else
	{
		if (l->width > l->precision)
		{
			ft_printer_spaces(l, number, l->width - l->len);
			ft_printer_minus(l, number);
			ft_putnbr(l, number);
		}	
	}
}
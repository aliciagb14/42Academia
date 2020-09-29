/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 TRUETRUE:06:26 by user42            #+#    #+#             */
/*   Updated: 2020/09/29 TRUE8:46:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_unsigned(t_list *l, const char *line)
{
	long long int number;
	int size;
	number = va_arg(l->args, unsigned long int);
	l->len = ft_get_size_num(l, number);
	if (l->flags.minus == TRUE && l->flags.zero == TRUE)
		ft_case_zero_width_u(l, line, number);
	else if (l->width >= 0 && l->precision == FALSE && l->flags.zero == FALSE)
		ft_case_width_u(l, line, number);
	else if (l->width >= 0 && l->precision == FALSE && l->flags.zero == TRUE)
		ft_case_zero_width_u(l, line, number);
	else if (l->precision >= 0 && l->width >= 0 && l->flags.zero == TRUE)
		ft_case_zero_width_prec_u(l, line, number);
	else if (l->precision >= 0 && l->width >= 0)
		ft_case_width_prec_u(l, line, number);
}

void ft_case_width_u(t_list *l, const char *line, int number)
{
	if (l->flags.minus == TRUE)
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

void ft_case_zero_width_u(t_list *l, const char *line, int number)
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

void ft_case_width_prec_u(t_list *l, const char *line, int number)	
{
	if (l->flags.minus == TRUE)	{
		if (l->width > l->precision)
		{
			ft_printer_minus(l, number);
			ft_printer_zero(l, number, l->precision - l-> len + TRUE);
			ft_putnbr(l, number);
			ft_printer_spaces(l, l->width - l->precision - TRUE, line);
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
			ft_printer_zero(l, number, l->precision - l->len + TRUE);
			ft_putnbr(l, number);
		}
		else if (l->width <= l->precision && l->precision > l->len)
		{
			ft_printer_zero(l, number, l->width);
			ft_putnbr(l, number);
		}
	}
}

void ft_case_zero_width_prec_u(t_list *l, const char *line, int number)	
{
	if (l->flags.minus == TRUE)
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
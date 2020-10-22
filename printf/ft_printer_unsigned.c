/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:17:38 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/22 20:13:06 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_unsigned(t_list *l, const char *line)
{
	long long int number;
	int size;
	number = va_arg(l->args, unsigned int);
	l->len = ft_get_size_num(l, number);
	if (l->flags.minus == TRUE && l->flags.zero == TRUE)
		ft_case_zero_width_u(l, line, number);
	else if (l->width >= 0 && l->precision <= 0)
		ft_case_width_u(l, line, number);
	else if (l->precision > 0 && l->width >= 0)
		ft_case_width_prec_u(l, line, number);
}

void ft_case_width_u(t_list *l, const char *line, int number)
{
	if (l->flags.minus == TRUE)
	{
		if (l->flags.point == TRUE && l->width >= l->precision && number == 0)
			ft_printer_spaces(l, l->width, line);
		else
		{
			ft_printer_minus(l, number);
			ft_putnbr_u(l, number);
			ft_printer_spaces(l, l->width - l->len, line);
		}
		
	}
	else if (l->flags.zero == TRUE)
	{
		if (number < 0)
			ft_printer_minus(l, number);
		ft_printer_zero(l, number, l->width - l->len);
		ft_putnbr_u(l, number);
	}
	else if (l->flags.minus == FALSE)
	{
		if (l->flags.point == TRUE && l->width >= l->precision && number == 0)
		{
			if (l->precision < 0)
				ft_printer_zero(l, number, l->len);
			else
				ft_printer_spaces(l, l->width, line);
		}
		else
		{
			ft_printer_spaces(l, l->width - l->len, line);
			ft_printer_minus(l, number);
			ft_putnbr_u(l, number);	
		}
	}
}

void ft_case_zero_width_u(t_list *l, const char *line, int number)
{
	if (l->flags.minus == TRUE)
	{
		if (number < 0)
		{
			ft_printer_minus(l, number);
			ft_printer_zero(l, number, l->precision - l->len + 1);
			ft_putnbr_u(l, number);
			if (l->precision > l->len)
				ft_printer_spaces(l, l->width - l->precision - 1, line);
			else if (l->width > l->len && l->precision < l->len)
				ft_printer_spaces(l, l->precision, line);
		}
		else
		{
			ft_printer_zero(l, number, l->precision - l->len);
			ft_putnbr_u(l, number);
			if (l->precision > l->len)
				ft_printer_spaces(l, l->width - l->precision, line);
			else
				ft_printer_spaces(l, l->width - l->len, line);
		}
	}
	else if (l->flags.minus == FALSE)
	{
		if (number < 0)
		{
			if (l->precision > l->len)
				ft_printer_spaces(l, l->width - l->precision - 1, line);
			else
				ft_printer_spaces(l, l->width - l->len, line);
			ft_printer_minus(l, number);
			l->len--;
		}
		else
		{
			if (l->precision > l->len)
				ft_printer_spaces(l, l->width - l->precision, line);
			else
				ft_printer_spaces(l, l->width - l->len, line);
		}
		ft_printer_zero(l, number, l->precision - l->len);
		ft_putnbr_u(l, number);	
	}
}

void ft_case_width_prec_u(t_list *l, const char *line, int number)	
{
	if (l->flags.minus == TRUE)	
	{
		if (l->width > l->precision)
		{
			ft_printer_minus(l, number);
			if (number < 0)
			{
				ft_printer_zero(l, number, l->precision - l-> len + 1);
				ft_putnbr_u(l, number);
				if (l->precision > l->len)
					ft_printer_spaces(l, l->precision - 1, line);
				else
					ft_printer_spaces(l, l->precision, line);
			}
			else
			{
				ft_printer_zero(l, number, l->precision - l-> len);
				ft_putnbr_u(l, number);
				if (l->precision > l->len)
					ft_printer_spaces(l, l->width - l->precision, line);
				else
					ft_printer_spaces(l, l->width - l->len, line);
			}
		}
		else if (l->width <= l->precision)
		{
			if (number > 0 || l->width > l->len)
				ft_printer_zero(l, number, l->precision - l->len);
			else
			{
				ft_printer_minus(l, number);
				ft_printer_zero(l, number, l->precision - l-> len + 1);
			}
			ft_putnbr_u(l, number);
		}
	}
	else
	{
		if (l->width > l->precision)
		{
			if (number < 0)
			{
				if (l->precision < l->len)
					ft_printer_spaces(l, l->precision, line);
				else
					ft_printer_spaces(l, l->len, line);
				ft_printer_minus(l, number);
				ft_printer_zero(l, number, l->precision - l->len + 1);
			}
			else
			{
				if (l->precision > l->len)
					ft_printer_spaces(l, l->width - l->precision, line);
				else
					ft_printer_spaces(l, l->width - l->len, line);
				ft_printer_minus(l, number);
				ft_printer_zero(l, number, l->precision - l->len);
			}
			ft_putnbr_u(l, number);	
		}
		else
		{
			if (number < 0)
			{
				ft_printer_minus(l, number);
				l->len--;
			}
			ft_printer_zero(l, number, l->precision - l->len);
			ft_putnbr_u(l, number);
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
			ft_putnbr_u(l, number);
			ft_printer_spaces(l, l->precision - l->len, line);
		}
		else if (l->width > l->precision && l->len >= l->precision)
		{
			ft_putnbr_u(l, number);
			ft_printer_spaces(l, l->width - l->len, line);
		}
	}
	else
	{
		if (l->width > l->precision)
		{
			ft_printer_spaces(l, l->width - l->len, line);
			ft_printer_minus(l, number);
			ft_putnbr_u(l, number);
		}	
	}
}
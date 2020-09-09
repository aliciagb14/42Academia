/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:40:53 by user42            #+#    #+#             */
/*   Updated: 2020/08/24 10:21:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_string(t_list *l, const char *line)
{
	int size;
	char *str;

	str = (char *)va_arg(l->args, long int);
	if (l->flags.zero == TRUE || l->flags.minus == TRUE)
		ft_case_zero_s(l, line, str, size);
	else if (l->flags.zero == TRUE && l->flags.minus == TRUE)
		ft_case_zero_s(l, line, str, size);
	else if (l->flags.zero == FALSE && l->width > 0)
		ft_case_width_s(l, line, str, size);
}

void ft_case_zero_s(t_list *l, const char *line, char *str, int size)
{
	if (l->flags.zero == TRUE && l->flags.minus == FALSE)
	{
		if (l->width > 0)
			ft_printer_spaces(l, l->precision - 1, line);
	 	while (str[l->len] && l->len < l->precision)
		{
			ft_putchar((char)str[l->len], l);
			l->len++;
		}
	}
	else if (l->flags.minus == TRUE)
	{
		while (str[l->len] && l->len != l->precision)
		{
			ft_putchar((char)str[l->len], l);
			l->len++;
		}
		ft_printer_spaces(l, l->width - l->len, line);
	}
}

void ft_case_width_s(t_list *l, const char *line, char *str, int size)
{
	if (l->flags.minus == TRUE && l->precision < 0)
	{
		while (str[l->len])
		{
			ft_putchar((char)str[l->len], l);
			l->len++;
		}
		ft_printer_spaces(l, l->width - l->len, line);
	}
	else if (l->flags.minus == FALSE)
	{
		l->len = ft_strlen(l, str);
		if (l->precision > 0)
			ft_printer_spaces(l, l->width - l->precision, line);
		else
			ft_printer_spaces(l, l->width - l->len, line);
		l->len = 0;
		ft_aux_case_width_s(l, line, str);
	}
}

void ft_aux_case_width_s(t_list *l, const char *line, char *str)
{
	if (l->precision > 0)
	{
		l->len = 0;
		while (str[l->len] && l->len != l->precision)
		{
			ft_putchar((char)str[l->len], l);
			l->len++;
		}
	}
	else
	{
		while (str[l->len])
		{
			ft_putchar((char)str[l->len], l);
			l->len++;
		}
	}
}
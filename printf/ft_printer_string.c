/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:17:26 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/21 17:25:49 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_string(t_list *l, const char *line)
{
	char *str;

	str = (char *)va_arg(l->args, long int);
	if (str != NULL)
	{
		l->len = ft_strlen(l, str);
		if (l->width == 0 && l->precision != 0)
			ncharacter_according_prec(l, str);
		else if (l->width >= 0 && l->precision <= 0)
			ft_case_width_s(l, line, str);
		else if (l->width > 0 && l->precision > 0)
			ft_case_width_prec_s(l, line, str);
	}
	else
	{
		l->len += 6;
		if (l->flags.minus == TRUE)
		{
			l->cnt += 6;
			if (l->flags.point == TRUE && l->precision < l->len)//l->precision < l->width && l->precision < l->len
				ft_printer_spaces(l, l->width, line);
			else
			{
				write(1, "(null)", 6);
				ft_printer_spaces(l, l->width - l->len, line);
			}
		}
		else if (l->flags.minus == FALSE)
		{
			if (l->flags.point == TRUE && l->precision < l->len)
				ft_printer_spaces(l, l->width, line);
			else
			{
				ft_printer_spaces(l, l->width - l->len, line);
				write(1, "(null)", 6);
			}
		}
		str = NULL;
	}
}

void ft_case_width_prec_s(t_list *l, const char *line, char *str)
{
	if (l->flags.minus == FALSE && l->flags.zero == FALSE)
	{
		if (l->width < l->len || l->precision < l->len)
		{
			ft_printer_spaces(l, l->width - l->precision, line);
			ncharacter_according_prec(l, str);
		}
		else if (l->width > l->len || l->precision > l->len)
		{
			ft_printer_spaces(l, l->width - l->len, line);
			ft_printer_character(l, str);
		}
	}
	else if (l->flags.minus == TRUE)
	{
		if (l->precision > l->len)
		{
			ft_printer_character(l, str);
			ft_printer_spaces(l, l->width - l->len, line);
		}
		else if(l->precision <= l->len)
		{
			ncharacter_according_prec(l, str);
			ft_printer_spaces(l, l->width - l->len, line);
		}
	}
}

void ft_case_width_s(t_list *l, const char *line, char *str)
{
	if (l->flags.minus == FALSE)
	{
		if (l->precision < l->len && l->width != 0)
		{
			if (l->width > l->len)
			{
				ft_printer_spaces(l, l->width - l->len, line);
				ft_printer_character(l, str);
			}
			else
				ft_printer_character(l, str);
		}
		else
		{
			if (l->width >= 0 && l->flags.point == FALSE)
			{
				ft_printer_spaces(l, l->width - l->len, line);
				ft_printer_character(l, str);
			}
		}
	}
	else if (l->flags.minus == TRUE)
	{
		if (l->precision < l->len && l->width < l->len)
		{
			ft_printer_spaces(l, l->width - l->len, line);
			ft_printer_character(l,str);
		}
		else
		{
			ft_printer_character(l, str);
			ft_printer_spaces(l, l->width - l->len, line);
		}
	}
}

char *ncharacter_according_prec(t_list *l, char *str)
{
	int i;
	
	i = 0;
	l->len = 0;
	while (*str && l->precision != 0)
	{
		ft_putchar(*str, l);
		str++;
		l->precision--;
		l->len++;
	}
	return (&str[i]);
}

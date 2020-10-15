/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 TRUE2:40:53 by user42            #+#    #+#             */
/*   Updated: 2020/09/28 23:33:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_string(t_list *l, const char *line)
{
	char *str;

	str = (char *)va_arg(l->args, long int);
	l->len = ft_strlen(l, str);
	if (str != NULL)
	{
		if (l->width <= 0 && l->flags.minus == FALSE)
		{
			if (l->precision <= 0 ||  l->precision >= l->len)
				ft_printer_character(l, str);
			else if (l->precision < l->len)
				ncharacter_according_prec(l, str);
		}
		else if (l->width > 0 && l->precision <= 0)
			ft_case_width_s(l, line, str);
		else if (l->width > 0 && l->precision > 0)
			ft_case_width_prec_s(l, line, str);
	}
	else
	{
		write(1, "(null)", 6);
		l->cnt += 6;
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
		ft_printer_spaces(l, l->width - l->len, line);
		ft_printer_character(l, str);
	}
	else if (l->flags.minus == TRUE)
	{
		ft_printer_character(l, str);
		ft_printer_spaces(l, l->width - l->len, line);
	}
}

char *ncharacter_according_prec(t_list *l, char *str)
{
	int i;
	
	i = 0;
	while (*str && l->precision != 0)
	{
		ft_putchar(*str, l);
		str++;
		l->precision--;
	}
	l->len = ft_strlen(l, str);
	return (&str[i]);
}

char	*ft_strdup(t_list *l, char *s1)
{
	char	*s2;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(l, s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return ((char*)s2);
}

/*
void ft_printer_string(t_list *l, const char *line)
{
	char *str;

	str = (char *)va_arg(l->args, long int);
	if (l->width < 0 && l->precision < 0 && l->flags.minus == FALSE)
	{
		while (str[l->len])
		{
			ft_putchar((char)str[l->len], l);
			l->len++;
		}
	}
	else if (l->flags.zero == TRUE || l->flags.minus == TRUE)
		ft_case_zero_s(l, line, str);
	else if (l->flags.zero == TRUE && l->flags.minus == TRUE)
		ft_case_zero_s(l, line, str);
	else if (l->flags.zero == FALSE && l->width > 0)
		ft_case_width_s(l, line, str);
}

void ft_case_zero_s(t_list *l, const char *line, char *str)
{
	if (l->flags.zero == TRUE && l->flags.minus == FALSE)
	{
		ft_printer_spaces(l, l->precision - TRUE, line);
	 	ft_printer_character(l, str);
	}
	else if (l->flags.minus == TRUE)
	{
		ft_printer_character(l, str);
		ft_printer_spaces(l, l->width - l->len, line);
	}
}

void ft_case_width_s(t_list *l, const char *line, char *str)
{
	if (l->flags.minus == TRUE && l->precision < 0)
	{
		ft_printer_character(l, str);
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
		ft_printer_character(l, str);
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
*/
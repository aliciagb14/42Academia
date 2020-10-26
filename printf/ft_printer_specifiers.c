/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:20:02 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/26 01:19:13 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_string(t_list *l)
{
	char *str;

	str = (char *)va_arg(l->args, char *);
	if (str != NULL)
	{
		l->len = ft_strlen(str);
		if (l->width == 0 && l->precision != 0)
			ncharacter_according_prec(l, str);
		else if (l->width >= 0 && l->precision <= 0)
			ft_case_width_s(l, str);
		else if (l->width > 0 && l->precision > 0)
			ft_case_width_prec_s(l, str);
	}
	else
	{
		l->len += 6;
		if (l->flags.minus == TRUE)
			ft_case_minus_null_s(l);
		else if (l->flags.minus == FALSE)
			ft_case_no_minus_null(l);
		str = NULL;
	}
}

void	ft_printer_int(t_list *l)
{
	int		number;

	number = va_arg(l->args, int);
	l->len = ft_get_size_num(l, number);
	if (l->width >= 0 && l->precision <= 0)
		ft_case_width(l, number);
	else if (l->precision > 0 && l->width >= 0)
	{
		if (l->width > l->precision && l->flags.minus == TRUE)
			ft_case_width_prec_minus(l, number);
		else
			ft_case_width_prec(l, number);
	}
}

void	ft_printer_unsigned(t_list *l)
{
	unsigned int	number;

	number = va_arg(l->args, unsigned int);
	l->len = ft_get_size_num(l, number);
	if (l->width >= 0 && l->precision <= 0)
		ft_case_width_u(l, number);
	else if (l->precision > 0 && l->width >= 0)
	{
		if (l->width > l->precision && l->flags.minus == TRUE)
			ft_case_width_prec_minus_u(l, number);
		else
			ft_case_width_prec_u(l, number);
	}
}

void	ft_printer_hexa(t_list *l, const char *line)
{
	long int	number;
	char		*str;

	number = va_arg(l->args, unsigned int);
	str = ft_trans_hex(number, line[l->pos]);
	l->len = ft_strlen(str);
	if (l->flags.minus == TRUE || (l->width > 0 && l->precision > 0))
		ft_case_width_prec_x(l, str, number);
	else if (l->flags.zero == TRUE ||
		(l->width >= 0 && l->flags.minus == FALSE))
		ft_case_width_x(l, str, number);
	free(str);
}

void	ft_printer_hexap(t_list *l)
{
	unsigned long int	number;
	char				*str;

	number = (unsigned long)va_arg(l->args, void *);
	str = ft_trans_hexp(number);
	l->len = ft_strlen(str);
	if (number == 0)
	{
		l->len += 2;
		if (l->flags.point == TRUE)
			ft_case_printer_hexap_aux(l, str);
		else
		{
			if (l->width > 0)
				ft_printer_spaces(l, l->width - l->len);
			ft_printer_character(l, "0x0");
		}
	}
	else if (l->width >= 0 || l->precision >= 0)
		ft_case_width_hexap(l, str);
	free(str);
}

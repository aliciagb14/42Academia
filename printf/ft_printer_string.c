/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:17:26 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/26 01:15:52 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_case_minus_null_s(t_list *l, char *str)
{
	if (l->flags.point == TRUE && l->precision <= l->len)
	{
		if (l->precision != 0 && l->width > 0)
		{
			ncharacter_according_prec(l, "(null");
			ft_printer_spaces(l, l->width - 1);
		}
		else
			ft_printer_spaces(l, l->width);
	}
	else
	{
		l->cnt += 6;
		write(1, "(null)", 6);
		ft_printer_spaces(l, l->width - l->len);
	}
}

void ft_case_no_minus_null(t_list *l, char *str)
{
	if (l->flags.point == TRUE && l->precision < l->len && l->precision >= 0)
	{
		if (l->width >= 0 && l->len > l->precision)
		{
			ft_printer_spaces(l, l->width - l->precision);
			ncharacter_according_prec(l, "(null)");
		}
		else
			ft_printer_spaces(l, l->width);
	}
	else
	{
		l->cnt += 6;
		ft_printer_spaces(l, l->width - l->len);
		write(1, "(null)", 6);
	}
}

void	ft_case_width_prec_s(t_list *l, char *str)
{
	if (l->flags.minus == FALSE && l->flags.zero == FALSE)
	{
		if (l->width < l->len || l->precision < l->len)
		{
			ft_printer_spaces(l, l->width - l->precision);
			ncharacter_according_prec(l, str);
		}
		else
		{
			ft_printer_spaces(l, l->width - l->len);
			ft_printer_character(l, str);
		}
	}
	else if (l->flags.minus == TRUE)
	{
		if (l->precision > l->len)
			ft_printer_character(l, str);
		else
			ncharacter_according_prec(l, str);
		ft_printer_spaces(l, l->width - l->len);
	}
}

void	ft_case_width_s(t_list *l, char *str)
{
	//if (l->precision < l->len && l->width != 0)
	//{
		if (l->flags.point == FALSE)
		{
			if (l->flags.minus == TRUE)
			{
				ft_printer_character(l, str);
				ft_printer_spaces(l, l->width - l->len);
			}
			else if (l->flags.zero == TRUE)
			{
				ft_printer_zero(l, l->width - l->len);
				ft_printer_character(l, str);
			}
			else
			{
				ft_printer_spaces(l, l->width - l->len);
				ft_printer_character(l, str);
			}
		}
		else if (l->flags.ast == TRUE)
		{
			if ((l->precision != 0 || l->width != 0) && l->precision > 0)
			{
				ft_printer_character(l, str);
				ft_printer_spaces(l, l->width - l->len);
			}
			if (l->precision < 0)
			{
				ft_printer_character(l, str);
				ft_printer_spaces(l, l->width - l->len);
			}
		}
		else if (l->flags.point == TRUE && l->flags.ast == FALSE)
			ft_printer_spaces(l, l->width);
	//}
	/*else
	{
		if (l->width >= 0 && l->flags.point == FALSE)
		{
			if (l->flags.minus == TRUE)
			{
				ft_printer_character(l, str);
				ft_printer_spaces(l, l->width - l->len);
			}
			else
			{
				ft_printer_spaces(l, l->width - l->len);
				ft_printer_character(l, str);
			}
		}
		else if (l->flags.ast == TRUE && (l->precision != 0 || l->width != 0))
		{
			ft_printer_character(l, str);
			ft_printer_spaces(l, l->width - l->len);
		}
		else if ((l->width > 0 && l->precision != 0) ||
			(l->width > 0 && l->precision == 0 && l->flags.ast == FALSE))
			ft_printer_spaces(l, l->width);
	}*/
}

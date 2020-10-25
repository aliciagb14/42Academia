/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:15:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/25 14:35:59 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_case_width_prec_x(t_list *l, char *s, int nb)
{
	if (l->width == 0 && nb != 0)
		ft_printer_character(l, s);
	else if (nb == 0 && l->flags.point == TRUE && l->precision == 0)
		ft_printer_spaces(l, l->width);
	else
	{
		if (l->width > l->precision && l->precision >= l->len)
			ft_case_width_prec_aux_x(l, s, nb);
		else
		{
			ft_printer_zero(l, l->precision - l->len);
			if (l->precision > l->len ||
				(l->precision <= l->len && l->flags.minus == TRUE))
			{
				ft_printer_character(l, s);
				ft_printer_spaces(l, l->width - l->len);
			}
			else if (l->precision <= l->len && l->flags.minus == FALSE)
			{
				ft_printer_spaces(l, l->width - l->len);
				ft_printer_character(l, s);
			}
		}
	}
}

void	ft_case_width_prec_aux_x(t_list *l, char *s, int nb)
{
	if (l->flags.minus == TRUE)
	{
		if (nb == 0 && l->precision != 0)
		{
			ft_printer_zero(l, l->precision);
			ft_printer_spaces(l, l->width - l->precision);
		}
		else
		{
			ft_printer_zero(l, l->width - l->precision);
			ft_printer_character(l, s);
			ft_printer_spaces(l, l->precision - l->len);
		}
	}
	else
	{
		ft_printer_spaces(l, l->width - l->precision);
		ft_printer_zero(l, l->precision - l->len);
		ft_printer_character(l, s);
	}
}

void	ft_case_width_x(t_list *l, char *s, int nb)
{
	if (l->precision > l->width ||
		(l->width > l->precision && l->flags.zero == TRUE))
	{
		if (l->precision > l->width)
			ft_printer_zero(l, l->precision - l->len);
		else
			ft_printer_zero(l, l->width - l->len);
		ft_printer_character(l, s);
	}
	else
	{
		if (nb == 0 && l->flags.point == TRUE && l->precision == 0)
			ft_printer_spaces(l, l->width);
		else
		{
			ft_printer_spaces(l, l->width - l->len);
			ft_printer_character(l, s);
		}
	}
}

char	*ft_trans_hex(long int i, char c)
{
	long int			i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 1;
	if (c == 'X')
		hex_char = "0123456789ABCDEF";
	else
		hex_char = "0123456789abcdef";
	i_copy = i;
	while (i_copy >= 16 && (i_copy /= 16))
		count++;
	i_copy = i;
	if (!(def = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	def[count] = '\0';
	while (i_copy > 15)
	{
		--count;
		def[count] = hex_char[i_copy % 16];
		i_copy /= 16;
	}
	def[--count] = hex_char[i_copy % 16];
	return (def);
}

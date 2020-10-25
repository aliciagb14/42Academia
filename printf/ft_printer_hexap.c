/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_hexap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:14:16 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/25 14:36:02 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_case_printer_hexap_aux(t_list *l, char *s)
{
	l->cnt += 2;
	if (l->precision == 0 && l->width < l->len)
		write(1, "0x", 2);
	else if (l->precision > l->len)
	{
		write(1, "0x", 2);
		if (l->precision > l->len)
			ft_printer_zero(l, l->precision - 1);
		ft_printer_character(l, s);
	}
	else
	{
		ft_printer_spaces(l, l->width - l->len + 1);
		write(1, "0x", 2);
	}
}

void	ft_case_width_hexap(t_list *l, char *str)
{
	l->len += 2;
	l->cnt += 2;
	if (l->flags.minus == FALSE)
	{
		if (l->width > l->len)
			ft_printer_spaces(l, l->width - l->len);
		write(1, "0x", 2);
		if (l->precision > l->width && l->precision > l->len)
			ft_printer_zero(l, l->precision - l->width - 1);
		ft_printer_character(l, str);
	}
	else
	{
		write(1, "0x", 2);
		ft_printer_character(l, str);
		if (l->width > l->len)
			ft_printer_spaces(l, l->width - l->len);
	}
}

char	*ft_trans_hexp(unsigned long i)
{
	unsigned long		i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 1;
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

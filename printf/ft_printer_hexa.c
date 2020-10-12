/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:16:33 by user42            #+#    #+#             */
/*   Updated: 2020/09/29 21:07:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_hexa(t_list *l, const char *line)
{
	long int number;
	char *str;


	number = va_arg(l->args, int);
	str = ft_trans_hex(number, line[l->pos]);
	l->len = ft_strlen(l, str);
	if (l->flags.minus == 1 || (l->width > 0 && l->precision > 0))
		ft_case_width_prec_x(l, line, str, number);
	else if (l->flags.zero == 1 || (l->width > 0 && l->flags.minus == FALSE))
		ft_case_width_x(l, line, str, number);
}


char	 *ft_trans_hex(long int i, char c)
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

void ft_case_width_prec_x(t_list *l, const char *line, char *s, int nb)
{
	ft_printer_zero(l, nb, l->precision - l->len);
	ft_printer_character(l, s);
	ft_printer_spaces(l, l->width - l->precision, line);
}

void ft_case_width_x(t_list *l, const char *line, char *s, int nb)
{
	//TODO: nb puesto para q no de error, borrar despues
	if (nb){}
	ft_printer_spaces(l, l->width - l->len, line);
	ft_printer_character(l, s);
}
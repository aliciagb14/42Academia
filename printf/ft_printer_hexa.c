/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:15:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/21 23:14:00 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_hexa(t_list *l, const char *line)
{
	long int number;
	char *str;


	number = va_arg(l->args, unsigned long int);
	str = ft_trans_hex(number, line[l->pos]);
	l->len = ft_strlen(l, str);

	if (l->flags.minus == 1 || (l->width > 0 && l->precision > 0))
		ft_case_width_prec_x(l, line, str, number);
	else if (l->flags.zero == 1 || (l->width >= 0 && l->flags.minus == FALSE))
		ft_case_width_x(l, line, str, number);
}

/*void	ft_case_zero_hexa(t_list *l, const char *line, char *s, int nb)
{
	if (l->flags.minus == TRUE || l->precision > 0)
		ft_printer_spaces(l, l->precision, line);
	else if (l->precision <= 0)
		ft_printer_spaces(l, l->width, line);
}*/

void	ft_case_width_prec_x(t_list *l, const char *line, char *s, int nb)
{
	if (l->width == 0 && nb != 0)
		ft_printer_character(l, s);
	else
	{
		if (l->width > l->precision && l->precision > l->len)
		{
			if (l->flags.minus == TRUE)
			{
				if (nb == 0)
				{
					ft_printer_zero(l, nb, l->precision);
					ft_printer_spaces(l, l->width - l->precision, line);
				}
				else
				{
					ft_printer_zero(l, nb, l->width - l->precision);
					ft_printer_character(l, s);
					ft_printer_spaces(l, l->precision - l->len, line);	
				}
			}
			else
			{
				ft_printer_spaces(l, l->width - l->precision, line);
				ft_printer_zero(l, nb, l->precision - l->len);
				ft_printer_character(l, s);
			}
			
		}
		else
		{
			ft_printer_zero(l, nb, l->precision - l->len);
			if (l->precision > l->len)
			{
				ft_printer_character(l, s);
				ft_printer_spaces(l, l->width - l->len, line); //-7x, 33
			}
			else
			{
				if (l->flags.minus == TRUE)
				{
					ft_printer_character(l, s);	
					ft_printer_spaces(l, l->width - l->len, line);
				}
				else
				{	
					ft_printer_spaces(l, l->width - l->len, line); //-7x, 33
					ft_printer_character(l, s);	
				}
			}
		}
	}
}

void	ft_case_width_x(t_list *l, const char *line, char *s, int nb)
{
	if (l->precision > l->width || (l->width > l->precision && l->flags.zero == TRUE))
	{
		if (l->precision > l->width)
			ft_printer_zero(l, nb, l->precision - l->len);
		else
				ft_printer_zero(l, nb, l->width - l->len);
		ft_printer_character(l, s);
	}
	else
	{
		//if (l->precision != l->len && l->precision != 0)
		//{
			ft_printer_spaces(l, l->width - l->len, line);
			ft_printer_character(l, s);
		//}
	}
	
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
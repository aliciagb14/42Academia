/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_hexap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:14:16 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/18 13:30:32 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_hexap(t_list *l, const char *line)
{
    
	unsigned long int number;
	char *str;


	number = va_arg(l->args, int);
	str = ft_trans_hexp(number);
	l->len = ft_strlen(l, str);
	if (number == 0 || number == NULL)
	{
		l->len = 3;
		if (l->width > 0)
			ft_printer_spaces(l, l->width - l->len, line);
		ft_printer_character(l, "0x0");
	}
	else if (l->width >= 0 && l->precision < 0)
		ft_printer_character(l, str);
   /* else if ((l->flags.minus == TRUE || l->flags.zero == TRUE) && l->width <= 0 &&
		l->precision <= 0)
        ft_printer_character(l, str);
	else if (l->width >= 0 && l->precision >= 0)
		ft_case_width_prec_hexap(l, line, str);
	else if (l->width >= 0 || l->precision >= 0)
		ft_case_width_hexap(l, line, str, number);*/
}
/*
void ft_case_width_prec_hexap(t_list *l, const char *line, char *str)
{
	if (l->flags.minus == FALSE && l->flags.zero == FALSE)
	{
		ft_printer_spaces(l, l->width - l->precision - 2, line);
		ft_printer_character(l, str);
	}
	else if (l->flags.minus == 1)
	{
		ft_printer_character(l, str);
		ft_printer_spaces(l, l->width - l->len, line);
	}
	else if (l->flags.zero == 1 && l->flags.minus == FALSE)
	{
		ft_printer_spaces(l, l->width - l->len, line);
		ft_printer_character(l, str);
	}
}

void ft_case_width_hexap(t_list *l, const char *line, char *str, int number)
{
	if (l->flags.minus == FALSE && l->flags.zero == FALSE && l->precision <= 0)
	{
		ft_printer_spaces(l, l->width - l->len, line);
		ft_printer_character(l, str);
	} 
	else if (l->flags.minus == 1 && l->precision < l->len)
	{
		ft_printer_character(l, str);
		ft_printer_spaces(l, l->width - l->len, line);
	}
	else if (l->flags.zero == 1 && l->precision < l->len && l->width < l->len)
	{
		if (l->precision <= 0)
			ft_printer_zero(l, number, l->width - l->len);
		ft_printer_character(l, str);
	}
	else if (l->precision >= 0 && (l->len < l->precision || l->len < l->width))
	{
		str = ft_case_prec_hexap(l, str);
		ft_printer_zero(l, number, l->precision - l->len + 2);
		ft_printer_character(l, str);
	}
}*/

char *ft_case_prec_hexap(t_list *l, char *s)
{
	int cnt;

	cnt = 0;
	while (cnt < 2)
	{
		ft_putchar(*s, l);
		s++;
		cnt++;
	}
	return (s);
}

char *ft_type_hexap(t_list *l, char *def)
{
    int i;
    
    i = 0;
    def[i] = '0';
    i++;
    def[i] = 'x';
    i++;
	l->len = 2;
    return (def);
}

char	 *ft_trans_hexp(unsigned long int i)
{
	unsigned long int			i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 3;
	
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
    def = ft_type_hexap(def);
	return (def);
}
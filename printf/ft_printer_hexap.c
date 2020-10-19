/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_hexap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:14:16 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/19 17:37:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printer_hexap(t_list *l, const char *line)
{
    
	unsigned long int number;
	char *str;


	number = va_arg(l->args, unsigned long int);
	str = ft_trans_hexp(number);
	l->len = ft_strlen(l, str);
	if (number == 0)
	{
		l->len = 3;
		if (l->width > 0)
			ft_printer_spaces(l, l->width - l->len, line);
		ft_printer_character(l, "0x0");
	}
	/*else if (l->precision == 0)
	{
		l->len += 5;
		l->cnt += 5;
		write(1, "(nil)", 5);
	}*/
	else if (l->width >= 0 && l->precision < 0)
	{
		l->len+= 2;
		l->cnt+= 2;
		write(1, "0x", 2);
		ft_printer_character(l, str);
	}
	else if (l->width >= 0 || l->precision >= 0)
		ft_case_width_hexap(l, line, str, number);
}

void ft_case_width_hexap(t_list *l, const char *line, char *str, int number)
{
	l->len += 2;
	l->cnt += 2;
	if (l->flags.minus == FALSE)
	{
		if (l->width > l->len)
			ft_printer_spaces(l, l->width - l->len, line);
		write(1, "0x", 2);
		ft_printer_character(l, str);		
	}
	else
	{
		write(1, "0x", 2);
		ft_printer_character(l, str);
		if (l->width > l->len)
			ft_printer_spaces(l, l->width - l->len, line);
	}
	
}

/*char *ft_case_prec_hexap(t_list *l, char *s)
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
}*/

char	 *ft_trans_hexp(unsigned long i)
{
	unsigned long			i_copy;
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
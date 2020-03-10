/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:16:36 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/10 12:56:04 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Miramos el ancho y a raiz de ahi,
Controla si hay - o 0, no se pueden combinar los dos.
encuentra flag: si lo almacena bn devuelve 1, si no 0
*/

int ft_saver_flags(t_list *l, char *line)
{
	int number;
	while (!ft_isspecifier(line[l->pos]))
	{
		if (line[l->pos] == '-')  
			l->flags.minus = TRUE;
		else if (line[l->pos] == '0')
			l->flags.zero = TRUE;
		else if (ft_isnumber(line[l->pos]))
			l->width = ft_atoi(line, l); //guardo en width el numero antes que hay antes de la d
		else if (line[l->pos] == '*')
			l->width = va_arg(l->args, int);
		else if (line[l->pos++] == '.')
		{
			if (line[l->pos++] == '*')
				l->precision = ft_atoi(line, l);
			l->precision = va_arg(l->args, int);
		}
		if (!ft_isspecifier(line[l->pos]))
			l->pos++;
	}
}

void	ft_printer(t_list *l, const char *line)
{
	int difference;
	int number;

	l->len = ft_get_size_num(l, number);
	difference = l->width - l->len;
	while (difference > 0)
	{
		if (line[l->pos] ==  ' ')
			ft_printer_spaces(l, line);
		//else if (line[l->pos] == l->flags.minus)
		//	ft_printer_minus(l, line);
		//else if (line[l->pos] == l->flags.zero)
		//	ft_printer_zeros(l, line);
		//difference--;
	}
}

/*void	ft_printer_zero(t_list *l, const char *line)
{
	if(line[l->pos] == l->flags.zero)
		write(1, ' ', 1);
	else
	{
		
	}
}*/

/*void	ft_printer_minus(t_list *l, const char *line)
{
	write(1, '-', 1);
}*/

void	ft_printer_spaces(t_list *l, const char *line)
{
	int number;
	int difference;
	
	if (line[l->pos] == l->flags.minus) //si encuentra - escribe 1º el numero y luego los espacios (segun ancho que haya y prec)
	{
		l->width = va_arg(l->args, int);
		number = ft_atoi((char *)line, l);
	}
	while (difference > 0)
	{
		ft_putchar(' ', l);
		difference--;
	}
}

/*void	ft_printer_thing(t_list *l, const char *line)
{

}*/

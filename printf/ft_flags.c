/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:16:36 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/05 16:36:15 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Miramos el ancho y a raiz de ahi,
Controla si hay - o 0, no se pueden combinar los dos.
encuentra flag: si lo almacena bn devuelve 1, si no 0
*/

int ft_first_flags(char *line, t_list *l)
{
	int number;
	while (!ft_isspecifier(*line))
	{
		if (line[l->pos] == '-')
			l->flags.minus = TRUE;
		else if (line[l->pos] == '0')
			l->flags.zero = TRUE;
		else if (line[l->pos] == '*')
			l->flags.ast = TRUE;
		else if (ft_isnumber(line[l->pos]))
		{
			l->width = ft_atoi(&(line[l->pos]), l); //guardo en width el numero antes que hay antes de la d
			l->len = ft_get_size_num(l, number); //guardo en len la long del numero que me pasen por parametro
			ft_saver_width(l, line, number);
		}
	}
}

void ft_saver_width(t_list *l, const char *line, int number)
{
	int difference;

	while (line[l->pos] == 'c' || line[l->pos] == 's' ||
		line[l->pos] == 'p' || line[l->pos] == 'd')
	{
		if (l->width > l->len)
		{
			difference = l->width - l->len;
			if (number < 0) //escribe -
				ft_putchar('-', l);
			while (difference > 0)
			{
				if (l->flags.zero)
					ft_putchar('0', l);
				else
					ft_putchar(' ', l);
				difference--;
			}
		}
	}
}

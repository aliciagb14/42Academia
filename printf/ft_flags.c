/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:16:36 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/02 15:37:25 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Miramos el ancho y a raiz de ahi,
Controla si hay - o 0, no se pueden combinar los dos.
encuentra flag: si lo almacena bn devuelve 1, si no 0
*/
void ft_first_flags(const char *line, t_list *l)
{
	if (line[l->pos] == '-' || line[l->pos] == '0')
	{
		if (line[l->pos] == '-')
			return (TRUE);
		else if (line[l->pos] == '0')
			return (TRUE);
	}
}

void ft_width(t_list *l, const char *line, int number)
{
	int difference;
	char c;

	c = (l->flags.zero) ? '0' : ' ';
	//si es distinto a 0, es decir flag - o nada
	while (line[l->pos] != '0')
	{
		if (l->width > l->len)
			write(1, ' ', 1);
		/*segun el caso que sea hace lo que tiene que hacer*/
		else
		{
			difference = l->width - l->len;
			if (number < 0)
				write(1, '-', 1);
			else
			{
				//justificado a la derecha
				while (difference > 0)
				{
					write(1, &c, 1);
					difference--;
				}
			}
		}
	}
}

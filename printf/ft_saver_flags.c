/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saver_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 18:05:08 by agonzale          #+#    #+#             */
/*   Updated: 2020/04/07 12:37:24 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_saver_flags(t_list *l, char *line)
{
	int number;
	while (!ft_isspecifier(line[l->pos]))
	{
		if (line[l->pos] == '-')  
			l->flags.minus = TRUE;
		else if (line[l->pos] == '0')
			l->flags.zero = TRUE;
		else if (line[l->pos] == ' ')
			l->flags.space = TRUE;
		else if (ft_isnumber(line[l->pos]))
		{
			l->width = ft_atoi(line, l); //guardo en width el numero antes que hay antes de la d
			while(ft_isnumber(line[l->pos++]))
				l->pos++;
		}
		else if (line[l->pos] == '*')
			l->width = va_arg(l->args, int);
		else if (line[l->pos] == '.')
		{
			if (line[l->pos++] == '*')
				l->precision = va_arg(l->args, int);
			else
				l->precision = ft_atoi(line, l);
			while(!ft_isspecifier(line[l->pos]))
				l->pos++;
		}
		if(!ft_isspecifier(line[l->pos]))
			l->pos++;
	}
	return (l->pos);
}
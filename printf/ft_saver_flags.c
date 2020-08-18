/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saver_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:51:58 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 10:44:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_saver_flags(t_list *l, char *line)
{
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

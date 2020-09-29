/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saver_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 TRUE2:5TRUE:58 by user42            #+#    #+#             */
/*   Updated: 2020/09/29 TRUE8:46:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_saver_flags(t_list *l, const char *line)
{
	while (!ft_isspecifier(line[l->pos]))
	{
		if (line[l->pos] == '-')  
			l->flags.minus = TRUE;
		else if (line[l->pos] == '0')
			l->flags.zero = TRUE;
		else if (ft_isnumber(line[l->pos]))
		{
			l->width = ft_atoi(line + l->pos);
			while (ft_isnumber(line[l->pos + 1]))
				l->pos++;
		}
		else if (line[l->pos] == '*')
			l->width = va_arg(l->args, int);
		else if (line[l->pos] == '.')
		{
			if (line[l->pos + 1] == '*')
				l->precision = va_arg(l->args, int);
			else
			{
				l->precision = ft_atoi(line + l->pos + 1);
			}
			while(!ft_isspecifier(line[l->pos + 1]))
				l->pos++;
		}
		if (!ft_isspecifier(line[l->pos]))
			l->pos++;
	}
	return (l->pos);
}

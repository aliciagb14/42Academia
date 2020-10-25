/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saver_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:18:35 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/25 13:11:05 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_saver_flags(t_list *l, const char *line)
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
			ft_saver_ast_width(l);
		else if (line[l->pos] == '.')
			ft_saver_ast_prec(l, line);
		if (!ft_isspecifier(line[l->pos]))
			l->pos++;
	}
	return (l->pos);
}

void	ft_saver_ast_width(t_list *l)
{
	l->flags.ast = TRUE;
	l->width = va_arg(l->args, int);
	if (l->width < 0)
	{
		l->flags.minus = TRUE;
		l->width = -l->width;
	}
}

void	ft_saver_ast_prec(t_list *l, const char *line)
{
	l->flags.point = TRUE;
	if (line[l->pos + 1] == '*')
	{
		l->flags.ast = TRUE;
		l->precision = va_arg(l->args, int);
	}
	else
		l->precision = ft_atoi(line + l->pos + 1);
	while (!ft_isspecifier(line[l->pos + 1]))
		l->pos++;
}

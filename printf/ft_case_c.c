/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 08:04:40 by agonzale          #+#    #+#             */
/*   Updated: 2020/02/27 16:00:56 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	l->cnt++;
	write(1, &c, 1);
}

void 	case_c(t_list * l, const char *line, char next)
{
	next = (char)va_arg(l->args, int);
	ft_putchar(next, l);
}

void	princp_c(const char *line, t_list *l)
{
	char next;
	if (line[l->pos] == 'c')
	{
		case_c(l, line, next);
		l->pos++;
	}
	ft_putchar(' ', l);
}

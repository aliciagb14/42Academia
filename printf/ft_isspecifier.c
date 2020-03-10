/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:07:16 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/10 10:20:29 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	else
		return (FALSE);
}

void		ft_specifier(t_list *l, const char *line)
{
	if (line[l->pos] == 'c')
		ft_case_c(l);
	else if (line[l->pos] == 's')
		ft_case_s(l);
	else if (line[l->pos] == 'd')
		ft_case_d(l);
}

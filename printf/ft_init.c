/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:14:37 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/20 20:35:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize(t_list *l)
{
	l->width = 0;
	l->precision = 0;
	l->cnt = 0;
	l->pos = 0;
	l->len = 0;
	l->flags.zero = FALSE;
	l->flags.space = FALSE;
	l->flags.minus = FALSE;
	l->flags.point = FALSE;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:45:51 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/11 22:46:01 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_initialize(t_list *l)
{
	l->width = 0;
	l->precision = 0;
	l->cnt = 0;
	l->pos = 0;
	l->len = 0;
	l->flags.zero = 0;
	l->flags.space = FALSE;
	l->flags.minus = FALSE;
}
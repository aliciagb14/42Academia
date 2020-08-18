/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:43:06 by user42            #+#    #+#             */
/*   Updated: 2020/07/23 12:44:07 by user42           ###   ########.fr       */
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

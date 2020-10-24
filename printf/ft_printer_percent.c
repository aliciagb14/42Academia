/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:35:15 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/24 12:52:46 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer_percent(t_list *l)
{
	if (l->flags.minus == TRUE)
	{
		ft_putchar('%', l);
		ft_printer_spaces(l, l->width - 1);
	}
	else
	{
		if (l->flags.zero == FALSE)
			ft_printer_spaces(l, l->width - 1);
		else
			ft_printer_zero(l, l->width - 1);
		ft_putchar('%', l);
	}
}

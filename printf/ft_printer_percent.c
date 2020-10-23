/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:16:19 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/23 10:34:01 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printer_percent(t_list *l, const char *line)
{
    int number;

    number = 0;
    if (l->flags.minus == TRUE)
    {
        ft_putchar('%', l);
        ft_printer_spaces(l, l->width - 1, line);
    }
    else
    {
        if (l->flags.zero == FALSE)
            ft_printer_spaces(l, l->width - 1, line);
        else
            ft_printer_zero(l, number, l->width - 1);
        ft_putchar('%', l);
    }
}

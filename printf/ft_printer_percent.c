/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:59:32 by user42            #+#    #+#             */
/*   Updated: 2020/10/18 12:14:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printer_percent(t_list *l, const char *line)
{
    int number = 0;
    if (l->flags.minus == TRUE)
    {
        ft_putchar('%', l);
        ft_printer_spaces(l, l->width - 1, line);
    }
    else if (l->flags.minus == FALSE && l->flags.zero == FALSE)
    {
        ft_printer_spaces(l, l->width - 1, line);
        ft_putchar('%', l);
    }
    else if (l->flags.minus == FALSE && l->flags.zero == TRUE)
    {
        ft_printer_zero(l, number, l->width - 1);
        ft_putchar('%', l);
    }
}
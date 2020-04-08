/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:42:20 by agonzale          #+#    #+#             */
/*   Updated: 2020/04/07 12:51:03 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
	l->cnt++;
}

void	ft_case_c(t_list *l)
{
	char next;
	next = (char)va_arg(l->args, int);
	ft_putchar(next, l);
}
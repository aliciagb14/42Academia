/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:52:15 by agonzale          #+#    #+#             */
/*   Updated: 2020/02/20 10:58:11 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

init_flags(t_list * s_flags)
{
    if(s_flags->tab)
    {

        s_flags->len = 0;
        s_flags->tab = 0;
        s_flags->zero = 0;
    }
}

init_princp(t_list * s_princp)
{
    if(s_princp)
    {
        t_flags->width = 0;
        t_flags->prec = 0;
        t_flags->cnt = 0;
        t_princp->len_str = 0;
        t_princp->format = 0;
        t_princp->data = 0;
    }
}
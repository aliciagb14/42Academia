/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:59:08 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:59:10 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdbl_add_back(t_list_dbl **lst, t_list_dbl *new)
{
	t_list_dbl	*p;

	p = *lst;
	if (!p)
		*lst = new;
	else
	{
		p = ft_lstdbl_last(p);
		p->next = new;
		p->next->prev = p;
	}
}

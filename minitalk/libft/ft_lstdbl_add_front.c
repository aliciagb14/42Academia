/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_add_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:59:00 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:59:02 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdbl_add_front(t_list_dbl **lst, t_list_dbl *new)
{
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}

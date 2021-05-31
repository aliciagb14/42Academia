/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:58:35 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:58:37 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_dbl	*ft_lstdbl_last(t_list_dbl *lst)
{
	if (lst == 0)
		return (lst);
	else
		while (lst->next != 0)
			lst = lst->next;
	return (lst);
}

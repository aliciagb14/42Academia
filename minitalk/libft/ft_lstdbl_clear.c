/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:58:51 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/29 19:45:38 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdbl_clear(t_list_dbl **lst, void (*del)(void *))
{
	t_list_dbl		*aux;
	t_list_dbl		*aux2;

	if (lst == NULL || *lst == NULL)
		return ;
	aux = *lst;
	while ((*lst)->prev && (*lst)->prev != aux)
		*lst = (*lst)->prev;
	while (*lst && *lst != aux)
	{
		aux2 = (*lst)->next;
		ft_lstdbl_delone(*lst, del);
		*lst = aux2;
	}
	if (*lst == aux)
		ft_lstdbl_delone(*lst, del);
}

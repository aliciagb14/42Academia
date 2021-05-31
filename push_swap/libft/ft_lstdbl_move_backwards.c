/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_move_backwards.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:58:09 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:58:11 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdbl_move_backwards(t_list_dbl *lst)
{
	void	*aux;

	if (lst->next)
	{
		aux = lst->content;
		lst->content = lst->next->content;
		lst->next->content = aux;
	}
}

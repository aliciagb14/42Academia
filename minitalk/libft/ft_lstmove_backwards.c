/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove_backwards.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:56:47 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:56:51 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmove_backwards(t_list *lst)
{
	void	*aux;

	if (lst->next)
	{
		aux = lst->content;
		lst->content = lst->next->content;
		lst->next->content = aux;
	}
}

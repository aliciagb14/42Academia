/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove_backwards.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:58:43 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 13:58:47 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmove_backwards(t_list *list)
{
	void *aux;

	if (list->next)
	{
		aux = list->content;
		list->content = list->next->content;
		list->next->content = aux;
	}
}

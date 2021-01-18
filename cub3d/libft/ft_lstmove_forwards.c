/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove_forwards.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:58:31 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 13:58:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmove_forwards(t_list *list, t_list *src)
{
	void *aux;

	if (list == src)
		return ;
	while (src->next->content != list->content && src)
		src = src->next;
	if (!src)
		return ;
	aux = src->content;
	src->content = list->content;
	list->content = aux;
}

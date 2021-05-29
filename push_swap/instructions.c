/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:40:43 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/29 15:34:40 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool is_sorted(t_list_dbl *list)
{
	t_list_dbl *aux;

	if (!list)
		return (0);
	aux = list;
	while (aux->next != list)
	{ //aux que al inicio sea list, y me voy a mover con el aux, hasta que aux de next = list
		if (((int *)aux->content)[0] > ((int *)aux->next->content)[0])
			return (false);
		aux = aux->next;
	}
	return (true);
}
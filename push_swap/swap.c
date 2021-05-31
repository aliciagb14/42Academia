/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:41 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/29 13:32:20 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//intercambia primeros 2 elementos en la parte superior de la pila

void swap(t_list_dbl *list)
{
	int *aux;

	if (!list || !list->next)
		return;
	aux = list->content;
	list->content = list->next->content;
	list->next->content = aux; // en el nodo 2 esta el contenido del 1
}


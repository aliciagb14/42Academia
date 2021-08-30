/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:35:27 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/30 09:14:06 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
**	Separa en 2 mitades los numeros que tenemos que ordenar
**
*/
int	get_pivot(t_list_dbl *init, int start, int end)
{
	int	swaps;
	int	pivot;
	int	i;
	t_list_dbl	*aux;
	t_list_dbl	*aux2;

	swaps = 0;
	aux = init;
	pivot = *(int*)(init->content);
	//while (swaps != (size / 2))
	while (swaps != ((end - start) / 2))
	{
		i = 0;
		swaps = 0;
		aux2 = init;
		pivot = *(int*)(aux->content);
		while (i < end)
		{
			if (*(int*)(aux2->content) <= pivot)
				swaps++;
			i++;
			aux2 = aux2->next;
		}
		aux = aux->next;
		//swaps = end - start - swaps;
		if (swaps < 0)
			swaps *= -1;
	}
	return (pivot);
}

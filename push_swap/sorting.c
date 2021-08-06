/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:35:27 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 13:35:45 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
**	Separa en 2 mitades los numeros que tenemos que ordenar
**
*/
int	get_pivot(t_list_dbl *start, int size)
{
	int	swaps;
	int	pivot;
	int	i;

	pivot = *(int*)(start->content);
	while (swaps != size / 2)
	{
		swaps = 0;
		pivot = *(int*)(start->next->content);
		while (i < size)
		{
			if (*(int*)(start->content) <= pivot)
				swaps++;
			i++;
		}
		swaps -= size;
	}
	return (pivot);
}

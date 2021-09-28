/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:35:27 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/28 13:11:42 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_list_dbl *init, int start, int end)
{
	int	swaps;
	int pivot;
	int i;
	t_list_dbl	*aux;
	t_list_dbl	*aux2;

	swaps = 0;
	aux = init;
	while (swaps != ((end - start) / 2))
	{
		i = 0;
		swaps = 0;
		aux2 = init;
		pivot = *(int *)(aux->content);
		while (i < end)
		{
			if (*(int *)(aux2->content) <= pivot)
				swaps++;
			i++;
			aux2 = aux2->next;
		}
		aux = aux->next;
		if (swaps < 0)
			swaps *= -1;
	}
	return (pivot);
}

int	smallest_nb(t_list_dbl *stack_a)
{
	int			min;
	int			min_index;
	int			i;
	t_list_dbl	*aux;

	i = 0;
	min_index = 0;
	min = *(int *)stack_a->content;
	aux = stack_a;
	if (stack_a->next == NULL)
		return (min);
	while (stack_a != aux || i == 0)
	{
		if (min > *(int *)stack_a->content)
		{
			min = *(int *)stack_a->content;
			min_index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (min);
}

int	biggest_nb(t_list_dbl *stack_b)
{
	t_list_dbl	*aux;
	int			max;
	int			max_index;
	int			i;

	i = 0;
	aux = stack_b;
	max = 0;
	while (stack_b != aux || i == 0)
	{
		if (max < *(int *)stack_b->content)
		{
			max = *(int *)stack_b->content;
			max_index = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (max);
}

/*
**busca el mas pequeño de a y el mas grande de b. Si peq a > grande b:  true
*/
t_bool	can_sort_a(t_stacks *stack)
{
	int	smallest;
	int	biggest;

	smallest = smallest_nb(stack->stack_a);
	biggest = biggest_nb(stack->stack_b);
	// //printf"+ pequeño: %d, + grande: %d\n", smallest, biggest);
	if (smallest > biggest)
		return (true);
	return (false);
}

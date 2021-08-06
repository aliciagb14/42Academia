/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:49:50 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 14:41:55 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Numeros ordenados se encuentran abajo del stack
*/
int	push_rotate_forwards_a(t_list *lista, int nb_swaps,
	t_stacks *stack)
{
	int	pivot;
	int	rotated_times;

	rotated_times = 0;
	pivot = get_pivot(stack->stack_a, stack->size_a - stack->sorted_elem_a);
	while (rotated_times < stack->size_a - stack->sorted_elem_a)
	{
		if (*(int*)lista->content <= pivot)
		{
			push_b(stack, true);
			nb_swaps++;
		}
		else
		{
			rotate_a(&stack->stack_a, true);
			rotated_times++;
		}
	}
	return (rotated_times);
}

/*
** Numeros ordenados se encuentran arriba del stack
**	
*/
int	push_rotate_backwards_a(t_list *lista, int nb_swaps,
	t_stacks *stack)
{
	int	pivot;
	int	rotated_times;

	pivot = get_pivot(stack->stack_a, stack->size_a - stack->sorted_elem_a);
	if (stack->sorted_elem_a < stack->size_a - stack->sorted_elem_a)
	{
		while (stack->sorted_elem_a)
		{
			rotate_a(&stack->stack_a, true);
			rotated_times = 0;
		}
	}
	while (rotated_times)
	{
		rev_rotate_a(&stack->stack_a, true);
		if (*(int*)stack->stack_a->content <= pivot)
		{
			push_b(stack, true);
			nb_swaps++;
		}
		rotated_times--;
	}
	return (rotated_times);
}

/*
** Si el numero de elementos desordenados es > 3
** comprobaremos si el numero de elementos de la cola es 0
*/
void	sort_a(t_list *subdivisions, t_stacks *stack)
{
	int		nb_swaps;
	int		rotated_times;

	rotated_times = 0;
	subdivisions = NULL;
	while (stack->size_a - stack->sorted_elem_a > 3)
	{
		nb_swaps = 0;
		if (rotated_times == 0)
		{
			rotated_times = push_rotate_forwards_a(subdivisions, nb_swaps,
					stack);
		}
		else
		{
			rotated_times = push_rotate_backwards_a(subdivisions, nb_swaps,
					stack);
		}
		if (nb_swaps)
			ft_lstadd_front(&subdivisions, ft_lstnew((void*)nb_swaps));
	}
	three_numbers(stack->stack_a, stack->size_a - stack->sorted_elem_a);
	stack->sorted_elem_a = stack->size_a;
	sort_b(subdivisions, stack, nb_swaps);
}

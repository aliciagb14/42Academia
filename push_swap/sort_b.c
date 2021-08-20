/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:50:06 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/20 18:40:53 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position_biggest_number_b(t_list_dbl *stack_b)
{
	int	max;
	int	max_index;
	int	i;

	i = 0;
	max_index = 0;
	max = *(int*)stack_b->content;
	while (stack_b->next != NULL)
	{
		if (max < *(int*)stack_b->next->content)
		{
			max = *(int*)stack_b->next->content;
			max_index = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (max_index);
}
/*
** Comprueba que si como el numero recibido del stack a
** 			se puede ordenar
*/
t_bool	special_permutations(t_stacks *stack, int *tam_set, int *rotated_times)
{
	if (!is_sorted(stack->stack_a))
		sort_a(stack);
	while (*tam_set)
	{
		if (get_position_biggest_number_b(stack->stack_b)
			== stack->size_b - 1 && stack->size_b != 1)
		{
			rev_rotate_b(&stack->stack_b, true);
			(*rotated_times)--;
		}
		else if (get_position_biggest_number_b(stack->stack_b) == 1)
			swap_b(stack->stack_b, true);
		else if (get_position_biggest_number_b(stack->stack_b) == 0)
		{
			push_a(stack, true);
			stack->sorted_elem_a++;
			(*tam_set)--;
		}
		else
			return (false);
	}
	return (true);
}

int	push_rotate_backwards_b(t_stacks *stack,
	int *tam_set, int rotated_times)
{
	int	pivot;

	pivot = get_pivot(stack->stack_b, stack->size_b - *tam_set, stack->size_b);
	while (rotated_times > 0)
	{
		rev_rotate_b(&stack->stack_b, true);
		rotated_times--;
		special_permutations(stack, tam_set, &rotated_times);
		if (*(int*)(stack->stack_b->content) >= pivot)
		{
			push_a(stack, true);
			(*tam_set)--;
		}
	}
	return (rotated_times);
}

int	push_rotate_forwards_b(int *tam_set, t_stacks *stack)
{
	int	pivot;
	int	nb_swaps;

	nb_swaps = 0;
	pivot = get_pivot(stack->stack_b, 0, *tam_set);
	while (*tam_set > stack->sorted_elem_b)
	{
		if (!special_permutations(stack, tam_set, &nb_swaps))
		{
			if(*(int*)(stack->stack_b->content) >= pivot)
			{
				push_a(stack, true);
				tam_set--;
			}
			else
			{
				rotate_b(&stack->stack_b, true);
				nb_swaps++;
			}
		}
	}
	return (nb_swaps);
}

void	sort_b(t_list *subdivisions, t_stacks *stack)
{
	int		elem_cola_stack;
	int		tam_set;
	t_list	*aux;

	while (subdivisions)
	{
		tam_set = (int)((long int)subdivisions->content);
		elem_cola_stack = 0;
		while (tam_set)
		{
			if (elem_cola_stack == 0)
			{
				elem_cola_stack = push_rotate_forwards_b(&tam_set, stack);
			}
			else
				elem_cola_stack = push_rotate_backwards_b(stack, &tam_set,
					elem_cola_stack);
			sort_a(stack);
		}
		aux = subdivisions;
		subdivisions = subdivisions->next;
		ft_lstdelone(aux, 0);
	}
}

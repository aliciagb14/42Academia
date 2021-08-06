/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:50:06 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 14:39:37 by agonzale         ###   ########.fr       */
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

t_bool	special_permutations(t_list *subdivisions, t_stacks *stack,
	int *tam_set, int rotated_times)
{
	if (!is_sorted(stack->stack_a))
		sort_a(subdivisions, stack);
	while (rotated_times)
	{
		if (get_position_biggest_number_b(stack->stack_b) == *(int*)stack->stack_b->prev)
			rev_rotate_a(&stack->stack_b, true);
		else if (get_position_biggest_number_b(stack->stack_b)
			== *(int*)stack->stack_b->next)
			swap_b(stack->stack_b, true);
		else if (get_position_biggest_number_b(stack->stack_b)
			== *(int*)stack->stack_a)
		{
			push_a(stack->stack_a, true);
			stack->sorted_elem_a++;
			tam_set--;
		}
		else
			return (false);
	}
	return (true);
}

int	push_rotate_backwards_b(t_list *lista, int nb_swaps, t_stacks *stack,
	int *tam_set, int rotated_times)
{
	int	pivot;

	pivot = get_pivot(stack->stack_b, stack->size_b - stack->sorted_elem_b);
	while (rotated_times > 0)
	{
		rev_rotate_b(&stack->stack_b, true);
		rotated_times--;
		//special_permutations(lista, stack, tam_set, rotated_times);
		special_permutations(stack->stack_b, stack, tam_set, rotated_times);
		//if (lista->content >= pivot)
		if (*(int*)(stack->stack_b->content) >= pivot)
		{
			push_a(stack, true);
			nb_swaps++;
		}
	}
	return (rotated_times);
}

int	push_rotate_forwards_b(t_list *lista, int *tam_set, t_stacks *stack,
		int rotated_times)//t_list *lista
{
	int	pivot;
	int	nb_swaps;

	nb_swaps = 0;
	pivot = get_pivot(stack->stack_b, stack->size_b - stack->sorted_elem_b);
	while (*tam_set > stack->sorted_elem_b)
	{
		//if (!special_permutations(lista, stack, tam_set, elem_cola_stack))
		if (!special_permutations(stack->stack_b, stack, tam_set, rotated_times))
		{
			//if (lista->content >= pivot)
			if(*(int*)(stack->stack_b->content))
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
	return (tam_set);
}

void	sort_b(t_list *subdivisions, t_stacks *stack, int nb_swaps)
{
	int		elem_cola_stack;
	int		*tam_set;
	t_list	*aux;

	while (subdivisions)
	{
		while (subdivisions->content)
		{
			if (elem_cola_stack == 0)
			{
				elem_cola_stack = push_rotate_forwards_b(subdivisions, tam_set,
						stack, elem_cola_stack);
			}
			else
				elem_cola_stack = push_rotate_backwards_b(subdivisions,
						nb_swaps, stack, tam_set, elem_cola_stack);
			sort_a(subdivisions, stack);
		}
		aux = subdivisions;
		subdivisions = subdivisions->next;
		ft_lstdelone(aux, 0);
	}
}

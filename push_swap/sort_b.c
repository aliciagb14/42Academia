/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:50:06 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/28 13:54:23 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position_biggest_number_b(t_list_dbl *stack_b)
{
	t_list_dbl	*aux;
	int	max;
	int	max_index;
	int	i;

	i = 0;
	aux = stack_b;
	max = 0;
	if (stack_b->next == NULL)
		return (0);
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
	return (max_index);
}

t_bool check_special_permutations(t_stacks *stack, int *tam_set, int *rotated_times)
{
	int max_index;

	max_index = get_position_biggest_number_b(stack->stack_b);
	if (max_index == stack->size_b - 1 && stack->size_b != 1)
	{
		rev_rotate_b(&stack->stack_b, true);
		(*rotated_times)--;
		max_index = 0;
	}
	else if (max_index == 1 && *rotated_times > 1)
	{
		swap_b(stack->stack_b, true);
		max_index = 0;
	}
	else if (max_index == 0 && *rotated_times > 0)
	{
		push_a(stack, true);
		stack->sorted_elem_a++;
		(*tam_set)--;
	}
	else
		return (false);
	return (true);
}
/*
** Queremos saber la posicion del numero mas grande del stack para poder
** ahorrarnos operaciones en casos específicos
** rotated times, numero de veces que pasa un numero (> pivote) a la cola del stack
*/
t_bool	special_permutations(t_stacks *stack, int *tam_set, int *rotated_times)
{
	t_bool done;

	done = false;
	if (stack->size_b > 1 && can_sort_a(stack))
	{
		sort_a(stack);
		while (*tam_set > 0 && check_special_permutations(stack, tam_set, rotated_times))
			done = true;
	}
	else if (stack->size_b == 1)
		push_a(stack, true);
	return done;
}
/*
** rotated times, numero de veces que pasa un numero a la cola del stack 
*/
int	push_rotate_backwards_b(t_stacks *stack,
	int *tam_set, int rotated_times, int pushed_times)
{
	int	pivot;

	pivot = get_pivot(stack->stack_b, stack->size_b - *tam_set, stack->size_b);
	while (rotated_times > 0)
	{
		rev_rotate_b(&stack->stack_b, true);
		rotated_times--;
		(*tam_set)++;
		special_permutations(stack, tam_set, &rotated_times);
		if (stack->size_b > 1 && *(int*)(stack->stack_b->content) >= pivot)
		{
			push_a(stack, true);
			(*tam_set)--;
			pushed_times--;
		}
	}
	return (rotated_times);
}

int	push_rotate_forwards_b(int *tam_set, t_stacks *stack)
{
	int	pivot;
	int	nb_swaps;
	int pushed_times;

	nb_swaps = 0;
	pivot = get_pivot(stack->stack_b, 0, stack->size_b);
	pushed_times = *tam_set;//j = pushed_times, *tam_set = *current_set_size, i = nb_swaps
	while (pushed_times > 0)
	{
		if (!special_permutations(stack, tam_set, &nb_swaps))
		{
			if(stack->size_b > 1 && *(int*)stack->stack_b->content >= pivot)
			{
				push_a(stack, true);
				(*tam_set)--;
			}
			else
			{
				rotate_b(&stack->stack_b, true);
				nb_swaps++;
			}
			pushed_times--;
		}
	}
	return (nb_swaps);
}

void	sort_b(t_list *subdivisions, t_stacks *stack)
{
	int		elem_cola_stack;
	int		tam_set;
	int		pushed_times;
	t_list	*aux;

	pushed_times = 0;
	while (subdivisions)
	{
		tam_set = *((int *)subdivisions->content);
		elem_cola_stack = 0;
		while (stack->size_b >= 1 && tam_set)
		{
			if (elem_cola_stack == 0)
				elem_cola_stack = push_rotate_forwards_b(&tam_set, stack);
			else
				elem_cola_stack = push_rotate_backwards_b(stack, &tam_set,
					elem_cola_stack, pushed_times);
			if (elem_cola_stack == -1)
				elem_cola_stack = 0;
			sort_a(stack);
		}
		aux = subdivisions;
		subdivisions = subdivisions->next;
		ft_lstdelone(aux, free);
	}
}

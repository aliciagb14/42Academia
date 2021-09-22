/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:50:06 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/22 16:05:43 by agonzale         ###   ########.fr       */
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
	while (stack_b != aux || i == 0)
	{
		if (max < (*(int *)stack_b->content))
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
	// printf("\n ---contenido de a---\n");
	// print_stack(stack->stack_a,  stack->size_a);
	// printf("\n ---contenido de b---\n");
	// print_stack(stack->stack_b,  stack->size_b);
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

int	push_rotate_backwards_b(t_stacks *stack,
	int *tam_set, int rotated_times)
{
	int	pivot;

	pivot = get_pivot(stack->stack_b, stack->size_b - *tam_set, stack->size_b);
	// // printf("\n------backwards b--------------\n");
		// // print_stack("\n(stack->stack_b,  stack->size_b);
		// // printf("\n--------------------\n");
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
	// // printf("\n------ despues de backwards b--------------\n");
		// // print_stack("\n(stack->stack_b,  stack->size_b);
		// // printf("\n--------------------\n");
	return (rotated_times);
}

int	push_rotate_forwards_b(int *tam_set, t_stacks *stack)
{
	int	pivot;
	int	nb_swaps;

	nb_swaps = 0;
	// // printf("\n------forwards b--------------\n");
	// // print_stack("\n(stack->stack_b,  stack->size_b);
	// // printf("\n--------------------\n");
	pivot = get_pivot(stack->stack_b, 0, stack->size_b);
	while (*tam_set > stack->sorted_elem_b)
	{
		// printf("Pivote be like: %i; %i, %i\n", pivot, *tam_set, stack->sorted_elem_b);
		if (!special_permutations(stack, tam_set, &nb_swaps))
		{
			if(*(int*)(stack->stack_b->content) >= pivot)
			{
				push_a(stack, true);
				/*// printf("\n------ stack a --------------\n");
				// print_stack("\n(stack->stack_a,  stack->size_a);
				// printf("\n--------------------\n");*/
				(*tam_set)--;
			}
			else
			{
				rotate_b(&stack->stack_b, true);
				nb_swaps++;
			}
		}
	}
	// // printf("\n------despues de forwards b--------------\n");
	// // print_stack("\n(stack->stack_b,  stack->size_b);
	// // printf("\n--------------------\n");
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
		while (stack->size_b > 1 && tam_set)
		{
			if (elem_cola_stack == 0)
				elem_cola_stack = push_rotate_forwards_b(&tam_set, stack);
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

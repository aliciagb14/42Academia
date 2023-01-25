/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:07:13 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 12:43:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Devuelve la posición del numero mas pequeño que encuentra en el stack
*/
int	get_position_smaller_number(t_list *stack_a)
{
	int	min;
	int	min_index;
	int	i;
	t_list *aux;

	i = 0;
	min_index = 0;
	min = *(int*)stack_a->content;
	aux = stack_a;
	while (stack_a != aux || i == 0)
	{
		if (min > *(int*)stack_a->content)
		{
			min = *(int*)stack_a->content;
			min_index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (min_index);
}

void	push_smallest_number(int min_index, t_stacks *stack)
{
	if (min_index >= stack->size_a / 2)
	{
		while (min_index < stack->size_a)
		{
			rev_rotate_a(&stack->stack_a, true);
			min_index++;
		}
	}
	else
	{
		while (min_index)
		{
			rotate_a(stack, true);
			min_index--;
		}
	}
	push_b(stack, true);
}

/*
** Pushear numero mas pequeño a b (x2), llamar a ordenar 3, push 2 a a
**	si hay 4 numeros, pushea un numero solo, si hay 5, pushea 1 numero más
*/
void	five_numbers(t_stacks *stack)
{
	int	min_index;

	while (stack->size_a != 3)
	{
		min_index = get_position_smaller_number(stack->stack_a);
		push_smallest_number(min_index, stack);
	}
	sort_three_numbers(stack);
	while (stack->size_b)
		push_a(stack, true);
}

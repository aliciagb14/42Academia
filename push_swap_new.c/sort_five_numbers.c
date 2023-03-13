/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:07:13 by agonzale          #+#    #+#             */
/*   Updated: 2023/03/13 11:40:53 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Devuelve la posición del numero mas pequeño que encuentra en el stack
*/
int	get_position_smaller_number(t_list *stack_a)
{
	int		min;
	int		min_index;
	int		i;
	t_list	*aux;

	i = 0;
	min_index = 0;
	min = get_biggest_number_a(stack_a);
	aux = stack_a;
	while (aux)
	{
		if (*(int *)aux->content < min)
		{
			min = *(int *)aux->content;
			min_index = i;
		}
		aux = aux->next;
		i++;
	}
	return (min_index);
}

void	push_smallest_number(int min, t_stacks *stack) //int min, int min_index, t_stacks *stack
{
	if (*(int *)stack->stack_a->content == min)
		push_b(stack, true);
	else if (stack->stack_a->pos > stack->size_a / 2)
		rev_rotate_a(&stack->stack_a, true);
	else if (stack->stack_a->pos <= stack->size_a / 2)
		rotate_a(&stack->stack_a, true);
}

/*
** Pushear numero mas pequeño a b (x2), llamar a ordenar 3, push 2 a a
**	si hay 4 numeros, pushea un numero solo, si hay 5, pushea 1 numero más
*/
void	five_numbers(t_stacks *stack)
{
	int	min_index;
	int	min;

	while (stack->size_a > 3)
	{
		min_index = get_position_smaller_number(stack->stack_a);
		min = get_smallest_number_a(stack->stack_a);
		push_smallest_number(min, stack);//min, min_index, stack
	}
	sort_three_numbers(stack->stack_a);
	if (stack->stack_b)
		push_a(stack, true);
	else if (stack->stack_b->next->content > stack->stack_b->content)
		swap_b(&stack->stack_b, true);
	while (stack->stack_b)
		push_a(stack, true);
}

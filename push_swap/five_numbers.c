/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:01:16 by agonzale          #+#    #+#             */
/*   Updated: 2021/07/14 21:53:22 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position_smaller_number(t_list_dbl *stack_a)
{
	int	min;
	int min_index;
	int i;

	i = 0;
	min_index = 0;
	min = stack_a->content;
	while (stack_a->next != NULL)
	{
		if (min > stack_a->next->content)
		{
			min = stack_a->next->content;
			min_index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (min_index);
}
//Rotate el primero se convierte en el ultimo
//Rev_Rotate el ultimo se convierte en el primero
void	push_smallest_number(int min_index, t_stacks *stack) //pusheando b o pulleando a
{
	int	i;

	i = stack->size_a - (stack->size - min_index);
	if(min_index <= stack->size_a/2) //1 <= 5/2, 2 <= 5
	{
		while(i > stack->size_a/2)//4 > 5/2, 3 > 5)2
			rotate_a(stack);
	}
	else
	{
		while (i < stack->size_a/2)
			rev_rotate_a(stack);
	}
	push_a(stack->stack_b);
}
/* pusear numero mas pequeño a b (x2), llamar a ordenar 3, push 2 a a
**	si hay 4 numeros, pushea un numero solo, si hay 5, pushea 1 numero más
**
*/
void	five_numbers(t_stacks *stack)
{
	int min_index;

	get_position_smaller_number(stack->stack_a);
	push_smallest_number(min_index, stack);
	if (stack->size_a == 5)
	{
		get_position_smaller_number(stack->stack_a);
		push_smallest_number(min_index, stack);
	}
	else if (stack->size_a == 3)
		three_numbers(stack->stack_a, stack->size_a);
}
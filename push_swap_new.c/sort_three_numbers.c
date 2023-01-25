/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:20:29 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 13:14:27 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_numbers(t_stacks *stack)
{
	if (stack->size_a <= 2){
		if (!is_sorted(stack->stack_a, stack->size_a) && stack->size_a == 2)
			swap_a(stack->stack_a, true);
		return ;
	}
	while(!is_sorted(stack->stack_a, 3)){
		if (stack->stack_a->content > stack->stack_a->next->content)
			swap_a(stack->stack_a, true);
		if (stack->stack_a->content > stack->stack_a->next->next->content)
			rev_rotate_a(&stack->stack_a, true);
		else if (!is_sorted(stack->stack_a, stack->size_a))
			rotate_a(stack, true);
	}
}

void sort_three_numbers_full_stack(t_stacks *stack)
{
	if (stack->size_a < 2 || is_sorted(stack->stack_a, stack->size_a))
		return ;
	if (stack->size_a == 2 || stack->stack_a->content > stack->stack_a->next->content)
	{
		rotate_a(stack, true);
		swap_a(stack->stack_a, true);
		rev_rotate_a(&stack->stack_a, true);
		if(stack->stack_a->content > stack->stack_a->next->content)
			swap_a(stack->stack_a, true);
	}
}

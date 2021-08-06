/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:06:54 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 14:20:28 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_list_dbl *stack_a, int size_a)
{
	if (size_a <= 2)
	{
		if (!is_sorted(stack_a) && size_a == 2)
			swap_a(stack_a, true);
		return ;
	}
	while (!is_sorted(stack_a))
	{
		if (stack_a->content > stack_a->next->content)
			swap_a(stack_a, true);
		else if (stack_a->content < stack_a->next->content
			&& stack_a->content > stack_a->next->next->content)
			rev_rotate_a(&stack_a, true);
		else if (!is_sorted(stack_a))
			rotate_a(&stack_a, true);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:06:54 by agonzale          #+#    #+#             */
/*   Updated: 2021/07/14 17:45:57 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_list_dbl *stack_a, int size_a)
{
	if (size_a <= 2)
	{
		if (!is_sorted(stack_a) && size_a == 2)
			instruction(swap);
		return ;
	}
	while (!is_sorted(stack_a))
	{
		if (stack_a->content > stack_a->next->content)//[0] > [1] || [0] < [2]
			instruction(swap);
		else if (stack_a->content < stack_a->next->content//[0] < [1] && [0] > [2]
			&& stack_a->content > stack_a->next->next->content)
			instruction(rev_rotate_a);
		else if(!is_sorted(stack_a))
			instruct(rotate_a);
	}
}
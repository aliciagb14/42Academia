/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:20:29 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/06 15:08:13 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_numbers(t_list *stack_a, int size_a)
{
	if (!is_sorted(stack_a, size_a) && size_a == 2)
			swap_a(&stack_a, true);
	if (*(int *)stack_a->content == get_smallest_number_a(stack_a)
		&& *(int *)stack_a->next->content == get_biggest_number_a(stack_a))
	{
		swap_a(&stack_a, true);
		rotate_a(&stack_a, true);
	}
	else if (*(int *)ft_lstlast(stack_a)->content == get_biggest_number_a(stack_a) 
		&& *(int *)stack_a->next->content == get_smallest_number_a(stack_a))
			swap_a(&stack_a, true);
	else if (*(int *)stack_a->next->content == get_biggest_number_a(stack_a) 
		&& *(int *)ft_lstlast(stack_a)->content == get_smallest_number_a(stack_a))
		rev_rotate_a(&stack_a, true);
	else if (*(int *)stack_a->content == get_biggest_number_a(stack_a)
		&& *(int *)stack_a->next->content == get_smallest_number_a(stack_a))
		rotate_a(&stack_a, true);
	else if (*(int *)stack_a->content == get_biggest_number_a(stack_a)
		&& *(int *)ft_lstlast(stack_a)->content == get_smallest_number_a(stack_a))
	{
		swap_a(&stack_a, true);
		rev_rotate_a(&stack_a, true);
	}
}

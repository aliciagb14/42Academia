/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:20:29 by agonzale          #+#    #+#             */
/*   Updated: 2023/04/14 15:45:40 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_list *stack_a)
{
	long int	min;
	long int	max;

	min = get_smallest_number_a(stack_a);
	max = get_biggest_number_a(stack_a);
	if (*(int *)stack_a->content == min
		&& *(int *)stack_a->next->content == max)
	{
		rev_rotate_a(&stack_a, true);
		swap_a(&stack_a, true);
	}
	else if (*(int *)ft_lstlast(stack_a)->content == max
		&& *(int *)stack_a->next->content == min)
		swap_a(&stack_a, true);
	else if (*(int *)stack_a->next->content == max
		&& *(int *)ft_lstlast(stack_a)->content == min)
		rev_rotate_a(&stack_a, true);
	else if (*(int *)stack_a->content == max
		&& *(int *)stack_a->next->content == min)
		rotate_a(&stack_a, true);
	else if (*(int *)stack_a->content == max
		&& *(int *)ft_lstlast(stack_a)->content == min)
	{
		swap_a(&stack_a, true);
		rev_rotate_a(&stack_a, true);
	}
}

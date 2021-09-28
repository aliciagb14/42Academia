/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:28:48 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/28 08:45:44 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:06:54 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/24 14:25:47 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_list_dbl *stack_a, int size_a)
{
	if (size_a <= 2)
	{
		if (!is_sorted(stack_a, size_a) && size_a == 2)
			swap_a(stack_a, true);
		return ;
	}
	while (!is_sorted(stack_a, 3))
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			swap_a(stack_a, true);
		if (*(int *)stack_a->content > *(int *)stack_a->next->next->content)
			rev_rotate_a(&stack_a, true);
		else if (!is_sorted(stack_a, size_a))
			rotate_a(&stack_a, true);
	}
	// //print-stack("\n(stack_a,  size_a);
	// // //printf"\n--------------------\n");
	// // //printf"\n ---nos salimos de ordenar 3 ---\n");
}

void	sort_three_numbers_full_stack_a(t_list_dbl *stack_a, int size)
{
	if (size < 2 || is_sorted(stack_a, size))
		return ;
	if (size == 2
		|| *(int *)stack_a->content > *(int *)stack_a->next->content)
	{
		swap_a(stack_a, true);
		if (is_sorted(stack_a, size))
			return ;
	}
	rotate_a(&stack_a, true);
	swap_a(stack_a, true);
	rev_rotate_a(&stack_a, true);
	if (*(int *)stack_a->content > *(int *)stack_a->next->content)
		swap_a(stack_a, true);
}

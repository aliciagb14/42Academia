/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:47 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/29 20:03:45 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate_a(t_stacks *stack)
{
	if (!stack->stack_a || !stack->stack_a->prev)
		return;
	stack->stack_a = stack->stack_a->prev;
}

void rev_rotate_b(t_stacks *stack)
{
	if (!stack->stack_b || !stack->stack_b->prev)
		return;
	stack->stack_b = stack->stack_b->prev;
}

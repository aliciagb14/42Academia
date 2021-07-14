/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:44 by agonzale          #+#    #+#             */
/*   Updated: 2021/07/03 20:50:14 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//que apunte al siguiente o al anterior el puntero
void	rotate_a(t_stacks *stack)
{
	if (!stack->stack_a || !stack->stack_a->next)
		return ;
	stack->stack_a = stack->stack_a->next;
}

void	rotate_b(t_stacks *stack)
{
	if (!stack->stack_b || !stack->stack_b->next)
		return ;
	stack->stack_b = stack->stack_b->next;
}

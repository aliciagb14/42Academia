/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:59:43 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/20 16:25:32 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_stacks *stack, t_bool print){
	t_list *aux;
	if (!&(stack->stack_a))
		return ;
	aux = stack->stack_a;
	stack->stack_a  = stack->stack_a->next;
	if (stack->stack_a->next == NULL)
		stack->stack_a = aux;
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void rotate_b(t_stacks *stack, t_bool print){
	t_list *aux;
	if (!&(stack->stack_b))
		return ;
	aux = stack->stack_b;
	stack->stack_b  = stack->stack_b->next;
	if (stack->stack_b->next == NULL)
		stack->stack_b = aux;
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}
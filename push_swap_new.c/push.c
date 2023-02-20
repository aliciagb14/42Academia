/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:06:04 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/20 14:45:50 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stack, t_bool print)
{
	t_list	*aux;

	if (!stack->stack_b)
		return ;
	aux = stack->stack_b->next;
	ft_lstadd_front(&stack->stack_a, ft_lstnew(stack->stack_b->content));
	stack->size_a++;
	stack->size_b--;
	if (print)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	//free(stack->stack_b);
	stack->stack_b = aux;
}

void	push_b(t_stacks *stack, t_bool print)
{
	t_list	*aux;

	if (!stack->stack_a)
		return ;
	aux = stack->stack_a->next;
	ft_lstadd_front(&stack->stack_b, ft_lstnew(stack->stack_a->content));
	stack->size_b++;
	stack->size_a--;
	if (print)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	//free(stack->stack_a);
	stack->stack_a = aux;
}

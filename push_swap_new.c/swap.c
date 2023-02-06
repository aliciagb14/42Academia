/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:34:49 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/06 13:10:55 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * intercambia los dos primeros elementos encima del stack a
 * */

void swap_a(t_list **stack_a, t_bool print)
{
	t_list *aux;

	aux = *stack_a;
	if(!stack_a)
		return ;
	if((*stack_a)->next)
	{
		aux = (*stack_a)->next;
		(*stack_a)->next = aux->next;
		ft_lstadd_front(stack_a, aux);
	}
	if (print)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void swap_b(t_list **stack_b, t_bool print)
{
	t_list *aux;

	
	aux = *stack_b;
	if(!stack_b)
		return ;
	if((*stack_b)->next)
	{
		aux = (*stack_b)->next;
		(*stack_b)->next = aux->next;
		ft_lstadd_front(stack_b, aux);
	}
	if (print)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

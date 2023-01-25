/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:34:49 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/24 12:59:38 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_list *stack_a, t_bool print)
{
	t_list *aux;

	aux = stack_a->content;
	stack_a->content = &stack_a->next;
	stack_a->next = aux;
	if (print)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void swap_b(t_list *stack_b, t_bool print)
{
	t_list *aux;

	aux = stack_b->content;
	stack_b->content = &stack_b->next;
	stack_b->next = aux;
	if (print)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

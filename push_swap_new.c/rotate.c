/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:59:43 by agonzale          #+#    #+#             */
/*   Updated: 2023/03/13 14:24:15 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a, t_bool print)
{
	t_list	*act;

	if (!stack_a)
		return ;
	act = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, ft_lstnew(act->content));
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rotate_b(t_list **stack_b, t_bool print)
{
	t_list	*act;

	if (!stack_b)
		return ;
	act = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, ft_lstnew(act->content));
	if (print)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rotate_all(t_list **stack_a, t_list **stack_b, t_bool print)
{
	rotate_a(stack_a, print);
	rotate_b(stack_b, print);
	if (print)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}

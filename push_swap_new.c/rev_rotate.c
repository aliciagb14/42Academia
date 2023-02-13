/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:10:34 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/13 14:19:42 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **stack_a, t_bool print)
{
	t_list	*actual;
	t_list	*anterior;

	if (!(stack_a))
		return ;
	anterior = (*stack_a);
	actual = anterior->next;
	while (actual->next)
	{
		anterior = actual;
		actual = actual->next;
	}
	ft_lstadd_front(stack_a, ft_lstnew(actual->content));
	anterior->next = 0;
	ft_lstdelone(actual, 0);
	if (print)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rev_rotate_b(t_list **stack_b, t_bool print)
{
	t_list	*actual;
	t_list	*anterior;

	if (!(stack_b))
		return ;
	anterior = (*stack_b);
	actual = anterior->next;
	while (actual->next)
	{
		anterior = actual;
		actual = actual->next;
	}
	ft_lstadd_front(stack_b, ft_lstnew(actual->content));
	anterior->next = 0;
	ft_lstdelone(actual, 0);
	if (print)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rev_rotate_all(t_list **stack_a, t_list **stack_b, t_bool print)
{
	rev_rotate_a(stack_a, print);
	rev_rotate_b(stack_b, print);
	if (print)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

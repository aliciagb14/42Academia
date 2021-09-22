/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:47 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/22 11:28:42 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list_dbl **stack_a, t_bool print)
{
	if (!(*stack_a) || !(*stack_a)->prev)
		return ;
	*stack_a = (*stack_a)->prev;
	if (print)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rev_rotate_b(t_list_dbl **stack_b, t_bool print)
{
	if (!(*stack_b) || !(*stack_b)->prev)
		return ;
	*stack_b = (*stack_b)->prev;
	if (print)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

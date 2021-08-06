/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:44 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 13:25:56 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list_dbl **stack_a, t_bool print)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	*stack_a = (*stack_a)->next;
	if (print)
		ft_putstr_fd("ra", STDOUT_FILENO);
}

void	rotate_b(t_list_dbl **stack_b, t_bool print)
{
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	*stack_b = (*stack_b)->next;
	if (print)
		ft_putstr_fd("rb", STDOUT_FILENO);
}

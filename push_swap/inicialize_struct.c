/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:42:00 by agonzale          #+#    #+#             */
/*   Updated: 2021/07/14 11:10:56 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inicialize(t_stacks *stack)
{
	ft_memset(&stack, 0, sizeof(t_stacks));
	stack->size_a = 1;
	stack->size_b = 1;
	if (stack->stack_b == NULL)
	{
		free(stack->stack_a);
		exit(1);
	}
}

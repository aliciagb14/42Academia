/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:40:43 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 14:27:13 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*aux que al inicio sea list, y me voy a mover con el aux,
hasta que aux de next = list*/
t_bool	is_sorted(t_list_dbl *list)
{
	t_list_dbl	*aux;

	if (!list)
		return (0);
	aux = list;
	while (aux->next != list)
	{
		if (((int *)aux->content)[0] >
			((int *)aux->next->content)[0])
			return (false);
		aux = aux->next;
	}
	return (true);
}

t_bool	swap_instr(char *line, t_stacks *stack, t_bool print)
{
	if (!ft_strncmp(line, "sa", 3))
		swap_a(stack->stack_a, print);
	else if (!ft_strncmp(line, "sb", 3))
		swap_b(stack->stack_b, print);
	else if (!ft_strncmp(line, "ss", 3))
	{
		swap_a(stack->stack_a, print);
		swap_b(stack->stack_b, print);
	}
	else
		print = false;
	return (print);
}

t_bool	push_instr(char *line, t_stacks *stack, t_bool print)
{
	if (!ft_strncmp(line, "pa", 3))
		push_a(stack, print);
	else if (!ft_strncmp(line, "pb", 3))
		push_a(stack, print);
	else
		print = false;
	return (print);
}

t_bool	rotate_instr(char *line, t_stacks *stack, t_bool print)
{
	if (!ft_strncmp(line, "ra", 3))
		rotate_a(&stack->stack_a, print);
	else if (!ft_strncmp(line, "rb", 3))
		rotate_b(&stack->stack_b, print);
	else if (!ft_strncmp(line, "rr", 3))
	{
		rotate_a(&stack->stack_a, print);
		rotate_b(&stack->stack_b, print);
	}
	else
		print = false;
	return (print);
}

t_bool	rev_rotate_instr(char *line, t_stacks *stack, t_bool print)
{
	if (!ft_strncmp(line, "rra", 3))
		rev_rotate_a(&stack->stack_a, print);
	else if (!ft_strncmp(line, "rrb", 3))
		rev_rotate_b(&stack->stack_b, print);
	else if (!ft_strncmp(line, "rrr", 3))
	{
		rev_rotate_a(&stack->stack_a, print);
		rev_rotate_b(&stack->stack_b, print);
	}
	else
		print = false;
	return (print);
}

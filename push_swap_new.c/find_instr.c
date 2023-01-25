/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:44:18 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 12:45:07 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	swap_instr(char *line, t_stacks stack, t_bool print)
{
	if (!ft_strncmp(line, "sa", 3))
		swap_a(stack.stack_a, print);
	else if (!ft_strncmp(line, "sb", 3))
		swap_b(stack.stack_b, print);
	else if (!ft_strncmp(line, "ss", 3))
	{
		swap_a(stack.stack_a, print);
		swap_b(stack.stack_b, print);
	}
	else
		print = false;
	return (print);
}

t_bool	push_instr(char *line, t_stacks stack, t_bool print)
{
	if (!ft_strncmp(line, "pa", 3))
		push_a(&stack, print);
	else if (!ft_strncmp(line, "pb", 3))
		push_b(&stack, print);
	else
		print = false;
	return (print);
}

t_bool	rotate_instr(char *line, t_stacks stack, t_bool print)
{
	if (!ft_strncmp(line, "ra", 3))
		rotate_a(&stack, print);
	else if (!ft_strncmp(line, "rb", 3))
		rotate_b(&stack, print);
	else if (!ft_strncmp(line, "rr", 3))
	{
		rotate_a(&stack, print);
		rotate_b(&stack, print);
	}
	else
		print = false;
	return (print);
}

t_bool	reverse_instr(char *line, t_stacks stack, t_bool print)
{
	if (!ft_strncmp(line, "rra", 4))
		rev_rotate_a(&stack.stack_a, print);
	else if (!ft_strncmp(line, "rrb", 4))
		rev_rotate_b(&stack.stack_b, print);
	else if (!ft_strncmp(line, "rrr", 4))
		rev_rotate_all(&stack.stack_a, &stack.stack_b, print);
	else
		print = false;
	return (print);
}

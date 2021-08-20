/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:59:35 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/16 13:02:42 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	execute_instr(char *line, t_stacks *stack)
{
	if (!ft_strncmp(line, "sa", 3))
		swap_a(stack->stack_a, false);
	else if (!ft_strncmp(line, "sb", 3))
		swap_b(stack->stack_b, false);
	else if (!ft_strncmp(line, "ss", 3))
	{
		swap_a(stack->stack_a, false);
		swap_b(stack->stack_b, false);
	}
	else if (!ft_strncmp(line, "pa", 3) && stack->size_b >= 1)
		push_a(stack, false);
	else if (!ft_strncmp(line, "pb", 3) && stack->size_a >= 1)
		push_b(stack, false);
	else
		execute_more_instr(line, stack);
}

void execute_more_instr(char *line, t_stacks *stack)
{
	if (!ft_strncmp(line, "ra", 3))
		rotate_a(&stack->stack_a, false);
	else if (!ft_strncmp(line, "rb", 3))
		rotate_b(&stack->stack_b, false);
	else if (!ft_strncmp(line, "rr", 3))
	{
		rotate_a(&stack->stack_a, false);
		rotate_b(&stack->stack_b, false);
	}
	else if (!ft_strncmp(line, "rra", 3))
		rev_rotate_a(&stack->stack_a, false);
	else if (!ft_strncmp(line, "rrb", 3))
		rev_rotate_b(&stack->stack_b, false);
	else if (!ft_strncmp(line, "rrr", 3))
	{
		rev_rotate_a(&stack->stack_a, false);
		rev_rotate_b(&stack->stack_b, false);
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
}

void	read_input(t_stacks *stack)
{
	int		gnl_ctrl;
	char	*buffer;

	gnl_ctrl = get_next_line(STDIN_FILENO, &buffer);
	while (gnl_ctrl == 1)
	{
		execute_instruction(buffer, stack);
		free(buffer);
		gnl_ctrl = get_next_line(STDIN_FILENO, &buffer);
	}
	if (buffer)
		free(buffer);
	if (gnl_ctrl == -1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
}
*/
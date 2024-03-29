/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:07:51 by agonzale          #+#    #+#             */
/*   Updated: 2023/04/14 15:38:52 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valgrind(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	atexit(valgrind);
	t_stacks	stack;

	ft_memset(&stack, 0, sizeof(t_stacks));
	if (argc < 2)
		return (0);
	read_input(&stack.stack_a, argv);
	stack.size_a = ft_lstsize(stack.stack_a);
	stack.sorted_elem_a = 0;
	stack.size_b = ft_lstsize(stack.stack_b);
	if (!is_sorted(stack.stack_a, stack.size_a))
	{
		if (stack.size_a <= 3)
			sort_three_numbers(stack.stack_a);
		else if (stack.size_a <= 5)
			five_numbers(&stack);
		else if (stack.size_a <= 100)
			sort_max_10_nbr(&stack);
		else
			radix_sort(&stack);
	}
	// free(stack.stack_a);
	// free(stack.stack_b);
	exit(EXIT_SUCCESS);
	return (0);
}

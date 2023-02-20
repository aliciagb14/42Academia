/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:07:51 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/20 14:49:39 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valgrind(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	// atexit(valgrind);

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
		else if (stack.size_a <= 45)
			sort_max_10_nbr(&stack);
		else
			radix_sort(&stack);
	}
	//print_stack(stack.stack_a, stack.size_a);
	//ft_lstclear(&stack.stack_a, free);
	//ft_lstclear(&stack.stack_b, free);
	exit(EXIT_SUCCESS);
	return (0);
}

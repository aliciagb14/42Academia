/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:07:51 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 12:32:02 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "push_swap.h"


void	valgrind(void)
{
	system("leaks push_swap");
}


int main(int argc, char **argv){
	// atexit(valgrind);
	t_stacks stack;
	if (argc < 2)
		return (0);
	read_input(&stack.stack_a, argv);
	stack.size_a = ft_lstsize(stack.stack_a);
	stack.sorted_elem_a = 0;
	stack.size_b = ft_lstsize(stack.stack_b);
	
	if (stack.size_a <= 3)
		sort_three_numbers(&stack);
	else if (stack.size_a <= 5)
		five_numbers(&stack);
	else
		sort_a(&stack);
	ft_lstclear(&stack.stack_a, free);
	ft_lstclear(&stack.stack_b, free);
}*/
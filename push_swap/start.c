/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:08:21 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/28 12:31:22 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(t_list_dbl **list, int aux, int j, char *current_argv)
{
	t_bool	is_error;

	is_error = false;
	if (current_argv[aux] == '-')
	{
		if (j - aux >= 11 && ft_strncmp(&current_argv[aux],
				"-2147483648", 12) > 0)
			is_error = true;
	}
	else
	{
		if (current_argv[aux] == '+')
			aux++;
		if (j - aux >= 10 && ft_strncmp(&current_argv[aux],
				"2147483647", 11) > 0)
			is_error = true;
	}
	if (is_elem_dup(list[0], &current_argv[aux]))
		is_error = true;
	if (is_error)
	{
		ft_putstr_fd("Error", STDERR_FILENO);
		ft_lstdbl_clear(list, free);
		exit(-1);
	}
}

void	check_sign_and_digits(t_list_dbl **list, char **argv, int i, int j)
{
	if (!ft_isdigit(argv[i][j]))
	{
		ft_putstr_fd("KO", STDERR_FILENO);
		ft_lstdbl_clear(list, free);
	}
}

void	input(t_list_dbl **list, char **argv)
{
	int	aux;
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			aux = j;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			while (argv[i][j] && !ft_isspace(argv[i][j]))
			{
				check_sign_and_digits(list, argv, i, j);
				j++;
			}
			check_error(list, aux, j, argv[i]);
			ft_lstdbl_add_back(list,
				ft_lstdbl_new(get_number(ft_atoi(&argv[i][aux]))));
		}
		i++;
	}
	circular_fun(*list);
}

void	valgrind(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	// atexit(valgrind);
	if (argc < 2)
		return (0);
	ft_memset(&stack, 0, sizeof(t_stacks));
	input(&stack.stack_a, argv);
	stack.size_a = ft_lstdbl_size(stack.stack_a);
	stack.sorted_elem_a = 0;
	stack.size_b = ft_lstdbl_size(stack.stack_b);
	if (stack.size_a <= 3)
		sort_three_numbers(stack.stack_a, stack.size_a);
	else if (stack.size_a <= 5)
		five_numbers(&stack);
	else
		sort_a(&stack);
	print_stack(stack.stack_a,  stack.size_a);
	ft_lstdbl_clear(&stack.stack_a, free);
	ft_lstdbl_clear(&stack.stack_b, free);
	return (0);
}

/*
** COMPROBACIONES PARA EL MAIN DE INSTRUCCIONES
**
**	// //print-stack("\n(stack.stack_a,  stack.size_a);
**	// // //printf"\n--------------------\n");
**	// //print-stack("\n(stack.stack_b,  stack.size_b);
**	push_b(&stack, true);
**	push_b(&stack, true);
**	push_b(&stack, true);
**	rev_rotate_a(&stack.stack_a, true);
**	rev_rotate_b(&stack.stack_b, true);
**	rev_rotate_a(&stack.stack_a, true);
**	swap_a(stack.stack_a, true);
**	swap_b(stack.stack_b, true);
**	// // //printf"\n fin \n");
**	// //print-stack("\n(stack.stack_a,  stack.size_a);
**	// // //printf"\n--------------------\n");
**	// //print-stack("\n(stack.stack_b, stack.size_b);
*/
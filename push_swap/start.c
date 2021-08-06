/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:08:21 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 12:57:25 by agonzale         ###   ########.fr       */
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
				if (!ft_isdigit(argv[i][j]))
				{
					ft_putstr_fd("KO", STDERR_FILENO);
					ft_lstdbl_clear(list, free);
				}
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

int	main(int argc, char **argv)
{
	t_stacks	stack;

	ft_inicialize(&stack);
	if (argc < 2)
		return (0);
	input(&stack.stack_a, argv);
	stack.size_a = ft_lstdbl_size(stack.stack_a) - 1;
	stack.size_b = ft_lstdbl_size(stack.stack_b) - 1;
}

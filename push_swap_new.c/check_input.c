/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:34:28 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/20 10:22:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_input(t_list **list, char **argv)
{
	int	i;
	int	j;
	int	aux;

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
				check_error_numbers(*list, argv, i, j);
				j++;
			}
			check_error_line(*list, aux, j, argv[i]);
			ft_lstadd_back(list,
				ft_lstnew(get_number(ft_atoi(&argv[i][aux]))));
		}
		i++;
	}
}

void	check_error_line(t_list *list, int aux, int j, char *current_argv)
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
	if (is_elem_dup(list, &current_argv[aux]))
	{
		is_error = true;
		ft_putstr_fd("Elements duplicated\n", STDOUT_FILENO);
	}
	if (is_error)
	{
		ft_putstr_fd("Number out of range", STDERR_FILENO);
		exit(-1);
	}
}

void	check_error_numbers(t_list *list, char **argv, int i, int j)
{
	if (!ft_isdigit(argv[i][j]))
	{
		ft_putstr_fd("KO", STDERR_FILENO);
		ft_lstclear(&list, free);
	}
}

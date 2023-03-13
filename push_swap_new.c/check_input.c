/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:34:28 by agonzale          #+#    #+#             */
/*   Updated: 2023/03/13 11:04:14 by agonzale         ###   ########.fr       */
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

// static void	ft_free_matrix(char **matrix)
// {
// 	int	i;

// 	i = -1;
// 	while (matrix[++i])
// 		;
// 	while (--i >= 0)
// 		free(matrix[i]);
// 	free(matrix);
// }

// static int	ft_matrix_len(char **matrix)
// {
// 	int	i;

// 	i = 0;
// 	while (matrix[i])
// 		i++;
// 	return (i);
// }

// int	ft_nbr_count(int argc, char **argv)
// {
// 	char	**numbers;
// 	int		nbr_count;
// 	int		i;

// 	i = 1;
// 	numbers = NULL;
// 	nbr_count = 0;
// 	while (i < argc)
// 	{
// 		numbers = ft_split(argv[i], ' ');
// 		nbr_count = nbr_count + ft_matrix_len(numbers);
// 		ft_free_matrix(numbers);
// 		i++;
// 	}
// 	return (nbr_count);
// }

// long	*store_numbers(t_stacks *stacks, int argc, char **argv)
// {
// 	long	*numbers;

// 	int k = 1;
// 	int i = 0;
// 	int j;
// 	stacks->nbr_count = ft_nbr_count(argc, argv);
// 	numbers = (long *)malloc(sizeof(long) * stacks->nbr_count);
// 	if (!numbers)
// 		ft_putstr_fd("Malloc KO.\n", STDOUT_FILENO);
// 	while (i < stacks->nbr_count)
// 	{
// 		stacks->matrix = ft_split(argv[k], ' ');
// 		if (stacks->matrix == NULL)
// 			ft_putstr_fd("Malloc KO.\n", STDOUT_FILENO);
// 		j = 0;
// 		while (stacks->matrix && stacks->matrix[j] != NULL)
// 		{
// 			if (ft_strlen(stacks->matrix[j]) <= 12)
// 				numbers[i++] = ft_atoi(stacks->matrix[j++]);//ft_atoi_long(stacks->matrix[j++]);
// 			else
// 				ft_putstr_fd("Number out of range.\n", STDOUT_FILENO);
// 		}
// 		ft_free_matrix(stacks->matrix);
// 		k++;
// 	}
// 	return (numbers);
// }

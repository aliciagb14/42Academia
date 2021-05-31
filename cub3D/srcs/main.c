/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:56:47 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 19:56:53 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	main(int argc, char const *argv[])
{
	t_bool				screenshot;
	t_program_params	program_params;

	screenshot = false;
	initialice_program_params(&program_params);
	if (check_arguments(&screenshot, argc, (char **)argv))
	{
		if (get_cub_data(&program_params, argv[1]))
			start_game(program_params, screenshot);
		else
		{
			free_program_params(program_params);
			if (program_params.map)
				free_map(program_params.map);
		}
	}
	return (0);
}

/*
** 		Checks the variadic arguments for the first and second arguments
*/

t_bool	check_arguments(t_bool *screenshot, int argc, char **argv)
{
	if (argc == 1)
		return (print_error("Missing argument"));
	else
	{
		if (argc == 3)
		{
			if (ft_strlen(argv[2]) == 6 && !ft_strncmp(argv[2], "--save", 6))
				*screenshot = true;
			else
				return (print_error("Second argument wrong"));
		}
		if (ft_strlen(argv[1]) <= 4)
			return (print_error("Wrong name of file given as argument"));
		else if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
			return (print_error("Wrong extension of file given as argument"));
	}
	return (true);
}

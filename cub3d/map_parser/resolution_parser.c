/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:30:33 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/13 20:31:43 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		handle_resolution(char *line, t_error error, t_data_params *info)
{
	if (info->resolution_x == 0 || info->resolution_y == 0)
	{
		info->resolution_x = ft_atoi(line);
		while(ft_isdigit(*line))
			line++;
		while (ft_isspace(*line))
			line++;
		info->resolution_y = ft_atoi(line);
		while(ft_isdigit(*line))
			line++;
		if (*line)
			return (error.error_id = wrong_input);
		else
			return (0);
	}
	else
	{
		ft_putstr_fd("Resolution alredy added.\n", 1);
		return (error.error_id = repeated_resolution_def);
	}
}

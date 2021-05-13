/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:26:56 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/13 20:39:14 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		handle_colour(char *line, t_error error, int *lista_colors)
{
	int colour[3];

	if (!check_color(line, error))
	{
		ft_putstr_fd("Invalid color definition", 1);
		return (error.error_id = wrong_colour);
	}
	colour[0] = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	colour[1] = ft_atoi(++line);
	while (ft_isdigit(*line))
		line++;
	colour[2] = ft_atoi(++line);
	while (ft_isdigit(*line))
		line++;
	if (colour[0] > 255 || colour[1] > 255 || colour[2] > 255)
		return (error.error_id = wrong_colour);
	*lista_colors = create_trgb(0, colour[0], colour[1], colour[2]);
	return (1);
}

int		check_color(char *line, t_error error)
{
	int comma;

	comma = 0;
	while (*line == ',' || ft_isdigit(*line))
	{
		if (*line == ',')
			comma++;
		line++;
	}
	if (comma > 2 || !ft_isdigit(*(line - 1)))
	{
		ft_putstr_fd("Invalid format color", 1);
		return (error.error_id = invalid_format_color);
	}
	return (1);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
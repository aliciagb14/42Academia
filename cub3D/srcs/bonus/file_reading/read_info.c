/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:30:39 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 18:30:43 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**		Reads the window resolution definition and
**		stores it in the program params
*/

t_bool	read_resolution(char *line, t_program_params *program_params)
{
	t_bool	correct;

	correct = true;
	while (*line == ' ')
		line++;
	program_params->window_width = ft_atoi(line);
	if (!program_params->window_width)
		return (print_error("Window width must be greater than 0"));
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (!(ft_isdigit(*line) && *(line - 1) == ' '))
		return (print_error("Only one number defined in resolution"));
	program_params->window_height = ft_atoi(line);
	if (!program_params->window_height)
		return (print_error("Window height must be greather than 0"));
	while (ft_isdigit(*line))
		line++;
	if (!(ft_isdigit(*(line - 1)) && *line == '\0'))
		return (print_error("Invalid character in resolution definition"));
	return (correct);
}

/*
**		Reads a path, checks wether the extension is .xpm or .XPM and
**		stores it in a pointer given as parameter
*/

t_bool	read_path(char *line, char **path_to_texture)
{
	t_bool	correct;
	int		path_length;

	correct = true;
	while (*line == ' ')
		line++;
	path_length = ft_strlen(line);
	*path_to_texture = (char *)malloc(sizeof(char) * (path_length + 1));
	if (!(*path_to_texture))
		return (print_error("Error while allocating memory"));
	ft_strlcpy(*path_to_texture, line, path_length + 1);
	if (ft_strncmp("XPM", &(*path_to_texture)[path_length - 3], 3)
	&& ft_strncmp("xpm", &(*path_to_texture)[path_length - 3], 3))
		return (print_error_line("Wrong extension of file", line));
	return (correct);
}

/*
**		Reads a color definition and stores it formated in an int
*/

t_bool	read_color(char *line, int *color)
{
	int		colors[3];

	while (*line == ' ')
		line++;
	if (!check_color_characters(line))
		return (print_error_line("Invalid char in color definition", line));
	colors[0] = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	colors[1] = ft_atoi(++line);
	while (ft_isdigit(*line))
		line++;
	colors[2] = ft_atoi(++line);
	while (ft_isdigit(*line))
		line++;
	if (colors[0] > 255 || colors[1] > 255 || colors[2] > 255)
		return (print_error("Incorrect rgb values, max should be 255"));
	*color = create_trgb(0, colors[0], colors[1], colors[2]);
	return (true);
}

/*
**		Checks there are only numbers and commas
*/

t_bool	check_color_characters(char *line)
{
	int	commas;

	commas = 0;
	while (*line == ',' || ft_isdigit(*line))
	{
		if (*line == ',')
			commas++;
		line++;
	}
	if (*line || commas > 2 || !ft_isdigit(*(line - 1)))
		return (false);
	return (true);
}

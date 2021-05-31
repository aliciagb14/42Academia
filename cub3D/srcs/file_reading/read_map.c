/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:54:01 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 20:43:38 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

/*
**		Avoids empty lanes, saves the map and checks for anything wrong
*/

t_bool	read_map(t_list *line_elem, char *line,
t_program_params *program_params)
{
	char	**map;

	while (line_elem && *line == '\0')
	{
		line_elem = line_elem->next;
		line = NULL;
		if (line_elem)
			line = (char *)line_elem->content;
	}
	if (line_elem == NULL)
		return (print_error("There is no map"));
	else if (search_identifier(line))
		return (print_error("Repeated information"));
	program_params->map = (char **)ft_calloc(
			get_map_height(line_elem) + 1, sizeof(char *));
	map = program_params->map;
	while (line_elem)
	{
		*map = (char *)ft_strdup(line_elem->content);
		(map)++;
		line_elem = line_elem->next;
	}
	if (!check_map_characters(program_params->map, 0, 0, program_params))
		return (false);
	return (true);
}
/*
**		Iterates through all the map characters checking for wrong characters,
**		duplicated player coordinates characters (N, S, E, W) and walls
*/

t_bool	check_map_characters(char **map, int y, int x,
t_program_params *params)
{
	char	c;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (!set_player_parameters(c, y, x, params))
					return (print_error_map(
							"At least 2 player chars found (N,S,E,W)", y, x));
			}
			else if (c != '0' && c != '1' && c != '2' && c != ' ')
				return (print_error_map("Wrong char found in the map", y, x));
			if (!map_is_closed(map, y, x))
				return (print_error_map("Map not closed by walls", y, x));
			x++;
		}
		y++;
	}
	if (params->player_angle == -1)
		return (print_error("Player angle and position not defined"));
	return (true);
}

/*
**		Receives a list of strings containing the map and a coordinate
**		If the char in the coordinates is not a wall or a space checks
**		the adjacents tiles, if it founds an space returns false
*/

t_bool	map_is_closed(char **map, int y, int x)
{
	int	top_line;
	int	down_line;

	top_line = 0;
	down_line = 0;
	if (map[y][x] != '1' && map[y][x] != ' ')
	{
		if (y == 0 || map[y + 1] == NULL
			|| x == 0 || map[y][x + 1] == '\0')
			return (false);
		while (map[y - 1][top_line] && map[y + 1][down_line])
		{
			top_line++;
			down_line++;
		}
		if (top_line < x || down_line < x)
			return (false);
		if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' ||
		map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
			return (false);
	}
	return (true);
}

/*
**		Sets the player coordinates and angle
*/

t_bool	set_player_parameters(char angle_char, int y, int x,
t_program_params *params)
{
	if (params->player_angle != -1)
		return (false);
	params->player_y = y;
	params->player_x = x;
	if (angle_char == 'N')
		params->player_angle = PI / 2;
	else if (angle_char == 'S')
		params->player_angle = (3 * PI) / 2;
	else if (angle_char == 'E')
		params->player_angle = 0;
	else
		params->player_angle = PI;
	return (true);
}

/*
**		Returns the amount of lines of the map
*/

int	get_map_height(t_list *line)
{
	int	i;

	i = 0;
	while (line)
	{
		i++;
		line = line->next;
	}
	return (i);
}

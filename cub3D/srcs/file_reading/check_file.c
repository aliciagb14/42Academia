/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:02:26 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 20:45:40 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "cub3d.h"
#include "libft.h"

/*
**			Saves the file content and search for the required information
*/

t_bool	get_cub_data(t_program_params *program_params,
const char *file_path)
{
	t_list	*file_content;
	t_bool	info_id_list[8];

	file_content = NULL;
	if (!(save_file_lines(&file_content, open(file_path, O_RDONLY))))
		return (false);
	initialice_info_ids(info_id_list);
	if (!read_file_lines(file_content, program_params, 0, info_id_list))
	{
		ft_lstclear(&file_content, free);
		return (false);
	}
	ft_lstclear(&file_content, free);
	return (true);
}

/*
**			Stores all the .cub file lines in an allocated struct
*/

t_bool	save_file_lines(t_list **file_content, int fd)
{
	t_list	*actual_line;
	char	*aux;
	int		result;

	if (fd < 0)
		return (print_error("Couldn't open the file"));
	get_next_line(fd, &aux);
	*file_content = ft_lstnew(aux);
	actual_line = *file_content;
	result = get_next_line(fd, &aux);
	while (result == 1)
	{
		actual_line->next = ft_lstnew(aux);
		actual_line = actual_line->next;
		result = get_next_line(fd, &aux);
	}
	if (result == -1)
	{
		ft_lstclear(file_content, free);
		return (print_error("Error while reading the .cub file"));
	}
	else
		actual_line->next = ft_lstnew(aux);
	return (true);
}

/*
**			Iterates through the file lines searching for each element
**			identifier, checking there are no repeated or wrong identifiers
**			and saving their information
*/

t_bool	read_file_lines(t_list *line_elem,
t_program_params *program_params, t_info_id info_id, t_bool info_id_list[8])
{
	char	*line;

	line = (char *)line_elem->content;
	while (line_elem && !check_info_ids(info_id_list))
	{
		line = (char *)line_elem->content;
		if (*line)
		{
			info_id = search_identifier(line);
			if (info_id)
			{
				if (info_id_list[info_id - 1] == true)
					return (print_error_line("Parameter repeated", line));
				info_id_list[info_id - 1] = true;
			}
			else
				return (print_error_line("Wrong identifier", line));
			if (!get_info(info_id, line, program_params))
				return (false);
		}
		line_elem = line_elem->next;
	}
	if (!check_info_ids(info_id_list) || !line_elem)
		return (print_error("Missing parameter in .cub file"));
	return (read_map(line_elem, line_elem->content, program_params));
}

/*
**			Checks the info id and calls the appropiate function
*/

t_bool	get_info(t_info_id info_id, char *line, t_program_params *params)
{
	if (info_id == id_resolution)
		return (read_resolution(line + 2, params));
	else if (info_id == id_path_north)
		return (read_path(line + 3, &(params->path_north_texture)));
	else if (info_id == id_path_south)
		return (read_path(line + 3, &(params->path_south_texture)));
	else if (info_id == id_path_west)
		return (read_path(line + 3, &(params->path_west_texture)));
	else if (info_id == id_path_east)
		return (read_path(line + 3, &(params->path_east_texture)));
	else if (info_id == id_path_sprite)
		return (read_path(line + 2, &(params->path_sprite_texture)));
	else if (info_id == id_color_floor)
		return (read_color(line + 2, &params->floor_color));
	else if (info_id == id_color_ceilling)
		return (read_color(line + 2, &params->ceilling_color));
	return (print_error("Undefined error"));
}

/*
**			Compares the first charcters of the line with every identifier
**			and returns the correct identifier id
*/

t_info_id	search_identifier(char *line)
{
	t_info_id	id;

	id = 0;
	if (ft_strncmp(line, "R ", 2) == 0)
		id = id_resolution;
	else if (ft_strncmp(line, "NO ", 3) == 0)
		id = id_path_north;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		id = id_path_south;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		id = id_path_west;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		id = id_path_east;
	else if (ft_strncmp(line, "S ", 2) == 0)
		id = id_path_sprite;
	else if (ft_strncmp(line, "F ", 2) == 0)
		id = id_color_floor;
	else if (ft_strncmp(line, "C ", 2) == 0)
		id = id_color_ceilling;
	return (id);
}

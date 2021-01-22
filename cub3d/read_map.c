/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:50:55 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/19 00:11:47 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_args(int argc, char **argv)
{
	if (argc < 3)
		ft_putstr_fd("No input files.\n", 1);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		ft_putstr_fd("Error in the second argument.\n", 1);
	if (argc > 3)
		ft_putstr_fd("Too much arguments.\n", 1);
	if (ft_strncmp(argv[1], ".cub", 5))
		ft_putstr_fd("Error in the name of the file.\n", 1);
	exit(-1);
}

int		handle_resolution(char *line, t_error error, t_data *info)
{
	if (info->resolution_x == 0 && info->resolution_y == 0)
	{
		if (!(info->resolution_x = ft_atoi(line)))
			return (error.error_id = wrong_resolution_x);
		else
		{
			info->resolution_x = ft_atoi(line);
			while (ft_isspace(*line + 1))
			{
				if (!(info->resolution_y = ft_atoi(line + 1)))
					return (error.error_id = wrong_resolution_y);
				else
					info->resolution_y = ft_atoi(line + 1);
			}
		}
	}
	else
	{
		ft_putstr_fd("Resolution alredy added.\n", 1);
		return (error.error_id = repeated_resolution_def);
	}
	return (0);
}

int		handle_colour(char *line, t_error error, int *listacolors)
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
	colour[1] = ft_atoi(line++);
	while (ft_isdigit(*line))
		line++;
	colour[2] = ft_atoi(line++);
	while (ft_isdigit(*line))
		line++;
	if (colour[0] > 255 || colour[1] > 255 || colour[2] > 255)
		return (error.error_id = wrong_colour);
	*listacolors = create_trgb(0, colour[0], colour[1], colour[2]);
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

void	read_file(char *path, t_data *info)
{
	int		fd;
	t_error error;

	ft_memset(info, 0, sizeof(t_error_number));
	if ((fd = open(path, O_RDONLY)) == -1)
		error.error_id = cant_open;
}

void	get_info_map(char *line, t_error error, t_data *info) //t_gnl_buffer *buffer
{
	if (!ft_strncmp(line, "R ", 2))
		handle_resolution(line + 2, error, info);
	else if (!ft_strncmp(line, "C ", 2))
		handle_colour(line + 2, error, &info->ceiling);
	else if (!ft_strncmp(line, "F ", 2))
		handle_colour(line + 2, error, &info->floor);
	/*else if (!ft_strncmp(line, "NO ", 3))
		handle_texture(line + 3, error, &info->north);
	else if (!ft_strncmp(line, "SO ", 3))
		handle_texture(line + 3, error, &info->south);
	else if (!ft_strncmp(line, "WE ", 3))
		handle_texture(line + 3, error, &info->west);
	else if (!ft_strncmp(line, "EA ", 3))
		handle_texture(line + 3, error, &info->east);
	else if (ft_isdigit(*line) || *line == ' ') empieza a leer el mapa
		handle_map(buffer, error, info);*/
	else
		return (error.error_id = wrong_input);
}

int		main(int argc, char **argv)
{
	t_data *info;
	t_error error;
	char *line;
	handle_args(argc, argv);
	ft_memset(&info, 0, sizeof(t_data));
	read_file(argv[1], info);
	get_info_map(line, error, info);
}

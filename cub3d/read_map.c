/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:50:55 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/13 20:39:25 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*tengo que poner argv[1][ft_strlen(argv[1]) - 4] 
ya que argv[][] el primer [] indica el argumento que pilla 
y el segundo [] la posicion a la que apunta el puntero*/
void	handle_args(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr_fd("Too few arguments.\n", 1);
	else if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5))
		ft_putstr_fd("Error in the name of the file.\n", 1);
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		ft_putstr_fd("Error in the second argument.\n", 1);
	else if (argc > 3)
		ft_putstr_fd("Too many arguments.\n", 1);
	//cambiar error: exit 
}

void	read_file(char *path, t_data_params *info)
{
	int		fd;
	t_error error;
	t_gnl_buffer *buffer;
	t_gnl_buffer *aux;

	ft_memset(info, 0, sizeof(t_data_params));
	ft_memset(&error, 0, sizeof(t_error));
	buffer = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		error.error_id = cant_open;
	gnl_buffer(fd, 0, &buffer);
	aux = buffer;
	while (aux)
	{
		get_info_map(aux->line, error, info);
		error.line += 1; // Indica la linea del mapa que se está leyendo, para imprimir el mensaje de error;
		error.error_id = 0;
		aux = aux->next;
	}
	//free_gnl_buffer(buffer, true);
	//check_all(info); //Comprobar que tienes todos los datos!
}
/*
void check_all(t_data *info)
{
	if (&info->resolution_x == 0)

}*/

int return_line(char *line)
{
	int i;
	int contlines;

	i = 0;
	contlines = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			contlines++;
			return (1);
		}
		i++;
	}
	return contlines;
}

void	get_info_map(char *line, t_error error, t_data_params *info, t_gnl_buffer *buffer)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		handle_resolution(line + 2, error, info);
	else if (ft_strncmp(line, "C ", 2) == 0)
		handle_colour(line + 2, error, &info->ceiling_color);
	else if (ft_strncmp(line, "F ", 2) == 0)
		handle_colour(line + 2, error, &info->floor_color);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		handle_texture(line + 3, error, &info->north_texture);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		handle_texture(line + 3, error, &info->south_texture);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		handle_texture(line + 3, error, &info->west_texture);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		handle_texture(line + 3, error, &info->east_texture);
	else if (ft_isdigit(*line) || *line == ' ') //empieza a leer el mapa
		handle_map(buffer, error, info);
	else
		error.error_id = wrong_input;
}
/*
int check_map(char *line, t_error error)
{

}*/

int		main(int argc, char **argv)
{
	t_data_params info;
	t_error error;
	char *line;
	handle_args(argc, argv);
	read_file(argv[1], &info);
	get_info_map(line, error, &info);
	//if argc == 3 llamar a la funcion de captura de pantalla

}

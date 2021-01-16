/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:51:26 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/16 13:11:36 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.141592
# include <fcntl.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
//# include <mlx.h>
# include <math.h>
# include <time.h>

typedef enum s_error_number
{
	cant_open,
	wrong_file,
	wrong_input,
	repeated_resolution_def,
	wrong_resolution_x,
	wrong_resolution_y
} 			t_error_number;

typedef struct s_error
{
	t_error_number error_id;
	int		row;
	int		column;
}			t_error;

typedef struct s_texture
{
	
}			t_texture;

typedef struct s_data
{
	int		resolution_x;
	int		resolution_y;
	int		floor;
	int		ceiling;
	t_texture north;
	t_texture south;
	t_texture west;
	t_texture east;
}			t_data;
/*
typedef struct s_gnl_buffer
{
	
}	t_gnl_buffer;*/

void get_info_map(char *line, t_error error, t_data *info);
void read_file(char *path, t_data *info);
int get_resolution(char *line, t_error error, t_data *info);
void handle_args(int argc, char **argv);
#endif
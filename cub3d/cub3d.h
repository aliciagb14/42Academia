/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:51:26 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/13 20:38:47 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
//# include <mlx.h>
# include <math.h>
# include <string.h>

typedef enum s_error_number
{
	cant_open = 1,
	wrong_file,
	wrong_input,
	repeated_resolution_def,
	wrong_resolution_x,
	wrong_resolution_y,
	repeated_ceiling_def,
	repeated_floor_def,
	wrong_colour,
	invalid_format_color
} 			t_error_number;

typedef struct s_error
{
	t_error_number error_id;
	int		row;
	int		column;
	int		line;
}			t_error;

typedef struct s_texture
{
	int	width;
	int height;
}			t_texture;

typedef struct s_colour
{
	int r;
	int g;
	int b;
}			t_colour;

typedef struct s_data_params
{
	int		resolution_x;
	int		resolution_y;
	int		floor_color;
	int		ceiling_color;
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
}			t_data_params;

typedef struct s_image_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int 	line_len;
	int		endian;
}				t_image_data;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image_data		*img;
}				t_mlx;

void	get_info_map(char *line, t_error error, t_data_params *info, t_gnl_buffer *buffer);
void	read_file(char *path, t_data_params *info);
int		handle_resolution(char *line, t_error error, t_data_params *info);
void	handle_args(int argc, char **argv);
int		handle_colour(char *line, t_error error, int *listacolors);
int		check_color(char *line, t_error error);
int		create_trgb(int t, int r, int g, int b);
char	*gnl_error(char *stock);
int		newline_check(char *stock, int read_size);
char	*buf_join(char *stock, char *buf);
char	*stock_trim(char *stock);
char	*get_line(char *stock);
#endif
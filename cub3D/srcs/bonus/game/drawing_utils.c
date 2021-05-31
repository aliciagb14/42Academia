/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:55:11 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 13:55:15 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**			Receives a struct of coordinates and renders a square with the
**			given color in the given image
*/

#include "cub3d.h"

void	draw_square(t_coords coords, int color, t_data *img)
{
	int	x;
	int	y;

	x = coords.start_x;
	while (x <= coords.end_x)
	{
		y = coords.start_y;
		while (y <= coords.end_y)
		{
			put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}

/*
**			Receives 4 parameters each one as a corner of a square and
**			returns a structure with them stored in it
*/

t_coords	get_coords_struct(int x_start, int y_start, int x_end, int y_end)
{
	t_coords	coords;

	coords.start_x = x_start;
	coords.start_y = y_start;
	coords.end_x = x_end;
	coords.end_y = y_end;
	return (coords);
}

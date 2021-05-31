/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_get_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:53:29 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 13:54:51 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**		Receives coordinates, a pointer to an image data and a pixel
**		It places the pixel in the img data at the coordinates
*/

void	put_pixel(t_data *image_data, int x, int y, int pixel)
{
	char	*dst;

	dst = image_data->addr
		+ (y * image_data->line_length + x * (image_data->bits_per_pixel / 8));
	*(int *)dst = pixel;
}

/*
**		Receives an image data and coordinates
**		It returns the pixel in the image data at the coordinates
*/

int	get_pixel(t_data image_data, int x, int y)
{
	int	pixel;

	pixel = *(int *)(image_data.addr
			+ (y * image_data.line_length
				+ (x * (image_data.bits_per_pixel / 8))));
	return (pixel);
}

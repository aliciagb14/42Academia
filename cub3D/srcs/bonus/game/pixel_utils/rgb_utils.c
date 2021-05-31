/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:01:18 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 20:01:25 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Receives 4 ints with opacity, red, green and blue values (0 to 255)
**	and returns and int with each value taking 2 bytes
*/

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
**		Receives and int with trgb values in it
**		and returns the opacity value (0 to 255)
*/

int	get_transparency(int color)
{
	return ((color & (0xFF << 24)) >> 24);
}

/*
**		Receives a distance and a color and returns the color
**		as darker as longer the distance
*/

int	add_shade(float distance, int color)
{
	int	r;
	int	g;
	int	b;

	r = (int)((color & (0xFF << 16)) >> 16);
	g = (int)((color & (0xFF << 8)) >> 8);
	b = (int)(color & 0xFF);
	distance /= 40;
	if (distance > 0.9)
		distance = 0.9;
	r = r - (r * distance);
	g = g - (g * distance);
	b = b - (b * distance);
	return (create_trgb(get_transparency(color), r, g, b));
}

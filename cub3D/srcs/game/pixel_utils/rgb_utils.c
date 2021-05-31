/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:57:48 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 19:57:52 by agonzale         ###   ########.fr       */
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

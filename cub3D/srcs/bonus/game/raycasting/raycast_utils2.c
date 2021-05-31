/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:52:16 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 17:53:46 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <float.h>
#include "cub3d.h"

float	get_distance_to_wall(t_ray ray, t_vars *vars,
	float *wall_x, int window_x)
{
	if (ray.tile_crossed == '1' && ray.direction == horizontal)
	{
		vars->distances[window_x] = ray.distance_hor;
		if (ray.tile_step_y == 1)
			vars->wall_face = north_face;
		else
			vars->wall_face = south_face;
		*wall_x = ray.x_intercept - ray.x;
		return (ray.distance_hor * cosf(ray.angle_beta));
	}
	else if (ray.tile_crossed == '1' && ray.direction == vertical)
	{
		vars->distances[window_x] = ray.distance_ver;
		if (ray.tile_step_x == 1)
			vars->wall_face = west_face;
		else
			vars->wall_face = east_face;
		*wall_x = ray.y_intercept - ray.y;
		return (ray.distance_ver * cosf(ray.angle_beta));
	}
	return (1.0);
}

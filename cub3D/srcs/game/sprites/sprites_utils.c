/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:33:31 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 19:36:46 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "libft.h"

/*
**		Receives a pointer to a sprite and other arguments with info
**		to calculate the distance to the sprite, its coordinates
*/

void	calculate_sprite_info(t_sprite *sprite, t_player_vars player,
t_vars vars)
{
	float	y;
	float	x;
	float	sprite_angle;

	x = sprite->x - player.x;
	y = -(sprite->y - player.y);
	sprite_angle = player.angle - atanf(y / x);
	sprite->distance = sqrtf(x * x + y * y) * fabsf(cosf(sprite_angle));
	sprite->size_half = ((vars.max_col_height + vars.window_width) / 4)
		/ sprite->distance;
	sprite->center_y = vars.window_height / 2
		+ (vars.window_height / 2) / sprite->distance
		- sprite->size_half * 0.75;
	sprite->center_x = (tanf(sprite_angle) / tanf(FOV / 2) + 1)
		* vars.window_width / 2;
}

void	add_sprite_coords(float x, float y, t_vars *vars)
{
	t_list		*sprite_elem;
	t_sprite	*sprite;

	sprite_elem = vars->sprite;
	while (sprite_elem != NULL)
	{
		sprite = (t_sprite *)sprite_elem->content;
		if (sprite->x == x && sprite->y == y)
			return ;
		sprite_elem = sprite_elem->next;
	}
	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!(sprite))
		return ;
	sprite->x = x;
	sprite->y = y;
	calculate_sprite_info(sprite, vars->player, *vars);
	ft_lstadd_front(&vars->sprite, ft_lstnew(sprite));
}

void	order_sprites(t_list *sprite)
{
	t_list	*aux;
	t_bool	changed;

	changed = true;
	while (changed)
	{
		changed = false;
		aux = sprite;
		while (aux)
		{
			if (aux->next && ((t_sprite *)aux->next->content)->distance
				> ((t_sprite *)aux->content)->distance)
			{
				ft_lstmove_backwards(aux);
				changed = true;
			}
			aux = aux->next;
		}
	}
}

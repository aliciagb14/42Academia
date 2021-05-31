/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:55:57 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/31 17:59:24 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdio.h>

void	check_keycode(int keycode, t_keys *keys_pressed, t_bool is_pressed)
{
	if (keycode == 'w')
		keys_pressed->w = is_pressed;
	else if (keycode == 'a')
		keys_pressed->a = is_pressed;
	else if (keycode == 's')
		keys_pressed->s = is_pressed;
	else if (keycode == 'd')
		keys_pressed->d = is_pressed;
	if (keycode == ARROW_UP_KEY)
		keys_pressed->up_arrow = is_pressed;
	if (keycode == ARROW_DOWN_KEY)
		keys_pressed->down_arrow = is_pressed;
	if (keycode == ARROW_LEFT_KEY)
		keys_pressed->left_arrow = is_pressed;
	if (keycode == ARROW_RIGHT_KEY)
		keys_pressed->right_arrow = is_pressed;
}
/*
**		Function called whenever a key is pressed
**		Sets to true whichever key it's been pressed
**		If the pressed key is the Escape Key
**		calls the funcion that close the program
*/

int	on_key_pressed(int keycode, t_vars *vars)
{
	t_keys	*keys_pressed;

	keys_pressed = &vars->keys_pressed;
	if (keycode == ESC_KEY)
		free_and_close(vars);
	check_keycode(keycode, keys_pressed, true);
	if (keycode == LEFT_CTRL_KEY)
	{
		keys_pressed->left_ctrl = true;
		vars->y_offset = -vars->window_height / 4;
		render_once(vars);
	}
	return (0);
}

/*
**		Function called whenever a key is released
**		Sets to false whichever key it's been released
*/

int	on_key_released(int keycode, t_vars *vars)
{
	t_keys	*keys_pressed;

	keys_pressed = &vars->keys_pressed;
	check_keycode(keycode, keys_pressed, false);
	if (keycode == LEFT_CTRL_KEY)
	{
		keys_pressed->left_ctrl = false;
		vars->y_offset = 0;
		render_once(vars);
	}
	return (0);
}

/*
**		Function called when the windows is reopened
**		Redraws the screen
*/

int	on_window_focused(t_vars *vars)
{
	raycast(vars);
	render_sprites(vars);
	mlx_put_image_to_window(
		vars->mlx.mlx, vars->mlx.win, vars->mlx.img->img, 0, 0);
	display_score(*vars);
	return (0);
}

/*
**		Function called when the cross of the window is clicked
**		Frees all the allocated memory and stop the program
*/

int	on_window_closed(t_vars *vars)
{
	free_and_close(vars);
	return (0);
}

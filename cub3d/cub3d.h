/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 00:18:08 by agonzale          #+#    #+#             */
/*   Updated: 2020/11/09 11:13:52 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include "libft/libft.h"
# define PI 3.141592

typedef struct t_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	camX;
	double	camY;
	double	time;
	double	old_time;
}			s_player;
#endif
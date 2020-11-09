/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:11:34 by agonzale          #+#    #+#             */
/*   Updated: 2020/11/09 11:29:10 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_init(t_player *data_player)
{
	//pos inicial x e y
	data_player->posX =;
	data_player->posY =;
	//vector de dir inicial
	data_player->dirX =;
	data_player->dirY =;
	//version 2d del raycaster de la camara
	data_player->camX =;
	data_player->camY =;
	//tiempo del cuadro actual
	data_player->time =;
	//tiempo del fotograma anterior
	data_player->old_time =;
}
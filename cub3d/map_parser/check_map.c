/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:54:01 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/13 21:06:09 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*ni 0 ni el 2 rodeado de cualquier numero menos de espacios. strchar
si es pto cardinal te guardas pos de jugador y le pones el angulo de vision N = 0 grados, 
E = 90 grados guardar en un elemento que sea float.
comprobar q pos de jugador no tiene valor ya, si lo tiene error*/

/*la info del fichero esta en el buffer. 1 = pared. 2 o > 2 = sprites. 0 = vacios.
 Espacio son huecos donde no se puede mover el jugador ni pared*/
int read_map(char *line, t_gnl_buffer *buffer, t_error error)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
}
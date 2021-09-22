/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:01:55 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 13:02:20 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_size(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (((char **)array)[i])
		i++;
	return (i);
}

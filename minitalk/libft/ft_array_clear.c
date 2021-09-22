/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:49 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 13:03:52 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_clear(void **array, void (*del)(void *))
{
	int	i;

	i = 0;
	if (array)
	{
		if (del)
		{
			while (((char **)array)[i])
				del(array[i++]);
			del(array[i]);
		}
		free(array);
	}
}

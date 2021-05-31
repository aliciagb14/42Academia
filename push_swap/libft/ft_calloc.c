/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:01:26 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 13:01:28 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*array;

	array = malloc(count * size);
	if (!array)
		return (NULL);
	if ((int)count == 0 || (int)size == 0)
		return (array);
	ft_bzero(array, count * size);
	return ((void *)array);
}

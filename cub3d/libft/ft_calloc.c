/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:51:44 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 13:51:50 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*array;

	if (!(array = malloc(count * size)))
		return (NULL);
	if ((int)count == 0 || (int)size == 0)
		return (array);
	ft_bzero(array, count * size);
	return ((void*)array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:59 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 13:04:04 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates a memory segment of count * size + 1 and
** null terminates the result.
*/

void	*ft_alloc(size_t count, size_t size)
{
	void	*array;

	array = malloc(count * size + size);
	if (!array)
		return (NULL);
	ft_bzero(array + count * size, size);
	return ((void *)array);
}

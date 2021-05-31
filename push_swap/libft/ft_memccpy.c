/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:55:55 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:56:00 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned int	i;

	i = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (i < n && (unsigned char)c != source[i])
	{
		dest[i] = source[i];
		i++;
	}
	if (i < n)
	{
		dest[i] = source[i];
		return (&dest[i + 1]);
	}
	return (NULL);
}

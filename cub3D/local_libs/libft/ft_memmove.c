/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:55:18 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:55:20 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned int	i;

	dest = dst;
	source = (unsigned char *)src;
	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dest > source)
		while ((int)(--len) >= 0)
			dest[len] = source[len];
	else
		while (++i < len)
			dest[i] = source[i];
	return (dst);
}

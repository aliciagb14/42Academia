/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:55:09 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:55:11 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pointer;

	pointer = (unsigned char *)b;
	while (len > 0)
	{
		*(pointer++) = (unsigned char)c;
		len--;
	}
	return (b);
}

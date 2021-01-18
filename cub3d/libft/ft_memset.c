/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:04:11 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 14:04:15 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *pointer;

	pointer = (unsigned char*)b;
	while (len > 0)
	{
		*(pointer++) = (unsigned char)c;
		len--;
	}
	return (b);
}

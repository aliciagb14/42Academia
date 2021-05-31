/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:55:43 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:55:46 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s2;

	s2 = s;
	while (n--)
	{
		if (*s2 != (char)c)
			s2++;
		else
			return ((void *)s2);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:51:00 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:51:03 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat_in(char *s1, char *s2, int n)
{
	size_t	dstsize;
	int		i;
	char	*s;

	i = 0;
	dstsize = ft_strlen(s1) + n + 1;
	s = malloc(dstsize);
	if (!s)
		return (0);
	if (!s1 && !s2)
		s[0] = 0;
	if (s1)
		i = ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcpy(s + i, s2, n + 1);
	return (s);
}

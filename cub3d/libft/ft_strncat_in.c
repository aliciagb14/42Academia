/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:10:49 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 14:10:53 by agonzale         ###   ########.fr       */
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
	if (!(s = malloc(dstsize)))
		return (0);
	if (!s1 && !s2)
		s[0] = 0;
	if (s1)
		i = ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcpy(s + i, s2, n + 1);
	return (s);
}

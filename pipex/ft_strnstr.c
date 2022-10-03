/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:23:31 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 08:39:26 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[k] && ((i + j) < len))
		{
			j++;
			k++;
			if (!needle[k])
				return ((char *)&haystack[i]);
		}
		k = 0;
		j = 0;
		i++;
	}
	return (NULL);
}
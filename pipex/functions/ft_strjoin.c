/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:06:16 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/15 13:06:53 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	if (!s1 || !s2)
	{
		if (!s1)
			return ((char *)s2);
		else
			return ((char *)s1);
	}
	joined_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!joined_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		joined_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined_str[j++] = s2[i++];
	joined_str[j] = '\0';
	return (joined_str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:21:58 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/15 08:22:17 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	real_len;
	char			*string;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	real_len = ft_strlen(&s[start]);
	if (real_len > len)
		real_len = len;
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	string = (char *)malloc((real_len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (j < real_len)
		string[j++] = s[i++];
	string[j] = '\0';
	return (string);
}
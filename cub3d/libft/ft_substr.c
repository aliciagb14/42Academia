/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:00 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 14:12:04 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	real_len = (real_len < len) ? real_len : len;
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (!(string = (char*)malloc((real_len + 1) * sizeof(char))))
		return (NULL);
	while (j < real_len)
		string[j++] = s[i++];
	string[j] = '\0';
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 07:46:25 by agonzale          #+#    #+#             */
/*   Updated: 2020/01/30 11:47:54 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	char	*aux;
	int		i;

	i = 0;
	aux = (char *)str;
	while (*aux)
	{
		if (*aux == c)
			return (aux);
		aux++;
	}
	if (c == '\0')
		return (aux);
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	if (!s1)
		return ((char *)s2);
	if (!(p = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
		* sizeof(char))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
		p[j++] = s2[i++];
	p[j] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s = malloc((sizeof(char)) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*src;
	char			*p;

	i = 0;
	src = (char *)s;
	if (!(p = malloc(sizeof(char) * len + 1)))
		return (0);
	if (s == 0)
		return (0);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	while (src[start] && i < len)
	{
		p[i] = src[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:49:41 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:49:44 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_limit(char const *string, char const *set, int flag)
{
	int	position;
	int	sum;

	if (flag == 1)
	{
		sum = 1;
		position = 0;
	}
	else
	{
		sum = -1;
		position = ft_strlen((char *)string) - 1;
	}
	while (position != -1 && string[position] && ft_checkchar(string[position],
			(char *)set))
		position += sum;
	return (position);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*new_string;

	if (!s1 || !set)
		return (NULL);
	start = get_limit(s1, set, 1);
	end = get_limit(s1, set, -1) + 1;
	if (end == 0)
		return (ft_strdup(""));
	new_string = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while ((i + start) < end)
	{
		new_string[i] = s1[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

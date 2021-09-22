/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:50:01 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:50:05 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last_ocurrence;
	char	*string;

	string = (char *)s;
	i = 0;
	last_ocurrence = -1;
	while (string[i])
	{
		if (string[i] == c)
			last_ocurrence = i;
		i++;
	}
	if (c == '\0')
		return (&string[i]);
	if (last_ocurrence != -1)
		return (&string[last_ocurrence]);
	else
		return (NULL);
}

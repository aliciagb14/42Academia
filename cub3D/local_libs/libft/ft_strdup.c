/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:52:28 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:52:31 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	char	*new_string;

	string = (char *)s1;
	new_string = (char *)malloc((ft_strlen(string) + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	else
		return (ft_memcpy(new_string, string, ft_strlen(string) + 1));
}

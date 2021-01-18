/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:07:41 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 14:07:45 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *string;
	char *new_string;

	string = (char*)s1;
	if (!(new_string = (char*)malloc((ft_strlen(string) + 1) * sizeof(char))))
		return (NULL);
	else
		return (ft_memcpy(new_string, string, ft_strlen(string) + 1));
}

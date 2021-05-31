/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:50:33 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:50:36 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s2, int n)
{
	char	*s;

	if (!s2)
		return (ft_strdup(""));
	s = malloc(n + 1);
	if (!s)
		return (0);
	ft_strlcpy(s, s2, n + 1);
	return (s);
}

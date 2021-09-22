/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_checkset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:52:51 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:52:54 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_checkset(char *string, char *set)
{
	if (string)
	{
		while (*string)
		{
			if (ft_checkchar(*string, set))
				return (true);
			string++;
		}
	}
	return (false);
}

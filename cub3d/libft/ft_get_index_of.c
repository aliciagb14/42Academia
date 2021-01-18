/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:52:13 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 13:52:18 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_index_of(char *string, char c)
{
	int index;

	index = 0;
	while (string[index])
	{
		if (string[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

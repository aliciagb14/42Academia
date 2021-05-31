/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:01:09 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 13:01:11 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_index_of(char *string, char c)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

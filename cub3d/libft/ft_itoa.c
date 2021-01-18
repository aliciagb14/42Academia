/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:57:14 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 13:57:21 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_nbr(char *string, unsigned int index, long int number)
{
	if (number >= 10 || number <= -10)
	{
		fill_nbr(string, index - 1, (number < 0 ? -number : number) / 10);
		string[index] = ((number < 0 ? -number : number) % 10) + 48;
	}
	else
		string[index] = (number >= 0 ? number : -number) + 48;
}

unsigned int	get_digits(long int n)
{
	unsigned int	digits;

	digits = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char			*ft_itoa(long int n)
{
	char			*string;
	long int		n_copy;
	unsigned int	digits;
	unsigned int	index;

	if (n == 0)
		return (ft_strdup("0"));
	digits = get_digits(n);
	n_copy = n;
	index = digits - 1;
	if (!(string = (char*)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	string[digits] = '\0';
	if (n_copy < 0)
		string[0] = '-';
	fill_nbr(string, index, n_copy);
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:42:55 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/02 15:14:32 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
	c == '\r' || c == ' ') ? TRUE : FALSE;
}

int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	number;
	char		*string;

	i = 0;
	sign = 1;
	number = 0;
	string = (char*)str;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign *= (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number == 0)
			number = str[i] - 48;
		else
			number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * sign);
}

static int		getsize(int nb)
{
	long int len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb == 0)
		len = 1;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void		init_var(long int *i, long int *a, long int *len, int n)
{
	*len = getsize(n);
	*i = 0;
	*a = (long int)n;
}

char			*itoa(int n)
{
	long int		len;
	long int		i;
	long int		a;
	long int		j;
	char			*s;

	init_var(&i, &a, &len, n);
	if (!(s = malloc(sizeof(char) * len + 1)))
		return (0);
	if (a == 0)
		s[0] = '0';
	if (a < 0)
	{
		s[0] = '-';
		a = -a;
	}
	while (a != 0)
	{
		j = a % 10;
		s[len - (++i)] = j + '0';
		a = a / 10;
	}
	s[len] = '\0';
	return (s);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:42:55 by agonzale          #+#    #+#             */
/*   Updated: 2020/02/11 08:55:11 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         atoi(const char *str)
{
    int		i;
	int		neg;
	int		sign;
	int		a;

	i = 0;
	neg = 1;
	a = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
		sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + ((int)(str[i]) - '0');
		i++;
	}
	return (sign > 1) ? 0 : a * neg;
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
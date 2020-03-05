/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:42:55 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/05 16:46:51 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
	c == '\r' || c == ' ') ? TRUE : FALSE;
}

int		ft_atoi(char *str, t_list *l)
{
	int			i;
	int			sign;
	long int	number;
	char		*string;

	i = 0;
	sign = 1;
	number = 0;
	string = (char*)str;
	while (ft_isspace(str[l->pos]))
		l->pos++;
	if (str[l->pos] == '+' || str[l->pos] == '-')
		sign *= (str[l->pos++] == '-') ? -1 : 1;
	while (str[l->pos] >= '0' && str[l->pos] <= '9')
	{
		if (number == 0)
			number = str[l->pos] - 48;
		else
			number = number * 10 + str[l->pos] - 48;
		l->pos++;
	}
	return (number * sign);
}

int		ft_get_size_num(t_list *l, int number)
{
	l->len = 0;
	if (number < 0)
		l->len++;
	if (number == 0)
		l->len = 1;
	while (number != 0)
	{
		l->len++;
		number /= 10;
	}
	return (l->len);
}

int		ft_isnumber(char c)
{
	return (c >= '0' && c <= '9') ? TRUE : FALSE;
}

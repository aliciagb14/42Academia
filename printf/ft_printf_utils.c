/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:18:05 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/23 10:23:06 by agonzale         ###   ########.fr       */
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

int		ft_strlen(t_list *l, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_isnumber(char c)
{
	return (c >= '0' && c <= '9') ? TRUE : FALSE;
}

void	ft_putnbr(t_list *l, int number)
{
	if (number < 0)
		number = -number;
	if (number > 9)
	{
		ft_putnbr(l, number / 10);
		ft_putchar(number % 10 + 48, l);
	}
	else
		ft_putchar(number + 48, l);
}

void	ft_putnbr_u(t_list *l, unsigned int number)
{
	if (number < 0)
		number = -number;
	if (number > 9)
	{
		ft_putnbr(l, number / 10);
		ft_putchar(number % 10 + 48, l);
	}
	else
		ft_putchar(number + 48, l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:51:20 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 10:33:36 by user42           ###   ########.fr       */
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


int		ft_count_nb(int number)
{
	int				count;
	unsigned int	c;

	c = 0;
	count = 0;
	if (number < 0)
	{
		c = number * -1;
		count++;
	}
	if (number > 0)
		c = number;
	while (c >= 10)
	{
		c = c / 10;
		count++;
	}
	if (c < 10)
		count++;
	return (count);
}

void	ft_putnum(char *str, int number, int len)
{
	unsigned int c;

	c = 0;
	str[len--] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		c = number * -1;
	}
	if (number > 0)
		c = number;
	while (c > 10 || (c <= 10 && c != 0))
	{
		str[len--] = c % 10 + 48;
		c = c / 10;
	}
}

char	*ft_itoa(int number)
{
	char	*str;
	int		len;

	if (number < -2147483648)
		return (NULL);
	len = ft_count_nb(number);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (NULL);
	ft_putnum(str, number, len);
	return (str);
}

int		ft_isnumber(char c)
{
	return (c >= '0' && c <= '9') ? TRUE : FALSE;
}
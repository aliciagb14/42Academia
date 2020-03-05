/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:59:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/05 08:03:46 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
	l->cnt++;
}*/

void	ft_putnbr(int number, t_list *l)
{
	if (number < 0)
	{
		number = -number;
		ft_putchar('-', l);
	}
	if (number > 9)
	{
		ft_putnbr(number / 10, l);
		ft_putchar(number % 10 + 48, l);
	}
	else
		ft_putchar(number + 48, l);
}

/*void	case_c(t_list *l, char next)
{
	next = (char)va_arg(l->args, int);
	ft_putchar(next, l);
}*/

void	case_s(t_list *l)
{
	char *str;
	str = (char *)va_arg(l->args, long int);
	l->len = 0;
	while (str[l->len])
	{
		ft_putchar((char)str[l->len], l);
		l->len++;
	}
}

//%d asume que la base es 10 y %i autodetecta la base
void	case_d(t_list *l)
{
	int number;

	number = va_arg(l->args, int);
	ft_putnbr(number, l);
}

int     ft_printf(const char *line, ...)
{
	t_list *l;
	if (!(l = malloc(sizeof(t_list))))
		return (-1);
	l->pos = 0;
	char *str;
	char next;

	va_start(l->args, line);
	while (line[l->pos])
	{
		if (line[l->pos] == '%')
		{
			l->pos++;
			if (line[l->pos] == 'c')
				case_c(l, next);
			else if (line[l->pos] == 's')
				case_s(l);
			else if (line[l->pos] == 'd')
				case_d(l);
		}
		else
			ft_putchar((char)line[l->pos], l);
		l->pos++;
	}
	va_end(l->args);
	return (l->cnt);
}

int		main(void)
{
	//CHAR
	/*char m = 'a';
	printf("%d\n", ft_printf("eeeyy%ckbuenosdias", m));
	printf("%d\n", printf("eeeyy%ckbuenosdias", m));
	return (0);*/

    //STRING
	char s[5] = {'H','O','L','A','\0'};
	int x;
	x = printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	x = ft_printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	return (0);

	//INT %D
/*	int m = 9921474;
	printf("%d\n", ft_printf("%5dbaemjjcmj", m));
	printf("%d\n", printf("%5dbaemjjcmj", m));
	return (0);*/
}

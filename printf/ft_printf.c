/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:59:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/02/27 16:01:08 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
	l->cnt++;
}

void	case_c(t_list *l, const char *line, char next)
{
	next = (char)va_arg(l->args, int);
	ft_putchar(next, l);
}

void	case_s(t_list * l, const char *line, char *str)
{
	str = (char *)va_arg(l->args, long int);
	l->len_str = 0;
	while (str[l->len_str])
	{
		ft_putchar((char)str[l->len_str], l);
		l->len_str++;
	}
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
				case_c(l, line, next);
			else if (line[l->pos] == 's')
				case_s(l, line, str);
			else if (line[l->pos] == 'p')
				case_p(l, line);
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
	/*
	char m = 'a';
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
}

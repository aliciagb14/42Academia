/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:47:25 by agonzale          #+#    #+#             */
/*   Updated: 2020/04/08 12:47:29 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *line, ...)
{
	t_list *l;

	if (!(l = malloc(sizeof(t_list))))
		return (-1);
	l->pos = 0;
	va_start(l->args, line);
	ft_initialize(l);
	while (line[l->pos])
	{
		if (line[l->pos] == '%')
		{
			l->pos++;
			ft_saver_flags(l, (char *)line);
			ft_printer_int(l, line);
		}
		else
			ft_putchar(line[l->pos], l);
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
	/*char s[5] = {'H','O','L','A','\0'};
	int x;
	x = printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	x = ft_printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	return (0);*/

	//INT %D	PRUEBAS MIAS
	/*m = 789990 printf("%d\n", printf("%5d", m)) --> 789990
	m = 798 printf("%d\n", printf("%5d", m)) --> SPACESPACE798
	m = 798 printf("%d\n", printf("%-5d", m)) --> 798SPACESPACE
	int m = 471337;
	printf("%d\n", ft_prinf("%5d", m));
	printf("%d\n", printf("%5d", m));
	return (0);*/
	printf("%d\n", ft_printf("%-2.3dFIN", 42));
	printf("%d\n", printf("%-2.3dFIN", 42));
	return (0);
}

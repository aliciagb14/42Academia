/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:59:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/05 16:47:38 by agonzale         ###   ########.fr       */
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
			ft_first_flags((char *)line, l);
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
	char s[5] = {'H','O','L','A','\0'};
	int x;
	x = printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	x = ft_printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	return (0);

	//INT %D
	/*m = 789990 printf("%d\n", printf("%5d", m)) --> 789990
	m = 798 printf("%d\n", printf("%5d", m)) --> SPACESPACE798
	m = 798 printf("%d\n", printf("%-5d", m)) --> 798SPACESPACE*/
	int m = 474;
	printf("%d\n", ft_printf("%05d", m));
	printf("%d\n", printf("%05d", m));
	return (0);
}

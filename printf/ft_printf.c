/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:59:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/10 12:55:03 by agonzale         ###   ########.fr       */
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
			ft_printer(l, line);
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

	//INT %D
	/*m = 789990 printf("%d\n", printf("%5d", m)) --> 789990
	m = 798 printf("%d\n", printf("%5d", m)) --> SPACESPACE798
	m = 798 printf("%d\n", printf("%-5d", m)) --> 798SPACESPACE*/
	int m = 474;
	printf("%d\n", ft_printf("%5d", m));
	printf("%d\n", printf("%5d", m));
	return (0);
	/*
	    // Conversiones de enteros (d)(i)
    ft_printf("CONVERSIONES DE ENTEROS (d)(i)\n");
        // flags 0 es ignorado cuando hay un flag - (Warning)
        // si el num dado como arg es de tipo double, añade tantos 0s como precisión o 1 si no está especificada
    ft_printf("%-0*.3dFIN\n", 4, 42);       // se cogen . int rellenando de 0s a la izq si fuera necesario completar
                                        // y el num sobrante rspcto al width se añade a la dcha en forma de espacio
    ft_printf("%0*.1dFIN\n", 4, -42);       // igual q el anterior pero el espacio se añade a la izq
    ft_printf("%-2.3dFIN\n", 42);           // se añade 0s a izq para completar la precisión y después se comprueba *
    ft_printf("%*dFIN\n", 4, -42);          // se añaden (width - len(int)) espacios a la izq, el - cuenta (len(-24) = 3)
    ft_printf("%-04.1dFIN\n", 42);          // se añaden (width - len(int)) espacios a la dcha, la precisión es menor q
                                        // len(int) por lo que no se rellena con 0s
    ft_printf("%-*.5dFIN\n", 7, -42);
    ft_printf("%*.5dFIN\n", 7, -42);
    ft_printf("%*.7dFIN\n", 5, 42);
    ft_printf("%0*dFIN\n", 4, -42);
            // Estos ejemplos de flags, no influyen en la impresión de la cadena
    ft_printf("%-dFIN\n", 42);
    ft_printf("%-0dFIN\n", 42);
    ft_printf("%0dFIN\n", 42);
    ft_printf("%*dFIN\n", 1, 42); // width < nº cifras
    ft_printf("%0*dFIN\n", 1, 42);
    ft_printf("%.1dFIN\n", 42);
    ft_printf("%-.1dFIN\n", 42);
    ft_printf("%-*.2dFIN\n", 2, 42);
    ft_printf("---------------------------------\n");
	*/
}

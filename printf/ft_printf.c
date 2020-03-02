/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:59:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/02 17:00:33 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *l)
{
	write(1, &c, 1);
	l->cnt++;
}

void	case_c(t_list *l, char next)
{
	next = (char)va_arg(l->args, int);
	ft_putchar(next, l);
}

void	case_s(t_list * l, char *str)
{
	str = (char *)va_arg(l->args, long int);
	l->len = 0;
	while (str[l->len])
	{
		ft_putchar((char)str[l->len], l);
		l->len++;
	}
}
//%d asume que la base es 10 y %i autodetecta la base
void 	case_d(t_list *l, char *number)
{
	number = (char *)va_arg(l->args, long int);
	l->len = 0;
	if (number[l->len])
	{
		ft_itoa(number[l->len]);
		l->len++;
	}
	/*else if (number)
		number[l->len] = *itoa(number); //itoa devuelve char**/
}

int     ft_printf(const char *line, ...)
{
	t_list *l;
	if (!(l = malloc(sizeof(t_list))))
		return (-1);
	l->pos = 0;
	char *str;
	char next;
	char *number;

	va_start(l->args, line);
	while (line[l->pos])
	{
		if (line[l->pos] == '%')
		{
			l->pos++;
			if (line[l->pos] == 'c')
				case_c(l, next);
			else if (line[l->pos] == 's')
				case_s(l, str);
			/*else if (line[l->pos] == 'p')
				case_p(l, line);*/
			else if (line[l->pos] == 'd')
				case_d(l, number);
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
	/*char s[5] = {'H','O','L','A','\0'};
	int x;
	x = printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	x = ft_printf("hh98%sbuenosdias", s);
	printf("%d\n", x);
	return (0);*/

	//INT %D
	int m = 5356;
	printf("%d\n", ft_printf("%d", m));
	printf("%d\n", printf("%d", m));
	return (0);
}

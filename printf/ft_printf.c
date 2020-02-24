/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:59:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/02/24 18:37:15 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		write(1, &s, 1);
		i++;
	}
}

void case_c(t_list * l, const char *line, char next)
{
    next = (char)va_arg(l->args, int);
    ft_putchar(next);
    l->cnt++;
    //l->data = ft_putchar(next);
}

/*char *case_s(va_list args, t_list * l, const char *line, char *str)
{
    str = (char *)va_arg(args, int);
    l->cnt++;
    l->data = ft_putstr(str);
}
*/
int     ft_printf(const char *line, ...)
{
    t_list *l;
    if (!(l = malloc(sizeof(t_list))))
        return (0);
    unsigned int i;
    char next;
    char *str;

    i = 0;
    va_start(l->args, line);
    while (line[i])
    {
        if (line[i] == '%')
        {
            i++;
            if (line[i] == 'c')
                case_c(l, line, next);
           /* else if(line[i] == 's')
                case_s(args, l, line, str);*/
        }
        else
        {
            i++;
            /*
            imprimir el espacio y seguir imprimiendo lo que haya de string
            hasta llegar al caracter nulo. l->cnt++ cada vez que avanza 1 pos*/
            l->cnt++;
        }
        i++;
       // return (next);
    }
    return (l->cnt);
    va_end(l->args);
}

int     main(void)
{
    //CHAR
    char c = 'a';
   // ft_printf("%c\n", c);
   // printf("%c\n", c);

    //STRING
  //  char s[4] = "hola";
    printf("%d\n", ft_printf("%c buenosdias", c));
    printf("%d\n", printf("%c buenosdias", c));
    return (0);
}

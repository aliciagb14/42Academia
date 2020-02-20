/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:59:31 by agonzale          #+#    #+#             */
/*   Updated: 2020/02/20 11:19:28 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
int     ft_num(t_list * hola)
{
    if((hola-> num_0) > 0)
    {
        if (hola-> prec > hola->len_str)
            hola-> num_0 = hola-> prec - hola-> len_str;
        else
            hola-> num_0 = hola-> len_str;
    }

    if ((hola-> num_esp) > 0)
    {
        if (hola-> width > hola-> prec)
         hola-> num_esp = hola-> width - hola-> prec;
        else
         hola-> num_esp <= 0;
    }
}

static int printfspecifier(t_list * format)
{
    char specifier;
    if (specifier == "%")
        return (strchr('%', va_arg()))
    else if(strchr == 'd' || strchr == 'i')
}

static char specifier(char **line, s_flags p)
{
    char d;
    char i;
    char c;
    char e;
    char g;
    char f;
    char o;
    char s;
    char u;
    char x;
    char percent;

    p->percent = '%';
    specifier(*line, p);
    if (*line)
    {
        if (*line == p->percent) //inicio cadena
        {
            line++;
        }
        else if ((*line == d) || (*line == i))
            return (va_arg(list, int));
        else if(*line == c)
            return (va_arg(list, char));
    }
}

char ischar(char **line)
{
    int i;
    int c;

    i = 0;
    while(*line)
    {
        if(*line == (char *)c)
            return (c);
    }
}

int     scprinter(t_list specialcar, va_list adios)
{
    char **line;
    if(*line)
    {
        if (*line == "\\")
            ischar('\');
        else if (*line == "\"")
            ischar('"');
        else if (*line = "\,")
            ischar(',');
    }
}*/
void ft_putchar(char c)
{
    write (1, 'c', 1);
}
char case_c(va_list args, t_list * p, const char *line, char c)
{
    int i;
    char saver[100];
    saver[i] = (char)va_arg(args, int);
    p->cnt++;
    i++;
    ft_putchar(c);
}

int     ft_printf(const char *line, ...)
{
    t_list *p;
    va_list args;
    unsigned int i;
    unsigned int j;
    char c;
    char saver[100];

    i = 0;
    j = 0;
    va_start(args, line);
    while (*line)
    {
        if(line[i] == '%')
        {
            i++;
            if((line[i]) == 'c')
                case_c(args, p, line, c);
        }
        else
        {
            ft_putchar(c);
            i++;
            p->cnt++;
        }
        i++;
    }
    va_end(args);
    return (saver[i]);
}

int     main(void)
{
    //  CHAR
    char c = 'a';
    ft_printf("%c hola", c);
    printf("%c hola", c);
    return (0);
}

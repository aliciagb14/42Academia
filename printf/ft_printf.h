/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:52:03 by agonzale          #+#    #+#             */
/*   Updated: 2020/02/27 16:00:58 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h> //al incluir la librería  declaro va_list y se definen sus 3 macros       
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*funciones*/
int             ft_printf(const char *, ...);
//void			ft_putchar(char c, t_list * l);
//void 			case_c(t_list * l, const char *line, char next);
//void			princp_c(const char *line, t_list *l);
int             atoi(const char *str);
char			*itoa(int n);


/*estructuras*/
/*
typedef struct s_flags
{
    int     minus; //-
	int     space; // ' '
    int     zero; //0
}               t_flags;
*/
typedef struct  s_princp {
    int         width; //ancho
    int         precision; //numeros tras la coma
    int         cnt; //cuenta %s, %c, %f....
	int			pos; // es un contador (igual que i)
    int         len_str;
    char        *format;
    void        *data;
    va_list     args;
   //	struct      s_flags;
}               t_list;

/*
void va_start(va_list ap, last) -> inicializa lista
void va_arg(va_list ap, type) -> devuelve sig argumento de lista
void va_end(va_list ap) -> limpia arg list
*/
#endif
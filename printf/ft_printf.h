/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:52:03 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/02 16:57:10 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdarg.h> //al incluir la librería  declaro va_list y se definen sus 3 macros       
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*estructuras*/
typedef struct s_flags
{
    int     minus;	// -
	int     space;	// ' '
    int     zero;	// 0
	//ACUERDATE DEL *
}               t_flags;

typedef struct  s_princp {
    int         width; //ancho
    int         precision; //numeros tras la coma
    int         cnt; //cuenta %s, %c, %f....
	int			pos; // es un contador (igual que i)
	int			len;
    va_list     args;
   	t_flags		flags;
}               t_list;

/*funciones*/
void 			ft_initialize(t_list *l);
int             ft_printf(const char *, ...);
int             ft_atoi(char *str);
char			*ft_itoa(int n);
static int		ft_getsize_itoa(int nb);
static void		ft_init_var_itoa(long int *i, long int *a, long int *len, int n);

/*
void va_start(va_list ap, last) -> inicializa lista
void va_arg(va_list ap, type) -> devuelve sig argumento de lista
void va_end(va_list ap) -> limpia arg list
*/
#endif
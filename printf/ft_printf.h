/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:52:03 by agonzale          #+#    #+#             */
/*   Updated: 2020/03/05 08:10:20 by agonzale         ###   ########.fr       */
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
//ft_specifier
void ft_isspecifier(t_list *l);
//ft_numbers
void	ft_putnbr(int number, t_list *l);
int		ft_get_size_num(t_list *l, int number);
int		ft_atoi(char *str);
int		ft_isspace(int c);
//ft_case_c
void	ft_putchar(char c, t_list *l);
void 	ft_case_c(t_list * l, const char *line, char next);
void	princp_c(const char *line, t_list *l);
//FLAGS
void 	ft_first_flags(const char *line, t_list *l);
void 	ft_width(t_list *l, const char *line, int number);


/*
void va_start(va_list ap, last) -> inicializa lista
void va_arg(va_list ap, type) -> devuelve sig argumento de lista
void va_end(va_list ap) -> limpia arg list
*/
#endif
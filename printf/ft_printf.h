/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 TRUE2:50:08 by user42            #+#    #+#             */
/*   Updated: 2020/09/29 TRUE8:46:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#define TRUE 1
#define FALSE 0
#define NULL = 0
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
void	ft_initialize(t_list *l);
//ft_specifier
void	ft_specifier(t_list *l, const char *line);
int		ft_isspecifier(char c);
//ft_numbers
void	ft_putnbr(t_list *l, int number);
int     ft_strlen (t_list *l, char *str);
int		ft_get_size_num(t_list *l, int number);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isnumber(char c);
//ft_cases
void	ft_putchar(char c, t_list *l);
void 	ft_case_c(t_list * l);
void    ft_printer_char(t_list *l, const char *line);
void    ft_printer_string(t_list *l, const char *line);
void    ft_printer_hexa(t_list *l, const char *line);
void    ft_printer_hexap(t_list *l, const char *line);
void	ft_printer_int(t_list *l, const char *line);
void	ft_printer_unsigned(t_list *l, const char *line);
char	*ft_trans_hex(long int i, char c);
char    *ft_trans_hexp(unsigned long int i);
char    *ft_type_hexap(char *def);

//FLAGS
int     ft_saver_flags(t_list *l, const char *line);
void    ft_printer_zero(t_list *l, int number, int size);
void    ft_printer_spaces(t_list *l, int size, const char *line);
void    ft_printer_minus(t_list *l, int number);
void    ft_printer_character(t_list *l, char *str);
void    ft_case_width(t_list *l, const char *line, int number);
void    ft_case_zero_width(t_list *l, const char *line, int number);
void    ft_case_prec_d(t_list *l, const char *line, int number);
void    ft_case_width_prec(t_list *l, const char *line, int number);
void    ft_case_width_prec(t_list *l, const char *line, int number);
void    ft_case_zero_s(t_list *l, const char *line, char *str);
void    ft_case_width_s(t_list *l, const char *line, char *str);
void    ft_aux_case_width_s(t_list *l, const char *line, char *str);
void    ft_case_width_prec_s(t_list *l, const char *line, char *str);
char	*ft_strdup(t_list *l, char *s1);
char    *ncharacter_according_prec(t_list *l, char *str);
void    ft_case_width_prec_x(t_list *l, const char *line, char *s, int nb);
void    ft_case_width_x(t_list *l, const char *line, char *s, int nb);
void    ft_case_width_hexap(t_list *l, const char *line, char *str, int number);
void    ft_case_width_prec_hexap(t_list *l, const char *line, char *str, int number);
char    *ft_case_prec_hexap(t_list *l, char *s);
void    ft_case_width_u(t_list *l, const char *line, int number);
void    ft_case_zero_width_u(t_list *l, const char *line, int number);
void    ft_case_width_prec_u(t_list *l, const char *line, int number);
void    ft_case_zero_width_prec_u(t_list *l, const char *line, int number);
/*
void va_start(va_list ap, last) -> inicializa lista
void va_arg(va_list ap, type) -> devuelve sig argumento de lista
void va_end(va_list ap) -> limpia arg list
*/
#endif
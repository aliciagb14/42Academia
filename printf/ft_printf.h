/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:01:56 by agonzale          #+#    #+#             */
/*   Updated: 2020/10/26 11:20:07 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			minus;
	int			space;
	int			zero;
	int			ast;
	int			point;
}				t_flags;

typedef struct	s_princp
{
	int			width;
	int			precision;
	int			cnt;
	int			pos;
	int			len;
	va_list		args;
	t_flags		flags;
}				t_list;

int				ft_printf(const char *line, ...);
void			ft_initialize(t_list *l);
void			ft_specifier(t_list *l, const char *line);
int				ft_isspecifier(char c);
void			ft_putnbr(t_list *l, long int number);
void			ft_putnbr_u(t_list *l, unsigned int number);
int				ft_strlen (char *str);
int				ft_get_size_num(t_list *l, int number);
int				ft_atoi(const char *str);
int				ft_isspace(int c);
int				ft_isnumber(char c);
void			ft_putchar(char c, t_list *l);
void			ft_case_c(t_list *l);
void			ft_printer_char(t_list *l);
void			ft_printer_string(t_list *l);
void			ft_printer_hexa(t_list *l, const char *line);
void			ft_printer_hexap(t_list *l);
void			ft_printer_int(t_list *l);
void			ft_printer_unsigned(t_list *l);
void			ft_printer_percent(t_list *l);
char			*ft_trans_hex(long int i, char c);
char			*ft_trans_hexp(unsigned long i);
char			*ft_type_hexap(char *def);
int				ft_saver_flags(t_list *l, const char *line);
void			ft_saver_ast_width(t_list *l);
void			ft_saver_ast_prec(t_list *l, const char *line);
void			ft_printer_zero(t_list *l, int size);
void			ft_printer_spaces(t_list *l, int size);
void			ft_printer_minus(t_list *l, int number);
void			ft_printer_character(t_list *l, char *str);
void			ft_case_width(t_list *l, int number);
void			ft_case_minus_width(t_list *l, int number);
void			ft_case_width_prec_minus(t_list *l, int number);
void			ft_case_width_prec_aux(t_list *l, int number);
void			ft_case_width_prec(t_list *l, int number);
void			ft_case_minus_null_s(t_list *l);
void			ft_case_no_minus_null(t_list *l);
void			ft_case_width_s(t_list *l, char *str);
void			ft_case_width_prec_s(t_list *l, char *str);
char			*ncharacter_according_prec(t_list *l, char *str);
void			ft_case_width_prec_x(t_list *l, char *s, int nb);
void			ft_case_width_prec_aux_x(t_list *l, char *s, int nb);
void			ft_case_width_x(t_list *l, char *s, int nb);
void			ft_case_zero_hexa(t_list *l, const char *line, char *s, int nb);
void			ft_case_printer_hexap_aux(t_list *l, char *str);
void			ft_case_width_hexap(t_list *l, char *str);
void			ft_case_width_u(t_list *l, int number);
void			ft_case_minus_width_u(t_list *l, int number);
void			ft_case_width_prec_minus_u(t_list *l, int number);
void			ft_case_width_prec_aux_u(t_list *l, int number);
void			ft_case_width_prec_u(t_list *l, int number);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:23:30 by agonzale          #+#    #+#             */
/*   Updated: 2023/04/14 15:31:54 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	int		sorted_elem_a;
	int		sorted_elem_b;
	int		nbr_count;
	char	**matrix;
	t_list	*stack_a;
	t_list	*stack_b;
}				t_stacks;

/**
 * CHECK INPUT
 * */
void	read_input(t_list **list, char **argv);
void	check_error_line(t_list *list, int aux, int j, char *current_argv);
void	check_error_numbers(t_list *list, char **argv, int i, int j);
void	check_errors(t_bool is_error, t_list *list,
			char *current_argv, int aux);

/**
 * FIND_INSTRUCTIONS.C
 * */
t_bool	swap_instr(char *line, t_stacks stack, t_bool print);
t_bool	push_instr(char *line, t_stacks stack, t_bool print);
t_bool	rotate_instr(char *line, t_stacks stack, t_bool print);
t_bool	reverse_instr(char *line, t_stacks stack, t_bool print);

/**
 *  SWAP.C
 * */
void	swap_a(t_list **stack_a, t_bool print);
void	swap_b(t_list **stack_b, t_bool print);

/**
 * PUSH.c || push a - toma el primer elemento del stack b 
 * y lo pone encima del stack a.
 *	No hace nada si b está vacío.
 * */
void	push_a(t_stacks *stack, t_bool print);
void	push_b(t_stacks *stack, t_bool print);

/**
 * ROTATE = primer elemento se convierte en el último
 * */
void	rotate_a(t_list **stack_a, t_bool print);
void	rotate_b(t_list **stack_b, t_bool print);
void	rotate_all(t_list **stack_a, t_list **stack_b, t_bool print);

/**
 * REV_ROTATE = último elemento se convierte en el primero
 * */
void	rev_rotate_a(t_list **stack_a, t_bool print);
void	rev_rotate_b(t_list **stack_b, t_bool print);
void	rev_rotate_all(t_list **stack_a, t_list **stack_b, t_bool print);

/**
 * SORT THREE NUMBERS = 
 * 
 * */
void	sort_three_numbers(t_list *stack_a);

/**
 * SORT FIVE NUMBERS = 
 * 
 * */
int		get_position_smaller_number(t_list *stack_a);
void	push_smallest_number(int min, t_stacks *stack);
void	five_numbers(t_stacks *stack);

/**
 * UTILS
 * */
int		*get_number(int number);
int		is_elem_dup(t_list *list, char *str_number);
t_bool	is_sorted(t_list *stack_a, int length);
int		get_biggest_number_a(t_list *stack_a);
int		get_smallest_number_a(t_list *stack_a);

/**
 * UTILS2.C
 * 
 * */
void	print_stack(t_list *list, int size);

/**
 * RADIX  SORT
 * */
void	sort_max_10_nbr(t_stacks *stack);
void	radix_sort(t_stacks *stack);

#endif
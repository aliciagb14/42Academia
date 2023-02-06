/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:23:30 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/06 14:03:27 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"


#endif
/*
typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;*/

typedef struct s_stacks
{
	int size_a;
	int size_b;
	int	sorted_elem_a;
	int sorted_elem_b;
	int	nbr_count;
	int *nbr_act;
	t_list *stack_a;
	t_list *stack_b;
}				t_stacks;

/**
 * CHECK INPUT
 * */
void	read_input(t_list **list, char **argv);
void	check_error_line(t_list *list, int aux, int j, char *current_argv);
void 	check_error_numbers(t_list *list, char **argv, int i, int j);

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
 * PUSH.c || push a - toma el primer elemento del stack b y lo pone encima del stack a.
 *	No hace nada si b está vacío.
 * */
void	push_a(t_stacks *stack, t_bool print);
void	push_b(t_stacks *stack, t_bool print);

/**
 * ROTATE = primer elemento se convierte en el último
 * */
void	rotate_a(t_list **stack_a, t_bool print);
void	rotate_b(t_list **stack_b, t_bool print);

/**
 * REV_ROTATE = último elemento se convierte en el primero
 * */
void	rev_rotate_a(t_list **stack_a, t_bool print);
void	rev_rotate_b(t_list **stack_b, t_bool print);
void	rev_rotate_all(t_list **stack_a, t_list **stack_b, t_bool print);


int		is_elem_dup(t_list *list, char *str_number);
void	five_numbers(t_stacks *stack);
void	sort_three_numbers(t_list *stack_a, int size_a);

void	push_smallest_number(int min_index, t_stacks *stack);
int		get_position_smaller_number(t_list *stack_a);
int		*get_number(int number);

int		count_digits(int max);
int		get_smallest_number_a(t_list *stack_a);
int		get_biggest_number_a(t_list *stack_a);
void	radix_sort(t_stacks *stack); //t_list  *stack_a
t_bool	is_sorted(t_list *list, int length);
void	print_stack(t_list *list, int size);
void	print_zeros(int number_zeros);
int		get_max_bits(t_list *stack_a);
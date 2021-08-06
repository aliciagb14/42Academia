/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:17:17 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 14:06:16 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int			size_a;
	int			size_b;
	int			sorted_elem_a;
	int			sorted_elem_b;
	t_list_dbl	*stack_b;
	t_list_dbl	*stack_a;
}					t_stacks;

void	ft_inicialize(t_stacks *stack);
int		*get_number(int number);
void	print_stack(t_list_dbl *list);
void	circular_fun(t_list_dbl *list);
void	swap_a(t_list_dbl *list, t_bool print);
void	swap_b(t_list_dbl *list, t_bool print);
void	rotate_a(t_list_dbl **stack_a, t_bool print);
int		push_rotate_forwards_a(t_list *lista, int nb_swaps,
			t_stacks *stack);
int		push_rotate_backwards_a(t_list *lista, int nb_swaps,
			t_stacks *stack);
void	rotate_b(t_list_dbl **stack_b, t_bool print);
int		push_rotate_forwards_b(t_list *lista, int *tam_set, t_stacks *stack,
			int elem_cola_stack);
int		push_rotate_backwards_b(t_list *lista, int nb_swaps, t_stacks *stack,
			int *tam_set, int elem_cola_stack);
void	rev_rotate_a(t_list_dbl **stack_a, t_bool print);
void	rev_rotate_b(t_list_dbl **stack_b, t_bool print);
void	push_a(t_stacks *stack, t_bool print);
void	push_b(t_stacks *stack, t_bool print);
void	input(t_list_dbl **list, char **argv);
t_bool	is_elem_dup(t_list_dbl *list, char *number);
t_bool	is_sorted(t_list_dbl *list);
void	sort_a(t_list *subdivisions, t_stacks *stack);
void	sort_b(t_list *subdivisions, t_stacks *stack, int nb_swaps);
int		smaller_nb(t_stacks *stack);
void	three_numbers(t_list_dbl *stack_a, int size_a);
void	five_numbers(t_stacks *stack);
void	print_swap(unsigned int instruction, t_stacks *stack);
int		get_pivot(t_list_dbl *start, int size);
#endif
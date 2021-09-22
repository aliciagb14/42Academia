/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:17:17 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/22 14:53:27 by agonzale         ###   ########.fr       */
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

/*
**				UTILS.C
*/
int		*get_number(int number);
void	print_stack(t_list_dbl *list, int size);
t_bool	is_elem_dup(t_list_dbl *list, char *number);
t_bool	is_sorted(t_list_dbl *list);
t_bool	can_sort_a(t_stacks *stack);
t_bool	check_special_permutations(t_stacks *stack, int *tam_set, int *rotated_times);
void	circular_fun(t_list_dbl *list);
/*
**				SWAP.C
*/
void	swap_a(t_list_dbl *list, t_bool print);
void	swap_b(t_list_dbl *list, t_bool print);
/*
**				ROTATE.C
*/
void	rotate_a(t_list_dbl **stack_a, t_bool print);
void	rotate_b(t_list_dbl **stack_b, t_bool print);
/*
**				REV_ROTATE.C
*/
void	rev_rotate_a(t_list_dbl **stack_a, t_bool print);
void	rev_rotate_b(t_list_dbl **stack_b, t_bool print);
/*
**				PUSH.C
*/
void	push_a(t_stacks *stack, t_bool print);
void	push_b(t_stacks *stack, t_bool print);
/*
**				SORT_A.C
*/
void	sort_a(t_stacks *stack);
/*
**				SORT_B.C
*/
void	sort_b(t_list *subdivisions, t_stacks *stack);
void	three_numbers(t_list_dbl *stack_a, int size_a);
void	five_numbers(t_stacks *stack);
void	print_swap(unsigned int instruction, t_stacks *stack);
/*
**				SORTING.C
*/
int		get_pivot(t_list_dbl *init, int start, int end);
int		get_tail_stack(t_list_dbl *start);
int		smallest_nb(t_list_dbl *stack_a);
int		biggest_nb(t_list_dbl *stack_b);
/*
**					CHECKER.C
*/
void	execute_more_instr(char *line, t_stacks *stack);
void	execute_instr(char *line, t_stacks *stack);
void	read_input(t_stacks *stack);
#endif
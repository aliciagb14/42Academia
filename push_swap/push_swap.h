/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:17:17 by agonzale          #+#    #+#             */
/*   Updated: 2021/07/14 17:33:50 by agonzale         ###   ########.fr       */
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
	t_list_dbl	*stack_b;
	t_list_dbl	*stack_a;
}					t_stacks;

void	ft_inicialize(t_stacks *stack);
void	swap(t_list_dbl *list);
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rev_rotate_a(t_stacks *stack);
void	rev_rotate_b(t_stacks *stack);
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);
void	input(t_list_dbl **list, char **argv);
t_bool	is_elem_dup(t_list_dbl *list, char *number);
t_bool	is_sorted(t_list_dbl *list);
int		smaller_nb(t_stacks *stack);
void	three_numbers(t_list_dbl *stack_a, int size_a);
void	five_numbers(t_stacks *stack);
void	print_swap(unsigned int instruction, t_stacks *stack);
#endif
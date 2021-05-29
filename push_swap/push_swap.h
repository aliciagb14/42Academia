/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:17:17 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/29 19:23:39 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	t_list_dbl	*stack_b;
	t_list_dbl	*stack_a;
}					t_stacks;

void swap(t_list_dbl *list);
void rotate_a(t_stacks *stack);
void input(t_list_dbl **list, char **argv);
t_bool is_elem_dup(t_list_dbl *list, char *number);
t_bool is_sorted(t_list_dbl *list);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:17:17 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/29 14:23:21 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

void swap(t_list_dbl *list);
void input(t_list_dbl **list, char **argv);
t_bool is_elem_dup(t_list_dbl *list, char *number);
t_bool is_sorted(t_list_dbl *list);
#endif
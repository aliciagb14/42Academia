/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:41 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/06 14:06:38 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Intercambia primeros 2 elementos en la parte superior de la pila
*/
void	swap_a(t_list_dbl *list, t_bool print)
{
	int	*aux;

	if (!list || !list->next)
		return ;
	aux = list->content;
	list->content = list->next->content;
	list->next->content = aux;
	if (print)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	swap_b(t_list_dbl *list, t_bool print)
{
	int	*aux;

	if (!list || !list->next)
		return ;
	aux = list->content;
	list->content = list->next->content;
	list->next->content = aux;
	if (print)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

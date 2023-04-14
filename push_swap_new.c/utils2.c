/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:09:50 by agonzale          #+#    #+#             */
/*   Updated: 2023/04/05 12:33:00 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *list, int size)
{
	t_list	*aux;
	int		i;

	i = 0;
	aux = list;
	if (list == NULL)
		return ;
	if (list->next == NULL)
	{
		printf("%d \n", (*(int *)(list->content)));
		return ;
	}
	while ((aux || i == 0) && size > 1)
	{
		printf("%d \n", (*(int *)(aux)->content));
		aux = aux->next;
		i++;
	}
}

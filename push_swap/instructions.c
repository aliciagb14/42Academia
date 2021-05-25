/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:40:43 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 23:59:45 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool is_sorted(t_list_dbl *list)
{
	int i;

	i = 0;
	if (!list)
		return 0;
	while (list)
	{
		if (&list->next < &list->content)
		{
			ft_putstr_fd("Lista no ordenada", STDERR_FILENO);
			return false;
		}
		else
			return true;
		list->next;
	}
}
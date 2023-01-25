/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:55:09 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 14:17:12 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_number(int number)
{
	int	*ptr;

	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	*ptr = number;
	return (ptr);
}

int is_elem_dup(t_list *list, char *str_number)
{
	int aux;
	if (list)
	{
		aux = ft_atoi(str_number);
		while(list)
		{
			if((int *)list->content == &aux)
				return true;
			list = list->next;
		}
	}
	return (false);
}

/*aux que al inicio sea list, y me voy a mover con el aux,
hasta que aux de next = list*/
t_bool	is_sorted(t_list *list, int length)
{
	t_list	*aux;
	t_bool		first_iteration;
	int			i;

	i = 1;
	first_iteration = false;
	if (!list)
		return (0);
	if (!list->next)
		return (true);
	aux = list;
	while (i < length && (aux->next != list || !first_iteration))
	{
		if (*(int *)aux->content > *(int *)aux->next->content)
			return (false);
		aux = aux->next;
		first_iteration = true;
		i++;
	}
	return (true);
}

int	get_biggest_number_a(t_list *stack_a)
{
	int			max;
	int			max_index;
	int			i;

	i = 0;
	max = 0;
	while (stack_a->next != NULL || i == 0)
	{
		if (*(int*)(stack_a->content) > max)
		{
			max = *(int*)stack_a->content;
			max_index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (max);
}

int count_digits(int max)
{
	int count = 1;
	while(max / 10)
	{
		max /= 10;
		count++;
	}
	return (count);
}
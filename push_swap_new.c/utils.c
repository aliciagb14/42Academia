/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:55:09 by agonzale          #+#    #+#             */
/*   Updated: 2023/04/14 15:11:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_number(int number)
{
	int	*ptr;

	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	free(ptr);
	*ptr = number;
	return (ptr);
}

int	is_elem_dup(t_list *list, char *str_number)
{
	int	aux;

	if (list)
	{
		aux = ft_atoi(str_number);
		while (list)
		{
			if ((int *)list->content == &aux)
				return (true);
			list = list->next;
		}
	}
	return (false);
}

t_bool	is_sorted(t_list *stack_a, int length)
{
	t_list	*aux;
	int		i;

	i = 0;
	aux = stack_a;
	if (!stack_a)
		return (0);
	if (!stack_a->next)
		return (true);
	while (++i < length && (aux->next != stack_a))
	{
		if (!aux
			|| (aux->next && *(int *)aux->content > *(int *)aux->next->content))
			return (false);
		aux = aux->next;
	}
	return (true);
}

int	get_biggest_number_a(t_list *stack_a)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (stack_a != NULL || i == 0)
	{
		if (*(int *)(stack_a->content) > max)
			max = *(int *)stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	return (max);
}

int	get_smallest_number_a(t_list *stack_a)
{
	int		min;
	int		min_index;
	int		i;
	t_list	*aux;

	i = 0;
	min_index = 0;
	min = get_biggest_number_a(stack_a);
	aux = stack_a;
	while (aux)
	{
		if (*(int *)aux->content < min)
		{
			min = *(int *)aux->content;
			min_index = i;
		}
		aux = aux->next;
		i++;
	}
	return (min);
}

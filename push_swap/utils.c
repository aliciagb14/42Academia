/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:22:36 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/21 11:41:53 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list_dbl *list, int size)
{
	t_list_dbl	*aux;
	int i;

	i = 0;
	aux = list;
	if (list == NULL)
		return ;
	if (list->next == NULL)
	{
		printf("%i (prev == NULL)\n", (*(int *)(aux)->content));
		return ;
	}
	while (aux != list || i == 0)
	{
		printf("%i (prev = %i) \n", (*(int *)(aux)->content), (*(int *)(aux)->prev->content));
		aux = aux->next;
		i++;
	}
	printf("size = %d ", size);
}

void	circular_fun(t_list_dbl *list)
{
	t_list_dbl	*aux;

	aux = list;
	while (list->next != NULL)
	{
		list = list->next;
	}
	list->next = aux;
	aux->prev = list;
}

/*a contiene num aleatorio de enteros positivos o negativos duplicados
b vacio. Dejar los elementos en a*/

t_bool	is_elem_dup(t_list_dbl *list, char *number)
{
	int	aux;

	if (list)
	{
		aux = ft_atoi(number);
		while (list)
		{
			if (((int *)list->content)[0] == aux)
				return (true);
			list = list->next;
		}
	}
	return (false);
}

int	*get_number(int number)
{
	int	*ptr;

	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	*ptr = number;
	return (ptr);
}

/*aux que al inicio sea list, y me voy a mover con el aux,
hasta que aux de next = list*/
t_bool	is_sorted(t_list_dbl *list)
{
	t_list_dbl	*aux;
	t_bool first_iteration;

	first_iteration = false;
	if (!list)
		return (0);
	if (!list->next)
		return (true);
	aux = list;
	while (aux->next != list || !first_iteration)
	{
		if (((int *)aux->content)[0] >
			((int *)aux->next->content)[0])
			return (false);
		aux = aux->next;
		first_iteration = true;
	}
	return (true);
}

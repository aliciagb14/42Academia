/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:22:36 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/05 12:04:37 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list_dbl *list)
{
	t_list_dbl	*aux;

	aux = list;
	while (aux != list->prev)
	{
		printf("%i \n", ((int *)(aux)->content)[0]);
		aux = aux->next;
	}
	printf("%i \n", ((int *)(aux)->content)[0]);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:44:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/08 13:35:30 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 * Primero tengo que encontrar el numero mas grande y ver la cantidad de digitos que tiene
 * despues tendre que calcular la cantidad de 0s que tengo que añadir a la izq segun el numero
 * y tengo que añadir el x 0 al ppio de mi numero
 *  
 *  */

void radix_sort(t_stacks *stack)
{
	int j, i = 0;

	int max_bits = get_max_bits(stack->stack_a);
	while(i < max_bits)
	{
		j = 0;
		while(j++ < ft_lstsize(stack->stack_a))
		{
			if ((*(int *)stack->stack_a->content >> i) % 2 != 0)
				rotate_a(&stack->stack_a, true);
			else
				push_b(stack, true);
		}
		while(ft_lstsize(stack->stack_b) != 0)
			push_a(stack, true);
		i++;
	}
}

void	print_stack(t_list *list, int size)
{
	t_list	*aux;
	int			i;

	i = 0;
	aux = list;
	if (list == NULL)
		return ;
	if (list->next == NULL)
	{
		printf("%d \n", (*(int *)(list->content)));
		return ;
	}
	while ((aux || i == 0) && size > 1) //aux != list 
	{
		printf("%d \n", (*(int *)(aux)->content));
		aux = aux->next;
		i++;
	}
}

int	get_max_bits(t_list *stack_a)
{
	int		max;
	int		max_bits;

	max = ft_lstsize(stack_a) - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

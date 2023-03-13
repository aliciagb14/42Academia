/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:44:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/03/13 13:29:21 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 * Primero tengo que encontrar el numero mas grande y
 *  ver la cantidad de digitos que tiene
 * despues tendre que calcular la cantidad de 0s que tengo 
 * que añadir a la izq segun el numero
 * y tengo que añadir el x 0 al ppio de mi numero
 *  */

/**
 * Devuelve la posicion del primer elemento que encuentra en la lista igual
 * al num pasado por
 * */
int	find_num(t_list *stack, int num)
{
	t_list	*ptr1;
	int		count;

	count = 0;
	ptr1 = stack;
	while (ptr1->next != NULL)
	{
		if ((int)ptr1->content == num)
			return (count);
		ptr1 = ptr1->next;
		count++;
	}
	return (count);
}

void	sort_max_10_nbr(t_stacks *stack)
{
	int	min_index;

	min_index = get_position_smaller_number(stack->stack_a);
	while (stack->stack_a && stack->size_a > 3)
	{
		while (get_position_smaller_number(stack->stack_a) != 0)
		{
			if (get_position_smaller_number(stack->stack_a)
				<= (ft_lstsize(stack->stack_a) / 2))
				rotate_a(&stack->stack_a, true);
			else
				rev_rotate_a(&stack->stack_a, true);
		}
		if (get_position_smaller_number(stack->stack_a) == 0)
			push_b(stack, true);
	}
	sort_three_numbers(stack->stack_a);
	while (stack->stack_b)
		push_a(stack, true);
}

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = *(int *)head->content;
	max_bits = 0;
	while (head)
	{
		if (*(int *)head->content > max)
			max = *(int *)head->content;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/** se usa para comprobar si el iesimo bit del numero entero almacenado en el
* 1 elemento de stack a es 1, es decir, si el bit mas significativo es 1
*(i + 1)-th bit is 1, leave in stack a
*/

void	radix_sort(t_stacks *stacks)
{
	t_list	*head_a;
	int		digit_count;
	int		j;
	int		size;
	int		max_bits;

	digit_count = -1;
	head_a = stacks->stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(&stacks->stack_a);
	while (++digit_count < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = stacks->stack_a;
			if (((*(int *)head_a->content >> digit_count) & 1) == 1)
				rotate_a(&stacks->stack_a, true);
			else
				push_b(stacks, true);
		}
		while (ft_lstsize(stacks->stack_b) != 0)
			push_a(stacks, true);
	}
}

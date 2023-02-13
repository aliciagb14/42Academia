/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:44:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/13 14:40:52 by agonzale         ###   ########.fr       */
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

/*oid	ft_sort_max_10(t_list **stack_a, t_list **stack_b, t_cosas *cosas)
{
	cosas->stack_a_size = cosas->number_count;
	while (stack_a[0] && cosas->stack_a_size > 3)
	{
		while (find_num(stack_a[0], find_min(stack_a[0])) != 0)
		{
			if (find_num(stack_a[0], find_min(stack_a[0]))
				<= (ft_lstsize(stack_a[0]) / 2))
				rotate_a(stack_a);
			else
				rrotate_a(stack_a);
		}
		if (ft_is_ordered(stack_a[0]) == 1)
			break ;
		if (find_num(stack_a[0], find_min(stack_a[0])) == 0)
			push_b(stack_a, stack_b, cosas);
	}
	ft_sort_max_3(stack_a);
	while (stack_b[0])
		push_a(stack_a, stack_b, cosas);
}*/

void	sort_max_10_nbr(t_stacks *stack)
{
	int	min_index;

	min_index = get_position_smaller_number(stack->stack_a);
	while (stack->stack_a && stack->size_a > 3)
	{
		while (min_index != 0)
		{
			if (min_index <= (ft_lstsize(stack->stack_a) / 2))
				rotate_a(&stack->stack_a, true);
			else
				rev_rotate_a(&stack->stack_a, true);
		}
		if (!is_sorted(stack->stack_a, stack->size_a))
			if (min_index == 0)
				push_b(stack, true);
	}
	sort_three_numbers(stack->stack_a);
	while (stack->stack_b)
		push_a(stack, true);
}

void	radix_sort(t_stacks *stack)
{
	int	j;
	int	i;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(stack->stack_a);
	while (i < max_bits) //make_pow(ft_lstsize(stack->stack_a/*max_bits*/))
	{
		j = 0;
		while (j < ft_lstsize(stack->stack_a))
		{
			if ((*(int *)stack->stack_a->content >> i) % 2 != 0)
				rotate_a(&stack->stack_a, true);
			else
				push_b(stack, true);
			five_numbers(stack);
			j++;
		}
		while (ft_lstsize(stack->stack_b) != 0)
			push_a(stack, true);
		i++;
	}
	i = 0;
}

int	get_max_bits(t_list *stack_a)
{
	int	max;
	int	max_bits;

	max = ft_lstsize(stack_a) - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	make_pow(int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 2;
		i++;
	}
	return (i);
}

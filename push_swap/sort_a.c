/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:49:50 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/24 15:12:33 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Numeros ordenados se encuentran abajo del stack
** nb_swaps son los numeros q pusea a b, esta variable luego nos sirve
** 			para saber cuantos numeros componen la subdivision (tam)
** rotated times, numero de veces que pasa un numero (> pivote) a la cola del stack 
*/
int	push_rotate_forwards_a(unsigned long int *nb_swaps, t_stacks *stack)
{
	int	pivot;
	int	rotated_times;

	rotated_times = 0;
	pivot = get_pivot(stack->stack_a, 0, stack->size_a - stack->sorted_elem_a);
	while (rotated_times < stack->size_a - stack->sorted_elem_a)
	{
		if (*(int*)stack->stack_a->content <= pivot)
		{
			push_b(stack, true);
			(*nb_swaps)++;
		}
		else
		{
			rotate_a(&stack->stack_a, true);
			rotated_times++;
		}
	}
	// // // // //printf"\n------despues de forwards a--------------\n");
	// // //print-stack("\n(stack->stack_a,  stack->size_a);
	// // //print-stack("\n(stack->stack_b,  stack->size_b);
	// // // // //printf"\n--------------------\n");
	return (rotated_times);
}

/*
** Numeros ordenados se encuentran arriba del stack
**	si hay mas num desordenados que ordenados,
**	haces una rotacion para poder acceder a la  direccion con + facilidad
** si hay mas num ordenados 
*/
int	push_rotate_backwards_a(unsigned long int *nb_swaps, t_stacks *stack)
{
	int	pivot;
	int rotated_times;

	if (stack->sorted_elem_a && stack->sorted_elem_a < stack->size_a - stack->sorted_elem_a)
	{
		// //printf"Señora\n");
		while (stack->sorted_elem_a)
			rotate_a(&stack->stack_a, true);
		return (0);
	}
	rotated_times = stack->size_a - stack->sorted_elem_a;
	pivot = get_pivot(stack->stack_a, stack->sorted_elem_a, stack->size_a);
	while (rotated_times)
	{
		rev_rotate_a(&stack->stack_a, true);
		if (*(int*)stack->stack_a->content <= pivot)
		{
			push_b(stack, true);
			(*nb_swaps)++;
		}
		rotated_times--;
	}
	// // // // //printf"\n------despues de backwards a--------------\n");
	// // //print-stack("\n(stack->stack_a,  stack->size_a);
	// // // // //printf"\n--------------------\n");
	return (rotated_times);
}

/*
** Si el numero de elementos desordenados es > 3 y mientras
** existan numeros en la cola del stack, pasamos num a b
** comprobaremos si el numero de elementos de la cola es 0.
** si lo es, implica que los numeros ordenados estan abajo
** (subdivisions guarda cuantos numeros pushea a b en cada iteracion)
*/
void	sort_a(t_stacks *stack)
{
	unsigned long int		nb_swaps;
	t_list	*subdivisions;
	int		rotated_times;

	rotated_times = 0;
	subdivisions = NULL;
	while (stack->size_a - stack->sorted_elem_a > 3 || rotated_times)
	{
		nb_swaps = 0;
		if (rotated_times == 0)
			rotated_times = push_rotate_forwards_a(&nb_swaps, stack);
		else
			rotated_times = push_rotate_backwards_a(&nb_swaps, stack);
		if (nb_swaps)
			ft_lstadd_front(&subdivisions, ft_lstnew((void*)nb_swaps));
	}
	sort_three_numbers_full_stack_a(stack->stack_a, stack->size_a - stack->sorted_elem_a);
	stack->sorted_elem_a = stack->size_a;
	sort_b(subdivisions, stack);
}

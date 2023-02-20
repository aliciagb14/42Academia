/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:44:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/20 12:57:03 by agonzale         ###   ########.fr       */
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

// static int	get_max_bits(t_list *stack_a)
// {
// 	int	max;
// 	int	max_bits;

// 	max = ft_lstsize(stack_a) - 1;
// 	max_bits = 1;
// 	while ((max >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

int	make_pow(int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

/** se usa para comprobar si el iesimo bit del numero entero almacenado en el
* 1 elemento de stack a es 1, es decir, si el bit mas significativo es 1
*(i + 1)-th bit is 1, leave in stack a
*/

// void radix_sort(t_stacks *stacks)
// {
//     int max_digit_count = count_digits(get_biggest_number_a(stacks->stack_a));
//     int digit_index = 0;
//     while (digit_index < max_digit_count)
//     {
//         int divisor = make_pow(*(int*)stacks->stack_a->content);
//         int i, nbr_head_stack;
//         i = ft_lstsize(stacks->stack_a);
//         while (--i >= 0)
//         {
//             nbr_head_stack = *(int*)stacks->stack_a->content;
//             if ((nbr_head_stack / divisor) % 10 == 0)
//                 push_b(stacks, true);
//             else
//                 rotate_a(&stacks->stack_a, true);
// 			digit_index++;
// 		}
//         while (stacks->stack_b)
//             push_a(stacks, true);
//     }
// }


void	radix_sort(t_stacks *stacks)
{
	int		i;
	int		bpos;
	int		l;

	bpos = 0;
	l = ft_lstsize(stacks->stack_a);
	while (bpos < make_pow(l))
	{
		i = 0;
		while (i < l)
		{
			if ((((stacks->stack_a)->pos) >> bpos) % 2 != 0)
				rotate_a(&stacks->stack_a, true);
			else
				push_b(stacks, true);
			i++;
		}
		while (stacks->stack_b)
			push_a(stacks, true);
		bpos++;
	}
	bpos = 0;
}
// void radix_sort(t_stacks *stacks)
// {
//     int max_bits;
//     int i;
// 	int	j;
// 	int size;
// 	int nbr_head_stack;

//     size = stacks->size_a;
//     max_bits = get_max_bits(stacks->stack_a);
//     i = -1;
// 	j = -1;
// 	while (++i < max_bits)
// 	{
// 		while(++j < size)
// 		{
// 			nbr_head_stack = *(int*)stacks->stack_a->content;
// 			if (((nbr_head_stack >> i) & 1) == 1)
// 				rotate_a(&stacks->stack_a, true);
// 			else
// 				push_b(stacks, true);
// 		}
// 		while (!stacks->stack_b)
//   	    	push_a(stacks, true);
// 		j = -1;
// 	}
// }


// void radix_sort(t_stacks *stacks)
// {
//     int max_bits;
//     int i;
//     int j;
//     int size;
//     int max_nbr;
//     int nbr_head_stack;
//     size = ft_lstsize(stacks->stack_a);
//     max_nbr = get_biggest_number_a(stacks->stack_a);
//     max_bits = get_max_bits(stacks->stack_a);
//     i = 0;
//     while (i < max_bits)
//     {
//         j = 0;
//         while (j < size)
//         {
//             nbr_head_stack = *(int *)stacks->stack_a->content;
//             if (((nbr_head_stack >> i) & 1) == 1)
//                 rotate_a(&stacks->stack_a, true);
//             else
//                 push_b(stacks, true);
//             j++;
//         }
//         while (stacks->stack_b)
//             push_a(stacks, true);
//         i++;
//     }
// }


// void radix_sort(t_list **stack_a, t_list **stack_b)
// {
//     int max_digit_count = 0;
//     int num_iterations = 0;
//     int divisor = 1;
//     int i;
//     // encontrar el número con la cantidad máxima de dígitos
//     t_list *curr_node = *stack_a;
//     while (curr_node != NULL)
//     {
//         int num = (int)curr_node->content;
//         int digit_count = 0;
//         while (num > 0)
//         {
//             num /= 10;
//             digit_count++;
//         }
//         if (digit_count > max_digit_count)
//             max_digit_count = digit_count;
//         curr_node = curr_node->next;
//     }
//     // calcular la cantidad de iteraciones necesarias
//     num_iterations = max_digit_count;
//     // iterar por cada dígito, comenzando por el dígito menos significativo
//     for (i = 0; i < num_iterations; i++)
//     {
//         divisor = divisor * 10;
//         // dividir los números según el valor del dígito correspondiente
//         while (*stack_a != NULL)
//         {
//             int num = (int)(*stack_a)->content;
//             int digit_value = (num / divisor) % 2;
//             // colocar los números en la pila correspondiente
//             if (digit_value == 0)
//                 ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->content));
//             else
//                 ft_rotate(stack_a);
//             ft_pop(stack_a);
//         }
//         // pushear los números de stack_b de vuelta a stack_a
//         while (*stack_b != NULL)
//         {
//             ft_push(stack_a, (*stack_b)->content);
//             ft_pop(stack_b);
//         }
//     }
// }

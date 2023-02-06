/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:44:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/02/06 15:16:45 by agonzale         ###   ########.fr       */
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
	/*int biggest_nb = 0;
	int max_digits = 0;
	int number_zeros;
	char *str_numbers;
	long numbers;*/
	int j, i = 0;

	int max_bits = get_max_bits(stack->stack_a);
	/*biggest_nb = get_biggest_number_a(stack->stack_a);
	printf("El numero + grande es %d\n", biggest_nb);
	max_digits = count_digits(biggest_nb);
	printf("el numero de digitos del mayor num es %d\n", max_digits);*/

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
		/*number_zeros  = max_digits - count_digits(*(int*)stack->stack_a->content);
		int  number_digits = count_digits(*(int*)stack->stack_a->content);
		stack->nbr_count = number_zeros + number_digits;
		i++;
		printf("\nEl numero de ceros es: %d y el numero de digitos es %d\n", number_zeros, number_digits);
		while (number_digits < max_digits && stack->stack_a != NULL){
				stack->nbr_act = ft_strncat("0", stack->stack_a->content, number_digits);
				number_digits++;
		}
		printf("%d", stack->nbr_act);
		stack->stack_a = stack->stack_a->next;
		stack->nbr_act = ft_strjoin(str_numbers, stack->stack_a->content);
		numbers = ft_atoi(stack->nbr_act);
		printf("%ld", numbers);
		numbers = *(long *)malloc(sizeof(long) * stack->nbr_count);
		i++;
		printf("%d\n\n", *(int *)stack->stack_a->content); *///rellenar la cadena con 0s y almacenar
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
		printf("ERROR");
		return ;
	}
	while ((aux != list || i == 0) && size > 1)
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

/*void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}*/
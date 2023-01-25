/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:44:07 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 16:22:03 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 * Primero tengo que encontrar el numero mas grande y ver la cantidad de digitos que tiene
 * despues tendre que calcular la cantidad de 0s que tengo que añadir a la izq segun el numero
 * y tengo que añadir el x 0 al ppio de mi numero
 *  
 *  */

#include <stdio.h>

int main(int argc, char **argv)
{
	t_stacks stack;
	if (argc < 2)
		return (0);
	ft_memset(&stack, 0, sizeof(t_stacks));
	read_input(&stack.stack_a, argv);
	print_stack(stack.stack_a, stack.size_a);
	radix_sort(stack.stack_a);
	print_stack(stack.stack_a, stack.size_a);
	return 0;
}

void radix_sort(t_list *stack_a)
{
	int biggest_nb = 0;
	int max_digits = 0;
	int number_zeros;

	biggest_nb = get_biggest_number_a(stack_a);
	printf("El numero + grande es %d\n", biggest_nb);
	max_digits = count_digits(biggest_nb);
	printf("el numero de digitos del mayor num es %d\n", max_digits);

	while(stack_a)
	{
		number_zeros  = max_digits - count_digits(*(int*)stack_a->content);
		int  number_digits = count_digits(*(int*)stack_a->content);
		printf("El numero de ceros es: %d y el numero de digitos es %d\n", number_zeros, number_digits);
		while (number_digits < max_digits && stack_a != NULL){
			//while (number_zeros > 0){
				//int *ptr = calloc(number_zeros, sizeof(t_list));
				stack_a->content = ft_strjoin(calloc(number_zeros, sizeof(t_list)), stack_a->content);
				printf("%d\n", *(int *)stack_a->content); //rellenar la cadena con 0s y almacenar
		//		number_zeros--;
		//	}
			number_digits++;
		}
		stack_a = stack_a->next;
	}
}

void print_zeros(int number_zeros)
{
	while (number_zeros > 0){
		ft_putstr_fd("0", number_zeros);
		number_zeros--;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:57 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 12:01:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*radix: primero se busca el numero mayor y se miran cuantos digitos tiene
 si el numero > es el 100, el resto se rellenan con ceros a la izq
 primero nos fijamos para ordenar en las uniidades, luego decenas, centenas, etc



*/

/*void add_zeros_left(t_list *stack_a){
	
}

void sort_a(t_list *stack_a){
	int max_number = get_biggest_number_a(stack_a);
	int max_digits = count_digits(max_number);
	int number_zeros = 0;
	//scaamos el numero max de digitos que tiiene nuestri numero mas grande
	//tenemos q lograr que toodos los numeros tengan el mismo numero de digitos
	while((int) stack_a->content / 10){
		//numero de 0s que añadir a la izq de lo que tenemos
		number_zeros = max_digits - count_digits((int) stack_a->content);
		add_zeros_left(); //funcion para añadir x ceros a la izq
		stack_a = stack_a->next;
	}
}*/
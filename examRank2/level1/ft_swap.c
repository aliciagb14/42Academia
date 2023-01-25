/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:20:36 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 10:24:30 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
**	Write a function that swaps the contents of two integers the adresses of which
**	are passed as parameters.
*/

void ft_swap(int *a, int *b){
	int *aux;
	aux = a;
	a = b;
	b = aux;
	printf("%d, %d, %d", aux, a, b);
}

int main(){
	ft_swap(1, 2);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:50:16 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 10:01:46 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	Write a function that displays a string on the standard output.
**	The pointer passed to the function contains the address of the string's first
**	character.
*/

void ft_putstr(char *str){
	int i;
	i = -1;
	while(str[i++])
		write(1, &str[i], 1);
}

int main(){
	char *str = "Hola mundo";
	ft_putstr(str);
}
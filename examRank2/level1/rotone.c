/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:13:28 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 12:11:53 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**	Write a program that takes a string and displays it, replacing each of its
**	letters by the next one in alphabetical order.

**	'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

**	The output will be followed by a \n.

**	If the number of arguments is not 1, the program displays \n.
*/
#include <unistd.h>
#include <stdio.h>

int main(int argc,  char **argv){
	int i = 0;
	if (argc  == 2){
		while(argv[1][i]){
			if (argv[1][i] == 90 || argv[1][i] == 122)
				argv[1][i] = argv[1][i] - 25;
			else if ((argv[1][i] >= 65 && argv[1][i] <= 89) 
				||	(argv[1][i] >= 97&& argv[1][i] <= 121))
				argv[1][i] = argv[1][i] + 1;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
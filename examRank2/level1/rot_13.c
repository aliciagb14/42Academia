/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:58:44 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 11:12:59 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*
**	Write a program that takes a string and displays it, replacing each of its
**	letters by the letter 13 spaces ahead in alphabetical order.
**	'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
**	The output will be followed by a newline.

**	If the number of arguments is not 1, the program displays a newline.
*/

int main(int argc, char **argv){
	int i = 0;
	if (argc == 2){
		while(argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a'; //% 26 + 'A';
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = (argv[1][i] - 'A' + 13) % 26 + 'A'; //% 26 + 'a';
			write(1, &argv[1][i], 1);
			i++;
		}
	write(1, "\n", 1);
	return (0);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:13:16 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 12:24:01 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*
**	Write a program called search_and_replace that takes 3 arguments, the first
**	arguments is a string in which to replace a letter (2nd argument) by
**	another one (3rd argument).

**	If the number of arguments is not 3, just display a newline.

**	If the second argument is not contained in the first one (the string)
**	then the program simply rewrites the string followed by a newline.
*/

int main(int argc, char **argv){
	int i = 0;
	if (argc == 4 && !argv[2][1] && argv[3][1]){
		while (argv[1][i]){
			if (argv[1][i] == argv[2][0])
				argv[1][i] = argv[3][0];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
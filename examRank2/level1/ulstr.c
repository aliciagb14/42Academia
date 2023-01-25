/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:24:35 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 12:30:49 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Write a program that takes a string and reverses the case of all its letters.
**	Other characters remain unchanged.

**	You must display the result followed by a '\n'.

**	If the number of arguments is not 1, the program displays '\n'.
**
*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
	int i = 0;
	if (argc == 2){
		while(argv[1][i]){
			if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] += 32;
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] -= 32;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
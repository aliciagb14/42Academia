/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:06:50 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 09:06:58 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**	Write a program that takes a string and displays its first word, followed by a
**	newline.

**	A word is a section of string delimited by spaces/tabs or by the start/end of
**	the string.

**	If the number of parameters is not 1, or if there are no words, simply display
**	a newline.
*/

#include <unistd.h>

int main(int argc, char **argv){
	int i;
	i = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2){
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i++;
		while ((argv[1][i] != 32 && argv[1][i] != 9) && argv[1][i]){
			write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
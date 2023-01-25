/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:25:21 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 10:42:17 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
/*
**	Write a program called repeat_alpha that takes a string and display it
**	repeating each alphabetical character as many times as its alphabetical index,
**	followed by a newline.

**	'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

**	Case remains unchanged.

**	If the number of arguments is not 1, just display a newline.
*/

int main(int argc, char **argv){
	int i = 0;
	if (argc == 2){
		while(argv[1][i] != '\0'){
			if (argv[1][i] >= 97 && argv[1][i] <= 122){ //minusculas
				for(int j = 0; j < argv[1][i] - 96; j++)
					write(1, &argv[1][i], 1);
			}
			else if (argv[1][i] >= 65 && argv[1][i] <= 90) //mayusculas
				for(int k = 0; k < argv[1][i] - 64; k++)
					write(1, &argv[1][i], 1);
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
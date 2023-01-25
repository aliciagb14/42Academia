/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:59:41 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 13:16:10 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	Write a program that takes a single string in lowerCamelCase format
**	and converts it into a string in snake_case format.

**	A lowerCamelCase string is a string where each word begins with a capital letter
**	except for the first one.

**	A snake_case string is a string where each word is in lower case, separated by
**	an underscore "_".
*/

int main(int argc, char **argv){
	int i = 0;
	if (argc == 2){
		while(argv[1][i]){
			if (argv[1][i] >= 65 && argv[1][i] <= 90){
				argv[1][i] += 32;
				write(1, "_", 1);
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:44:43 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 10:58:28 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
/*
**	Write a program that takes a string, and displays the string in reverse
**	followed by a newline.

**	If the number of parameters is not 1, the program displays a newline.
*/

int main(int argc, char **argv){
	int len = 0;

	if(argc == 2){
		while(argv[1][len])
			len++;
		for (int i = len - 1; i < argv[1][i] && i > 0; i--){
			write(1, &argv[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:16:10 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 10:19:17 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
/*
**	Write a function that returns the length of a string.
*/

int ft_strlen(char *str){
	int i;
	i = 0;
	while(str[i])
		i++;
	return i;
}

int main(){
	char *str = "Hola Mundo";
	int len = ft_strlen(str);
	printf("%d", len);
}
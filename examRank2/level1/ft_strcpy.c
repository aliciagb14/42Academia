/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:02:48 by agonzale          #+#    #+#             */
/*   Updated: 2022/10/03 10:20:20 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
/*
**	Copia la cadena a la que apunta src ,
**  incluyendo el byte nulo de terminación ('\0'), al búfer apuntado
**  a por dest . Las cadenas no pueden superponerse y el destino
**  string dest debe ser lo suficientemente grande para recibir la copia

**	char *strcpy(char *dest. char *src)
*/

char    *ft_strcpy(char *dest, char *src){
	int i = 0;

	while(src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int main(){
	char *s1 = "Hola mundo";
	char *s2 = "Adios";
	char *sfin = ft_strcpy(s1, s2);
	printf("%s", sfin);
}
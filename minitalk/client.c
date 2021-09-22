/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:02:10 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/22 08:23:49 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	int pid;

	if (argc != 2)
	{
		printf("client:  invalid arguments\n");
		exit(EXIT_FAILATURE);
	}
	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
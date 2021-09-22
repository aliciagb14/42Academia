/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:02:25 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/22 08:23:49 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_sigusr1(int signum)
{
	printf("signal %d received.\n", signum);
}

int main()
{
	int pid,

	pid = getpid(),
	signal(SIGUSR1, handle_sigusr1);
	exit(-1);
}
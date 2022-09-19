/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:39:39 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/19 08:29:56 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//end[1] padre, end[0] hijo
/*
** First and foremost, we need to parse this PATH variable 
** (with the ft_strnstr, ft_substr and ft_split functions of our libft !), using “:” as a delimiter.
*/

int check_error(pid_t pid){
	if (pid == -1)
        return (1);
    if (pid == 0)
    {
        printf("Child: I'm the child, my internal pid is %d.\n", pid);
        printf("Child: Done!\n");
    }
    else if (pid > 0)
    {
        printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
        while (1) // Infinite loop, the parent will never end !
            usleep(1);
    }
}

void close_fd(t_pipex *tube){
	if(close(tube->pipefd[0]) == 0 && close(tube->pipefd[1]) == 0)
		printf("Files closed correctly");
}

void	msg_error(char *error)
{
	perror(error);
	exit (1);
}
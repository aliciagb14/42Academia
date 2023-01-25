/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:39:39 by agonzale          #+#    #+#             */
/*   Updated: 2023/01/25 08:10:35 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//end[1] padre, end[0] hijo
/*
** First and foremost, we need to parse this PATH variable 
** (with the ft_strnstr, ft_substr and ft_split functions of our libft !), using “:” as a delimiter.
*/

void	close_fd(t_pipex *tube){
	if(close(tube->pipefd[0]) == 0 && close(tube->pipefd[1]) == 0)
		printf("Files closed correctly");
}

void	msg_error(char *error)
{
	perror(error);
	exit (1);
}

void	print_msg_error(char *error){
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	frees_process(t_pipex pipex){
	while(pipex.path){
		free(pipex.path);
	}
}

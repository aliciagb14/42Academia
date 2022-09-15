/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:01:27 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/15 09:58:11 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	We are going to read file1 command1 command2 file2" that traduces like:
**	<file1 command1 | file2 command2>
*/

void pathfile(){
	
}

int main(int argc, char **argv, char **envp)
{
    pid_t pid, pid_infile, pid_child;
	t_pipex tube;
	tube.pid_infile = getpid(); //obtener pid del 1 fichero introducido
	if (tube.pipefd[0])
		printf("We are going to start to read");
    pid = fork();
	pid_child = check_error(pid);
    close_fd(&tube);
    return (0);
}
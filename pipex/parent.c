/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:52:09 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/19 12:03:03 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parent_work(t_pipex tube){
	close(tube.pipefd[0]);
	close(tube.pipefd[1]);
	close(tube.fd_infile);
	close(tube.fd_outfile);
	waitpid(tube.pid_first_child, NULL, 0);
	waitpid(tube.pid_second_child, NULL, 0);
}

/*
WIFEXITED(status): devuelve verdadero si el hijo salió normalmente, 
ya sea a través del retorno principal o un código de error.
WEXITSTATUS(status): devuelve el código de salida del niño. 
Ese código puede indicar si la ejecución del niño terminó bien o si hubo un error. 
Esta macro solo tiene sentido si se WIFEXITED devuelve verdadera.
*/
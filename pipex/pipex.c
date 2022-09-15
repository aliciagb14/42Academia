/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:01:27 by agonzale          #+#    #+#             */
/*   Updated: 2022/09/15 12:18:47 by agonzale         ###   ########.fr       */
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
	char *string_aux1;
	t_pipex pipex;
	
    if (argc != 5)
		msg_error(ERR_ARGS);
	pipex.fd_infile = fopen(argv[1], O_RDONLY);
	if (pipex.fd_infile < 0)
		msg_error(ERR_INFILE);
	pipex.fd_outfile = fopen(argv[4], O_TRUNC | O_WRONLY | O_RDWR);
	if (pipex.fd_outfile < 0)
		msg_error(ERR_OUTFILE);
	
}

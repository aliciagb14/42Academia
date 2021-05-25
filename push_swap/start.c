/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:08:21 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 23:56:22 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*a contiene num aleatorio de enteros positivos o negativos duplicados
b vacio. Dejar los elementos en a*/

int main(int argc, char **argv)
{
	int i;
	int j;
	int *number;
	t_list_dbl *list;

	list = NULL;
	i = 1;

	if (argc == 1)
		return (0);
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
			input(list, argv, i, j, number);
		i++;
	}
}

void input(t_list_dbl *list, char **argv, int i, int j, int *number)
{
	int aux;

	aux = j;
	if (argv[i][j] == '-' || argv[i][j] == '+')
		j++;
	while(argv[i][j] && !ft_isspace(argv[i][j]))
	{
		if (!ft_isdigit(argv[i][j]))
		{
			ft_putstr_fd("KO", STDERR_FILENO);
			ft_lstdbl_clear(&list, free);
		}
		j++;
	}
	if (ft_atoi(&argv[i][aux]) > 2147483647)
		ft_putstr_fd("Error", STDERR_FILENO);
	number = (int *)malloc(sizeof(int));
	*number = ft_atoi(&argv[i][aux]);
	if (is_elem_dup(&list, number) == false)
		ft_lstdbl_add_back(&list, ft_lstdbl_new(number));
	else
		ft_putstr_fd("Error", STDERR_FILENO);
}

t_bool is_elem_dup(t_list_dbl *list,int *number)
{
	while (list)
	{
		if(&list->content[0] == number)
			return true;
		list->next;
	}
}
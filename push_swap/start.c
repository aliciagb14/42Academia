/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:08:21 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/29 15:08:02 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*a contiene num aleatorio de enteros positivos o negativos duplicados
b vacio. Dejar los elementos en a*/

t_bool is_elem_dup(t_list_dbl *list, char *number)
{
	int aux;

	if (list)
	{
		aux = ft_atoi(number);
		while (list)
		{
			if(((int *)list->content)[0] == aux)
				return true;
			list = list->next;
		}
	}
	return false;
}

int *get_number(int number)
{
	int *ptr;
	
	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	*ptr = number;
	return (ptr);
}

void check_error(t_list_dbl **list, int aux, int j, char *current_argv)
{
	t_bool is_error;

	is_error = false;
	if (current_argv[aux] == '-')
	{
		if (j - aux >= 11 && ft_strncmp(&current_argv[aux], "-2147483648", 12) > 0)
			is_error = true;
	}
	else
	{
		if (current_argv[aux] == '+')
			aux++;
		if (j - aux >= 10 && ft_strncmp(&current_argv[aux], "2147483647", 11) > 0)
			is_error = true;
	}
	if (is_elem_dup(list[0], &current_argv[aux]))
		is_error = true;
	if (is_error)
	{
		ft_putstr_fd("Error", STDERR_FILENO);
		ft_lstdbl_clear(list, free);
		exit(-1);
	}
}

void input(t_list_dbl **list, char **argv)
{
	int aux;
	int i;
	int j;
	
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			aux = j;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			while(argv[i][j] && !ft_isspace(argv[i][j]))
			{
				if (!ft_isdigit(argv[i][j]))
				{
					ft_putstr_fd("KO", STDERR_FILENO);
					ft_lstdbl_clear(list, free);
				}
				j++;
			}
			check_error(list, aux, j, argv[i]);
			ft_lstdbl_add_back(list, ft_lstdbl_new(get_number(ft_atoi(&argv[i][aux]))));
		}
		i++;
	}
}

void print_stack(t_list_dbl *list)
{
	while (list)
	{
		printf("%i \n", ((int *)(list)->content)[0]);
		list = list->next;
	}
}

int main(int argc, char **argv)
{
	t_list_dbl *list;

	list = NULL;
	if (argc == 1)
		return (0);
	input(&list, argv);
	printf("Original\n");
	print_stack(list);
	printf("\nSwap \n");
	swap(list);
	print_stack(list);
}
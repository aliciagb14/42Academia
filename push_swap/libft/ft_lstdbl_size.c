/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:57:51 by agonzale          #+#    #+#             */
/*   Updated: 2021/09/28 07:57:39 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstdbl_size(t_list_dbl *lst)
{
	int			size;
	t_list_dbl	*aux;

	aux = lst;
	size = 0;
	while (lst && (size == 0 || lst != aux))
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

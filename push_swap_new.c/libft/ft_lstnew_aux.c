/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:29:34 by agonzale          #+#    #+#             */
/*   Updated: 2023/03/08 11:23:08 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_aux(void *content, int pos)
{
	t_list	*lista;

	lista = malloc(sizeof(t_list));
	if (lista == 0)
		return (0);
	lista->content = (void *)content;
	lista->pos = pos;
	lista->next = NULL;
	return (lista);
}

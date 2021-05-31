/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:57:59 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:58:02 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_dbl	*ft_lstdbl_new(void *content)
{
	t_list_dbl	*new_elem;

	if (!content)
		return (NULL);
	new_elem = (t_list_dbl *)malloc(sizeof(t_list_dbl));
	if (new_elem == NULL)
	{
		free(content);
		return (NULL);
	}
	new_elem->content = (void *)content;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

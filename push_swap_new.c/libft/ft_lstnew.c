/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:40:23 by rprieto-          #+#    #+#             */
/*   Updated: 2023/03/08 11:13:39 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	if (!content)
		return (NULL);
	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem == NULL)
	{
		free(content);
		return (NULL);
	}
	new_elem->content = (void *)content;
	new_elem->pos = -1;
	new_elem->next = NULL;
	return (new_elem);
}

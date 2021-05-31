/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:56:29 by agonzale          #+#    #+#             */
/*   Updated: 2021/05/25 12:56:32 by agonzale         ###   ########.fr       */
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
	new_elem->next = NULL;
	return (new_elem);
}

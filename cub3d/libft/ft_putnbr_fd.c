/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:06:20 by agonzale          #+#    #+#             */
/*   Updated: 2021/01/04 14:06:28 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_copy;

	n_copy = n;
	if (n_copy < 0)
	{
		n_copy = -n_copy;
		ft_putchar_fd('-', fd);
	}
	if (n_copy > 9)
	{
		ft_putnbr_fd(n_copy / 10, fd);
		ft_putchar_fd(n_copy % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n_copy + 48, fd);
}

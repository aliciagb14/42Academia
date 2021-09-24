/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:44:29 by rprieto-          #+#    #+#             */
/*   Updated: 2021/03/30 21:09:28 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int n)
{
	long	nbr;
	int		len;

	if (n == 0)
		len = 1;
	else
		len = 0;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:28:37 by notraore          #+#    #+#             */
/*   Updated: 2017/03/14 10:55:58 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int j;

	j = nb;
	if (nb <= 2)
		return (2);
	while (!(ft_is_prime(nb)))
	{
		nb++;
	}
	return (nb);
}

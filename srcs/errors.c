/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:21:33 by notraore          #+#    #+#             */
/*   Updated: 2017/09/12 17:21:34 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			ft_help(void)
{
	ft_putendl("usage : ./wolf3d [.map]");
	exit(EXIT_FAILURE);
}

void			ft_print_err(int argc)
{
	if (argc > 2)
		write(2, "\n\t\t\t*****Too many arguments.*****\n", 34);
	if (argc < 2)
		ft_putendl("Please. Enter a map name to display.");
	ft_help();
}

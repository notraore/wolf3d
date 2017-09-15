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
	ft_putstr("You can Created a map using 0 for walkable ");
	ft_putendl("floor and 1 for walls.");
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

void			ft_print_player_pos_error(t_all *all)
{
	if (all->one_x > 1)
		ft_kill("Too many 'x' on your map. Only one 'x' can be placed.");
	if (all->one_x < 1)
	{
		ft_putstr("None 'x' found on your map. Please, make sure an 'x' ");
		ft_kill("is marked where you want the player to start.");
	}
}

void			check_file(t_all *all)
{
	int i;
	int j;
	int last;

	i = 0;
	j = 0;
	last = all->i - 1;
	while (j < all->j)
	{
		i = 0;
		while (i < all->i)
		{
			if (j == 0 || j == all->j)
			{
				if (all->map[j][i] == 0)
					ft_kill("Map not well closed. Please check map borders.");
			}
			if (all->map[j][0] == 0 || all->map[j][last] == 0)
				ft_kill("Map not well closed. Please check map borders.");
			i++;
		}
		j++;
	}
	ft_print_player_pos_error(all);
}

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
	ft_putendl("usage : ./wolf3d [map]");
	ft_putstr("You can create a map using 0 for walkable ");
	ft_putendl("floor and 1 for walls.");
	exit(EXIT_FAILURE);
}

void			ft_print_err(int argc)
{
	if (argc > 2)
		write(2, "The game can launch only one map at once.\n", 42);
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

void			map_size(t_all *all)
{
	if (all->j <= 2)
		ft_kill("Map need to have at least 3 or more lines.");
	if (*all->taille <= 2)
		ft_kill("Map need to have at least 3 or more columns.");
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
				if (all->map[j][i] != 1 || all->map[all->j - 1][i] != 1)
					ft_kill("Map not well closed. Please check map borders.");
			if (all->map[j][0] != 1 || all->map[j][last] != 1)
				ft_kill("Map not well closed. Please check map borders.");
			i++;
		}
		j++;
	}
	map_size(all);
	ft_print_player_pos_error(all);
}

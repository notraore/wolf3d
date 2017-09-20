/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:13:32 by notraore          #+#    #+#             */
/*   Updated: 2017/09/20 15:13:33 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			menu(int keycode, t_all *all)
{
	if (all->go == 1)
	{
		if ((keycode == 13 || keycode == 126) && all->go == 1)
			all->arrpos = (all->arrpos <= 0) ? 200 : all->arrpos - 100;
		if ((keycode == 1 || keycode == 125) && all->go == 1)
			all->arrpos = (all->arrpos < 200) ? all->arrpos + 100 : 0;
		if (keycode == 36)
		{
			if (all->arrpos == 0)
				all->go = 2;
			if (all->arrpos == 100)
			{
				all->compet = 1;
				all->go = 2;
			}
			system("killall afplay 2&>/dev/null >/dev/null\n \
			afplay ./song/ingame.mp3&");
			all->ammo = (all->compet == 1) ? 3 : 300;
			if (all->arrpos == 200)
				proper_exit(all);
		}
	}
}

int				ft_tile_screen(t_all *all)
{
	if (all->go == 0 && all->game == 0)
	{
		mlx_put_image_to_window(all->e->mlx, all->e->win, all->tile, 0, 0);
		if (all->loop <= 40)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 110, H - 100,
			WHITE, "PRESS ANY KEY TO START");
	}
	if (all->go == 1 && all->game == 0)
	{
		mlx_put_image_to_window(all->e->mlx, all->e->win, all->mainmenu, 0, 0);
		mlx_put_image_to_window(all->e->mlx, all->e->win, all->arrow,
		W / 2 - 120 + all->loop, 230 + all->arrpos);
	}
	all->loop = all->loop >= 80 ? 0 : all->loop + 1;
	display_help(all);
	return (0);
}

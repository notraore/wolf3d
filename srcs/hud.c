/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:24:14 by notraore          #+#    #+#             */
/*   Updated: 2017/09/14 16:24:16 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			ft_draw_minimap(t_all *all)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 20;
	y = 20;
	while (j < all->j)
	{
		i = 0;
		while (i < all->i)
		{
			if (all->map[j][i] == 1 && (x > 0 && x < W) && (y > 0 && y < H))
				all->e->img_datas[x + y * W] = WHITE;
			i++;
			x += 4;
		}
		j++;
		x = 20;
		y += 4;
	}
}

void			ft_map_reticule_hud(t_all *all)
{
	if (all->hide_hud == 0)
	{
		all->clr = RED;
		draw_circle(W / 2, H / 2, all->reticule, all);
		all->clr = WHITE;
		draw_circle(W - 150, 600, 100, all);
		all->clr = GREEN;
		draw_circle(W - 150, 600, 3, all);
		all->clr = WHITE;
		draw_circle(W - 150, 600, all->radar, all);
		if (all->radar >= 100)
			all->radar = 4;
	}
}

void			hud_loop_update(t_all *all)
{
	all->radar += 0.001;
	if (all->reticule > 5)
		all->reticule -= 0.001;
}

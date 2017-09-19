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
	y = 50;
	while (j < all->j)
	{
		i = 0;
		while (i < all->i)
		{
			if (all->map[j][i] != 0 && (x > 0 && x < W) && (y > 0 && y < H))
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
		all->clr = GREEN;
		draw_circle(W - 200, 200, 3, all);
		all->clr = WHITE;
		if (all->radar <= 50)
			all->clr = ORG;
		if (all->radar <= 20)
			all->clr = RED;
		draw_circle(W - 200, 200, all->radar, all);
	}
}

void			hud_loop_update(t_all *all)
{
	// all->radar -= 0.00006;
	if (all->reticule > 5)
		all->reticule -= 0.001;
}

void			fire_reticule(t_all *all)
{
	if (all->fire == 1)
		all->reticule = 20;
	mlx_put_image_to_window(all->e->mlx, all->e->win,
	all->gun_1, W / 2, 400);
	system("afplay ./song/fire.mp3&");
}

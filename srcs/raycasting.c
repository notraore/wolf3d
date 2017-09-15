/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:04:13 by notraore          #+#    #+#             */
/*   Updated: 2017/09/11 10:04:15 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		step_side_nbr(t_all *all)
{
	if (all->p->raydirx < 0)
	{
		all->m->stepx = -1;
		all->m->sidedistx = (all->p->rayposx - all->m->mapx)
		* all->m->deltadistx;
	}
	else
	{
		all->m->stepx = 1;
		all->m->sidedistx = (all->m->mapx + 1.0 - all->p->rayposx)
		* all->m->deltadistx;
	}
	if (all->p->raydiry < 0)
	{
		all->m->stepy = -1;
		all->m->sidedisty = (all->p->rayposy - all->m->mapy)
		* all->m->deltadisty;
	}
	else
	{
		all->m->stepy = 1;
		all->m->sidedisty = (all->m->mapy + 1.0 - all->p->rayposy)
		* all->m->deltadisty;
	}
}

void		ray_lenght(t_all *all)
{
	while (all->m->hit == 0)
	{
		if (all->m->sidedistx < all->m->sidedisty)
		{
			all->m->sidedistx += all->m->deltadistx;
			all->m->mapx += all->m->stepx;
			all->m->side = 0;
		}
		else
		{
			all->m->sidedisty += all->m->deltadisty;
			all->m->mapy += all->m->stepy;
			all->m->side = 1;
		}
		if (all->map[all->m->mapx][all->m->mapy] > 0)
			all->m->hit = 1;
	}
	if (all->m->side == 0)
		all->m->perpwalldist = 0.2 + (all->m->mapx - all->p->rayposx +
		(1 - all->m->stepx) / 2) / all->p->raydirx;
	else
		all->m->perpwalldist = 0.2 + (all->m->mapy - all->p->rayposy +
		(1 - all->m->stepy) / 2) / all->p->raydiry;
}

void		ray_draw(t_all *all, int x)
{
	int lineheight;
	int drawstart;
	int drawend;

	lineheight = (int)(H / all->m->perpwalldist);
	drawstart = -lineheight / 2 + H / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + H / 2;
	if (drawend >= H)
		drawend = H - 1;
	ft_line(all, x, drawstart, drawend);
}

void		raycast(t_all *all)
{
	int x;

	x = -1;
	all->p->rayposx = all->p->posx;
	all->p->rayposy = all->p->posy;
	while (++x < W)
	{
		all_init(all, x);
		step_side_nbr(all);
		ray_lenght(all);
		ray_draw(all, x);
		hud_loop_update(all);
	}
}

int			ft_loop(t_all *all)
{
	all->p->last_frame = clock();
	if (all->p->next_frame > all->p->last_frame)
		return (0);
	all->p->next_frame = all->p->last_frame + (CLOCKS_PER_SEC / 100);
	raycast(all);
	if (all->hide_map == 1)
		ft_draw_minimap(all);
	mlx_put_image_to_window(all->e->mlx, all->e->win, all->e->img, 0, 0);
	if (all->reticule <= 10)
		mlx_put_image_to_window(all->e->mlx, all->e->win, all->gun_0, W / 2, 400);
	return (0);
}

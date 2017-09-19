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
}

void		ray_draw(t_all *all, int x)
{
	if (all->m->side == 0)
		all->m->perpwalldist = (all->m->mapx - all->p->rayposx +
		(1 - all->m->stepx) / 2) / all->p->raydirx;
	else
		all->m->perpwalldist = (all->m->mapy - all->p->rayposy +
		(1 - all->m->stepy) / 2) / all->p->raydiry;
	all->lineheight = (int)(H / all->m->perpwalldist);
	all->drawstart = -all->lineheight / 2 + H / 2;
	if (all->drawstart < 0)
		all->drawstart = 0;
	all->drawend = all->lineheight / 2 + H / 2;
	if (all->drawend >= H)
		all->drawend = H - 1;
	ft_line(all, x, all->drawstart, all->drawend);
}

void		raycast(t_all *all)
{
	all->x = 0;
	move(all);
	all->time = clock();
	if (all->go == 1)
	{
		while (all->x < W)
		{
			init_screen(all, all->x);
			init_map(all);
			step_side_nbr(all);
			ray_lenght(all);
			ray_draw(all, all->x);
			hud_loop_update(all);
			all->x += 1;
		}
		all->oldtime = all->time;
		all->time = clock();
		all->p->movespeed = 10 * ((double)(all->time - all->oldtime)
		/ CLOCKS_PER_SEC);
		all->p->rotspeed = 5 * ((double)(all->time - all->oldtime)
		/ CLOCKS_PER_SEC);
		all->fps = 60 / ((double)(all->time - all->oldtime)
		/ CLOCKS_PER_SEC);
	}
}

int			ft_loop(t_all *all)
{
	ft_tile_screen(all);
	if (all->go == 1)
	{
		all->game += 1;
		if (all->radar > 0)
			raycast(all);
		if (all->hide_map == 1)
			ft_draw_minimap(all);
		ft_map_reticule_hud(all);
		mlx_put_image_to_window(all->e->mlx, all->e->win, all->e->img, 0, 0);
		if (all->reticule <= 15)
			mlx_put_image_to_window(all->e->mlx, all->e->win, all->gun_0, W / 2
			+ (all->hand_h / 2), 400 + all->hand_h);
		loop_hud(all);
		mlx_string_put(all->e->mlx, all->e->win, 55, 10,
		WHITE, ft_itoa(all->fps));
		if (all->radar <= 0)
			ft_game_over(all);
		if ((int)all->p->posx == 3)
			ft_ggwp(all);
	}
	return (0);
}

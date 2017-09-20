/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:04:51 by notraore          #+#    #+#             */
/*   Updated: 2017/09/11 10:04:51 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			ft_mlx(t_all *all)
{
	all->e->mlx = mlx_init();
	load_texture_pack_2(all);
	all->e->win = mlx_new_window(all->e->mlx, W, H, "WOLF3D");
	all->e->img_datas = (int *)mlx_get_data_addr(all->e->img,
	&(all->e->bpp), &(all->e->sl), &(all->e->end));
}

void			init_screen(t_all *all, int x)
{
	all->p->camx = 2 * x / (double)W - 1;
	all->p->rayposx = all->p->posx;
	all->p->rayposy = all->p->posy;
	all->p->raydirx = all->p->dirx + all->p->planex * all->p->camx;
	all->p->raydiry = all->p->diry + all->p->planey * all->p->camx;
}

void			init_map(t_all *all)
{
	all->m->mapx = (int)all->p->rayposx;
	all->m->mapy = (int)all->p->rayposy;
	all->m->deltadistx = sqrt(1 + (all->p->raydiry * all->p->raydiry)
	/ (all->p->raydirx * all->p->raydirx));
	all->m->deltadisty = sqrt(1 + (all->p->raydirx * all->p->raydirx)
	/ (all->p->raydiry * all->p->raydiry));
	all->m->hit = 0;
}

void			init_player(t_all *all)
{
	all->p->dirx = -1;
	all->p->diry = 0;
	all->p->planex = 0;
	all->p->planey = 0.66;
	all->hide_map = 1;
	all->time = 0;
	all->oldtime = 0;
	all->reticule = 5;
	all->radar = 100;
}

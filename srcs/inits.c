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

void		all_init(t_all *all, int x)
{
	all->m->mapx = (int)all->p->rayposx;
	all->m->mapy = (int)all->p->rayposy;
	all->p->camx = 2 * x / (double)W - 1;
	all->p->raydirx = all->p->dirx + all->p->planex * all->p->camx;
	all->p->raydiry = all->p->diry + all->p->planey * all->p->camx;
	all->m->deltadistx = sqrt(1 + (all->p->raydiry * all->p->raydiry)
	/ (all->p->raydirx * all->p->raydirx));
	all->m->deltadisty = sqrt(1 + (all->p->raydirx * all->p->raydirx)
	/ (all->p->raydiry * all->p->raydiry));
	all->m->hit = 0;
	all->m->side = -1;
	all->m->perpwalldist = -1;
}

void		init_player(t_all *all)
{
	all->hide_map = 1;
	all->p->dirx = -1;
	all->p->diry = 0;
	all->p->planex = 0;
	all->p->planey = 0.66;
	all->p->last_frame = clock();
	all->p->next_frame = 0;
	all->p->movespeed = 0.15;
	all->p->rotspeed = 0.05;
	all->reticule = 5;
}

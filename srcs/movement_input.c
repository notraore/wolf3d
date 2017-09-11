/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:04:22 by notraore          #+#    #+#             */
/*   Updated: 2017/09/11 10:04:22 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		forward_vector(t_all *all)
{
	if (all->map[(int)(all->p->posx + all->p->dirx * all->p->movespeed)]
	[(int)(all->p->posy)] == 0)
		all->p->posx += all->p->dirx * all->p->movespeed;
	if (all->map[(int)(all->p->posx)][(int)(all->p->posy + all->p->diry
	* all->p->movespeed)] == 0)
		all->p->posy += all->p->diry * all->p->movespeed;
}

void		back_vector(t_all *all)
{
	if (all->map[(int)(all->p->posx + all->p->dirx * all->p->movespeed)]
	[(int)(all->p->posy)] == 0)
		all->p->posx -= all->p->dirx * all->p->movespeed;
	if (all->map[(int)(all->p->posx)][(int)(all->p->posy + all->p->diry
	* all->p->movespeed)] == 0)
		all->p->posy -= all->p->diry * all->p->movespeed;
}

void		rot_right(t_all *all)
{
	all->p->oldx = all->p->dirx;
	all->p->dirx = all->p->dirx * cos(-all->p->rotspeed) -
	all->p->diry * sin(-all->p->rotspeed);
	all->p->diry = all->p->oldx * sin(-all->p->rotspeed) +
	all->p->diry * cos(-all->p->rotspeed);
	all->p->oldx = all->p->planex;
	all->p->planex = all->p->planex * cos(-all->p->rotspeed) -
	all->p->planey * sin(-all->p->rotspeed);
	all->p->planey = all->p->oldx * sin(-all->p->rotspeed) +
	all->p->planey * cos(-all->p->rotspeed);
}

void		rot_left(t_all *all)
{
	all->p->oldx = all->p->dirx;
	all->p->dirx = all->p->dirx * cos(all->p->rotspeed) -
	all->p->diry * sin(all->p->rotspeed);
	all->p->diry = all->p->oldx * sin(all->p->rotspeed) +
	all->p->diry * cos(all->p->rotspeed);
	all->p->oldx = all->p->planex;
	all->p->planex = all->p->planex * cos(all->p->rotspeed) -
	all->p->planey * sin(all->p->rotspeed);
	all->p->planey = all->p->oldx * sin(all->p->rotspeed) +
	all->p->planey * cos(all->p->rotspeed);
}

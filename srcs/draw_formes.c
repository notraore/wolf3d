/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_formes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:27:49 by notraore          #+#    #+#             */
/*   Updated: 2017/09/12 14:09:21 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		circle_init(t_all *all, int radius)
{
	all->cirx = radius - 1;
	all->ciry = 0;
	all->cirdx = 1;
	all->cirdy = 1;
	all->cirerr = all->cirdx - (radius << 1);
}

void		draw_circle(int x0, int y0, int radius, t_all *all)
{
	circle_init(all, radius);
	while (all->cirx >= all->ciry)
	{
		all->e->img_datas[(x0 + all->cirx) + (y0 + all->ciry) * W] = all->clr;
		all->e->img_datas[(x0 + all->ciry) + (y0 + all->cirx) * W] = all->clr;
		all->e->img_datas[(x0 - all->ciry) + (y0 + all->cirx) * W] = all->clr;
		all->e->img_datas[(x0 - all->cirx) + (y0 + all->ciry) * W] = all->clr;
		all->e->img_datas[(x0 - all->cirx) + (y0 - all->ciry) * W] = all->clr;
		all->e->img_datas[(x0 - all->ciry) + (y0 - all->cirx) * W] = all->clr;
		all->e->img_datas[(x0 + all->ciry) + (y0 - all->cirx) * W] = all->clr;
		all->e->img_datas[(x0 + all->cirx) + (y0 - all->ciry) * W] = all->clr;
		if (all->cirerr <= 0)
		{
			all->ciry += 1;
			all->cirerr += all->cirdy;
			all->cirdy += 2;
		}
		if (all->cirerr > 0)
		{
			all->cirx -= 1;
			all->cirdx += 2;
			all->cirerr += (-radius << 1) + all->cirdx;
		}
	}
}

void		line_init(t_all *all)
{
	all->dx = labs(all->x1 - all->x0);
	all->sx = all->x0 < all->x1 ? 1 : -1;
	all->dy = labs(all->y1 - all->y0);
	all->sy = all->y0 < all->y1 ? 1 : -1;
	all->err = (all->dx > all->dy ? all->dx : -all->dy) / 2;
}

void		ft_bresenham(t_all *all)
{
	line_init(all);
	while (1)
	{
		all->e->img_datas[all->x0 + all->y0 * W] = YELLOW;
		if (all->x0 == all->x1 && all->y0 == all->y1)
			break ;
		all->e2 = all->err;
		if (all->e2 > -all->dx)
		{
			all->err -= all->dy;
			all->x0 += all->sx;
		}
		if (all->e2 < all->dy)
		{
			all->err += all->dx;
			all->y0 += all->sy;
		}
	}
}

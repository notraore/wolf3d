/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:27:49 by notraore          #+#    #+#             */
/*   Updated: 2017/09/12 14:09:21 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	draw_circle(int x0, int y0, int radius, t_all *all)
{
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while (x >= y)
	{
		all->e->img_datas[(x0 + x) + (y0 + y) * W] = all->clr;
		all->e->img_datas[(x0 + y) + (y0 + x) * W] = all->clr;
		all->e->img_datas[(x0 - y) + (y0 + x) * W] = all->clr;
		all->e->img_datas[(x0 - x) + (y0 + y) * W] = all->clr;
		all->e->img_datas[(x0 - x) + (y0 - y) * W] = all->clr;
		all->e->img_datas[(x0 - y) + (y0 - x) * W] = all->clr;
		all->e->img_datas[(x0 + y) + (y0 - x) * W] = all->clr;
		all->e->img_datas[(x0 + x) + (y0 - y) * W] = all->clr;
		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}
		if (err > 0)
		{
			x--;
			dx += 2;
			err += (-radius << 1) + dx;
		}
	}
}

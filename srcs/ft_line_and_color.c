/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_and_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:04:40 by notraore          #+#    #+#             */
/*   Updated: 2017/09/11 10:04:42 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int			get_color(t_all *all)
{
	if (all->m->side)
	{
		if ((all->m->stepx == -1 && all->m->stepy == -1) ||
			(all->m->stepx == 1 && all->m->stepy == -1))
			return (FBLUE);
		if ((all->m->stepx == -1 && all->m->stepy == 1) ||
			(all->m->stepx == 1 && all->m->stepy == 1))
			return (BLUE);
	}
	if ((all->m->stepx == -1 && all->m->stepy == -1) ||
		(all->m->stepx == -1 && all->m->stepy == 1))
		return (BLUE / 2);
	else
		return (FBLUE / 2);
	return (0);
}

void		ft_map_reticule_hud(t_all *all)
{
		all->clr = RED;
		draw_circle(W / 2, H / 2, 5, all);
		all->clr = WHITE;
		draw_circle(W -150, 600, 100, all);
}

void		ft_line(t_all *all, int x, int start, int end)
{
	int i;

	i = start - 1;
	if ((start >= 0 && start <= W) && (end >= 0 && end <= H))
	{
		while (++i < end)
			all->e->img_datas[x + i * W] = get_color(all);
		i = end - 1;
		while (++i < H)
			all->e->img_datas[x + i * W] = FGREY;
		ft_map_reticule_hud(all);
	}
}

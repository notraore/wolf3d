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
	if (all->m->side == 1)
	{
		if ((all->m->stepx == -1 && all->m->stepy == -1) ||
			(all->m->stepx == 1 && all->m->stepy == -1))
			return (FBLUE / 0.95 / (all->m->deltadistx + all->m->deltadisty) * 0.85);
		if ((all->m->stepx == -1 && all->m->stepy == 1) ||
			(all->m->stepx == 1 && all->m->stepy == 1))
			return (ORG / 0.95 / (all->m->deltadistx + all->m->deltadisty) * 0.85);
	}
	if ((all->m->stepx == -1 && all->m->stepy == -1) ||
		(all->m->stepx == -1 && all->m->stepy == 1))
		return (FBLUE * 0.95 / (all->m->deltadistx + all->m->deltadisty) * 0.85);
	else
		return (FBLUE / 0.95 / (all->m->deltadistx + all->m->deltadisty) * 0.85);
	return (0);
}

int			get_color_2(t_all *all)
{
	if (all->m->side == 1)
	{
		if ((all->m->stepx == -1 && all->m->stepy == -1) ||
			(all->m->stepx == 1 && all->m->stepy == -1))
			return (RED);
		if ((all->m->stepx == -1 && all->m->stepy == 1) ||
			(all->m->stepx == 1 && all->m->stepy == 1))
			return (ORG);
	}
	if ((all->m->stepx == -1 && all->m->stepy == -1) ||
		(all->m->stepx == -1 && all->m->stepy == 1))
		return (BLUE / 2);
	else
		return (FBLUE);
	return (0);
}

/*
**return (BLUE / 0.95 / (all->m->deltadistx + all->m->deltadistx) * 0.85);
*/

void		ft_line(t_all *all, int x, int start, int end)
{
	int i;

	i = start - 1;
	if ((start >= 0 && start <= W) && (end >= 0 && end <= H))
	{
		while (++i < end)
		{
			if (all->compet == 1)
				all->e->img_datas[x + i * W] = get_color(all);
			else if (all->compet == 0)
				all->e->img_datas[x + i * W] = get_color_2(all);
		}
		i = end - 1;
		while (++i < H)
			all->e->img_datas[x + i * W] = FGREY;
	}
}

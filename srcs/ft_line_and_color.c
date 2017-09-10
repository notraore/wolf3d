#include "../wolf3d.h"

int			get_color(t_all *all)
{
	if (all->m->side)
	{
		if ((all->m->stepX == -1 && all->m->stepY == -1) ||
			(all->m->stepX == 1 && all->m->stepY == -1))
			return (RED / 2);
		if ((all->m->stepX == -1 && all->m->stepY == 1) ||
			(all->m->stepX == 1 && all->m->stepY == 1))
			return (RED);
	}
	if ((all->m->stepX == -1 && all->m->stepY == -1) ||
		(all->m->stepX == -1 && all->m->stepY == 1))
		return (RED / 3);
	return (0);
}

void		ft_line(t_all *all, int x, int start, int end)
{
	int i;

	i = - 1;
	while (++i < start)
		all->e->img_datas[x + i * WIN_WIDTH] = WHITE;
	i--;
	if ((start >= 0 && start <= WIN_WIDTH) && (end >= 0 && end <= WIN_HEIGHT))
		while (++i < end)
			all->e->img_datas[x + i * WIN_WIDTH] = get_color(all);
		i--;
		while (++i < WIN_HEIGHT)
			all->e->img_datas[x + i * WIN_WIDTH] = BLUE;
}

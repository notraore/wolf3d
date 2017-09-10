#include "../wolf3d.h"

void		step_side_nbr(t_all *all)
{
	if (all->p->rayDirX < 0)
	{
		all->m->stepX = -1;
		all->m->sideDistX = (all->p->rayPosX - all->m->mapX)
		* all->m->deltaDistX;
	}
	else
	{
		all->m->stepX = 1;
		all->m->sideDistX = (all->m->mapX + 1.0 - all->p->rayPosX)
		* all->m->deltaDistX;
	}
	if (all->p->rayDirY < 0)
	{
		all->m->stepY = -1;
		all->m->sideDistY = (all->p->rayPosY - all->m->mapY)
		* all->m->deltaDistY;
	}
	else
	{
		all->m->stepY = 1;
		all->m->sideDistY = (all->m->mapY + 1.0 - all->p->rayPosY)
		* all->m->deltaDistY;
	}
}

void		ray_lenght(t_all *all)
{
	while (all->m->hit == 0)
	{
		if (all->m->sideDistX < all->m->sideDistY)
		{
			all->m->sideDistX += all->m->deltaDistX;
			all->m->mapX += all->m->stepX;
			all->m->side = 0;
		}
		else
		{
			all->m->sideDistY += all->m->deltaDistY;
			all->m->mapY += all->m->stepY;
			all->m->side = 1;
		}
		if (worldMap[all->m->mapX][all->m->mapY] > 0)
			all->m->hit = 1;
	}
	if (all->m->side == 0)
		all->m->perpWallDist = (all->m->mapX - all->p->rayPosX +
		(1 - all->m->stepX) / 2) / all->p->rayDirX;
	else
		all->m->perpWallDist = (all->m->mapY - all->p->rayPosY +
		(1 - all->m->stepY) / 2) / all->p->rayDirY;
}

void		ray_draw(t_all *all, int x)
{
	int lineHeight;
	int drawStart;
	int drawEnd;

	lineHeight = (int)(WIN_HEIGHT / all->m->perpWallDist);
	drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawEnd >= WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
	ft_line(all, x, drawStart, drawEnd);
}

void		raycast(t_all *all)
{
	int x;

	x = -1;
	all->p->rayPosX = all->p->posX; 
	all->p->rayPosY = all->p->posY;
	while (++x < WIN_WIDTH)
	{
		all_init(all, x);
		step_side_nbr(all);
		ray_lenght(all);
		ray_draw(all, x);
	}
}

int		ft_loop(t_all *all)
{
	all->p->last_frame = clock();
	if (all->p->next_frame > all->p->last_frame)
		return (0);
	all->p->next_frame = all->p->last_frame + (CLOCKS_PER_SEC / 100);
	raycast(all);
	mlx_put_image_to_window(all->e->mlx, all->e->win, all->e->img, 0, 0);
	return (0);
}

#include "../wolf3d.h"

void		all_init(t_all *all, int x)
{
	all->m->mapX = (int)all->p->rayPosX;
	all->m->mapY = (int)all->p->rayPosY;
	all->p->camX = 2 * x / (double)WIN_WIDTH - 1;
	all->p->rayDirX = all->p->dirX + all->p->planeX * all->p->camX;
	all->p->rayDirY = all->p->dirY + all->p->planeY * all->p->camX;
	all->m->deltaDistX = sqrt(1 + (all->p->rayDirY * all->p->rayDirY)
	/ (all->p->rayDirX * all->p->rayDirX));
	all->m->deltaDistY = sqrt(1 + (all->p->rayDirX * all->p->rayDirX)
	/ (all->p->rayDirY * all->p->rayDirY));
	all->m->hit = 0;
	all->m->side = -1;
	all->m->perpWallDist = -1;
}

void	init_player(t_all *all)
{
	all->p->posX = 12;
	all->p->posY = 5;
	all->p->dirX = -1;
	all->p->dirY = 0;
	all->p->planeX = 0;
	all->p->planeY = 0.66;
	all->p->last_frame = clock();
	all->p->next_frame = 0;
	all->p->moveSpeed = 0.10;
	all->p->rotSpeed = 0.10;
}
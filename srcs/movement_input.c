#include "../wolf3d.h"

void		forward_vector(t_all *all)
{
	if (worldMap[(int)(all->p->posX + all->p->dirX * all->p->moveSpeed)]
	[(int)(all->p->posY)] == 0)
		all->p->posX += all->p->dirX * all->p->moveSpeed;
	if (worldMap[(int)(all->p->posX)][(int)(all->p->posY + all->p->dirY
	* all->p->moveSpeed)] == 0)
		all->p->posY += all->p->dirY * all->p->moveSpeed;
}
void		back_vector(t_all *all)
{
	if (worldMap[(int)(all->p->posX + all->p->dirX * all->p->moveSpeed)]
	[(int)(all->p->posY)] == 0)
		all->p->posX -= all->p->dirX * all->p->moveSpeed;
	if (worldMap[(int)(all->p->posX)][(int)(all->p->posY + all->p->dirY
	* all->p->moveSpeed)] == 0)
		all->p->posY -= all->p->dirY * all->p->moveSpeed;
}

void		rot_right(t_all *all)
{
	all->p->oldX = all->p->dirX;
	all->p->dirX = all->p->dirX * cos(-all->p->rotSpeed) -
	all->p->dirY * sin(-all->p->rotSpeed);
	all->p->dirY = all->p->oldX * sin(-all->p->rotSpeed) +
	all->p->dirY * cos(-all->p->rotSpeed);
	all->p->oldX = all->p->planeX;
	all->p->planeX = all->p->planeX * cos(-all->p->rotSpeed) -
	all->p->planeY * sin(-all->p->rotSpeed);
	all->p->planeY = all->p->oldX * sin(-all->p->rotSpeed) +
	all->p->planeY * cos(-all->p->rotSpeed);
}

void		rot_left(t_all *all)
{
	all->p->oldX = all->p->dirX;
	all->p->dirX = all->p->dirX * cos(all->p->rotSpeed) -
	all->p->dirY * sin(all->p->rotSpeed);
	all->p->dirY = all->p->oldX * sin(all->p->rotSpeed) +
	all->p->dirY * cos(all->p->rotSpeed);
	all->p->oldX = all->p->planeX;
	all->p->planeX = all->p->planeX * cos(all->p->rotSpeed) -
	all->p->planeY * sin(all->p->rotSpeed);
	all->p->planeY = all->p->oldX * sin(all->p->rotSpeed) +
	all->p->planeY * cos(all->p->rotSpeed);
}

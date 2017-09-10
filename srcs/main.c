/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:18:52 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/09 21:54:28 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int worldMap[24][24]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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

int			ft_hooks(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 13)
	{
		if (worldMap[(int)(all->p->posX + all->p->dirX * all->p->moveSpeed)]
			[(int)(all->p->posY)] == 0)
			all->p->posX += all->p->dirX * all->p->moveSpeed;
		if (worldMap[(int)(all->p->posX)][(int)(all->p->posY + all->p->dirY
		* all->p->moveSpeed)] == 0)
			all->p->posY += all->p->dirY * all->p->moveSpeed;
	}
	if (keycode == 1)
	{
		if (worldMap[(int)(all->p->posX - all->p->dirX * all->p->moveSpeed)]
		[(int)(all->p->posY)] == 0)
			all->p->posX -= all->p->dirX * all->p->moveSpeed;
		if (worldMap[(int)(all->p->posX)][(int)(all->p->posY - all->p->dirY *
		all->p->moveSpeed)] == 0)
			all->p->posY -= all->p->dirY * all->p->moveSpeed;
	}
	if (keycode == 2)
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
	if (keycode == 0)
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
	printf("kyc = %d\n", keycode);
	return (0);
}

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

void		step_side_nbr(t_all *all)
{
	if (all->p->rayDirX < 0)
	{
		all->m->stepX = -1;
		all->m->sideDistX = (all->p->rayPosX - all->m->mapX) * all->m->deltaDistX;
	}
	else
	{
		all->m->stepX = 1;
		all->m->sideDistX = (all->m->mapX + 1.0 - all->p->rayPosX) * all->m->deltaDistX;
	}
	if (all->p->rayDirY < 0)
	{
		all->m->stepY = -1;
		all->m->sideDistY = (all->p->rayPosY - all->m->mapY) * all->m->deltaDistY;
	}
	else
	{
		all->m->stepY = 1;
		all->m->sideDistY = (all->m->mapY + 1.0 - all->p->rayPosY) * all->m->deltaDistY;
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

int		main(void)
{
	t_ply	player;
	t_env	env;
	t_map	map;
	t_all	all;

	all.p = &player;
	init_player(&all);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
	env.img_datas = (int *)mlx_get_data_addr(env.img, &(env.bpp), &(env.sl), &(env.end));
	all.e = &env;
	all.m = &map;

	mlx_loop_hook(all.e->mlx, ft_loop, &all);
	mlx_hook(env.win, 2, (1L >> 0), ft_hooks, &all);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}

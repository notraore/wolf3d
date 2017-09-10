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
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_line(t_env *env, t_coords a, t_coords b, int clr)
{
	t_draw line;

	line.dx = abs(b.x - a.x);
	line.sx = a.x < b.x ? 1 : -1;
	line.dy = abs(b.y - a.y);
	line.sy = a.y < b.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -(line.dy)) / 2;
	while (1)
	{
		if ((a.x >= 0 && a.x <= WIN_WIDTH) && (a.y >= 0 && a.y <= WIN_HEIGHT))
			env->img_datas[a.x + a.y * WIN_WIDTH] = clr;
		if (a.x == b.x && a.y == b.y)
			break ;
		line.e2 = line.err;
		if (line.e2 > -(line.dx))
		{
			line.err -= line.dy;
			a.x += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			a.y += line.sy;
		}
	}
}

int			ft_hooks(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 13)
	{
		if (worldMap[(int)(all->p->posX + all->p->dirX * all->p->moveSpeed)][(int)(all->p->posY)] == false)
			all->p->posX += all->p->dirX * all->p->moveSpeed;
		if (worldMap[(int)(all->p->posX)][(int)(all->p->posY + all->p->dirY * all->p->moveSpeed)] == false)
			all->p->posY += all->p->dirY * all->p->moveSpeed;
	}
	if (keycode == 1)
	{
		if (worldMap[(int)(all->p->posX - all->p->dirX * all->p->moveSpeed)][(int)(all->p->posY)] == false)
			all->p->posX -= all->p->dirX * all->p->moveSpeed;
		if (worldMap[(int)(all->p->posX)][(int)(all->p->posY - all->p->dirY * all->p->moveSpeed)] == false)
			all->p->posY -= all->p->dirY * all->p->moveSpeed;
	}
	printf("hoks.x = %f\n", all->p->posX);
	printf("hoks.y = %f\n", all->p->posY);
	if (keycode == 0)
	{
		double oldDirX = all->p->dirX;
		all->p->dirX = all->p->dirX * cos(-all->p->rotSpeed) - all->p->dirY * sin(-all->p->rotSpeed);
		all->p->dirY = oldDirX * sin(-all->p->rotSpeed) + all->p->dirY * cos(-all->p->rotSpeed);
		double oldPlaneX = all->p->planeX;
		all->p->planeX = all->p->planeX * cos(-all->p->rotSpeed) - all->p->planeY * sin(-all->p->rotSpeed);
		all->p->planeY = oldPlaneX * sin(-all->p->rotSpeed) + all->p->planeY * cos(-all->p->rotSpeed);
	}
	if (keycode == 2)
	{
		double oldDirX = all->p->dirX;
		all->p->dirX = all->p->dirX * cos(all->p->rotSpeed) - all->p->dirY * sin(all->p->rotSpeed);
		all->p->dirY = oldDirX * sin(all->p->rotSpeed) + all->p->dirY * cos(all->p->rotSpeed);
		double oldPlaneX = all->p->planeX;
		all->p->planeX = all->p->planeX * cos(all->p->rotSpeed) - all->p->planeY * sin(all->p->rotSpeed);
		all->p->planeY = oldPlaneX * sin(all->p->rotSpeed) + all->p->planeY * cos(all->p->rotSpeed);
	}
	if (keycode == 49)
	{
		all->e->clr = BLUE;
		mlx_put_image_to_window(all->e->mlx, all->e->win, all->e->img, 0, 0);
	}
	printf("dir.x = %f\n", all->p->dirY);
	printf("dir.y = %f\n", all->p->dirY);
	printf("rot. = %f\n", all->p->rotSpeed);
	mlx_put_image_to_window(all->e->mlx, all->e->win, all->e->img, 0, 0);
	printf("keycode = %d\n", keycode);
	return (0);
}


int		main(void)
{
	t_ply	player;
	t_env	env;
	t_map	map;
	t_coords a;
	t_coords b;
	t_all all;

	player.moveSpeed = 5;
	player.rotSpeed = 5;
	printf("player. = %f\n", player.moveSpeed);
	printf("rot. = %f\n", player.rotSpeed);
	all.e = &env;
	all.p = &player;
	all.m = &map;
	printf("all. = %f\n", all.p->moveSpeed);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
	env.img_datas = (int *)mlx_get_data_addr(env.img, &(env.bpp), &(env.sl), &(env.end));

	player.posX = 12;
	player.posY = 22;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;
	env.clr = WHITE;
	for (int x = 0; x < WIN_WIDTH; x++)
	{
		printf("edefe\n");
		player.camX = 2 * x / (double)WIN_WIDTH - 1;
		player.rayPosX = player.posX; 
		player.rayPosY = player.posY;
		player.rayDirX = player.dirX + player.planeX * player.camX;
		player.rayDirY = player.dirY + player.planeY * player.camX;
		map.mapX = (int)player.rayPosX;
		map.mapY = (int)player.rayPosY;

		map.deltaDistX = sqrt(1 + (player.rayDirY * player.rayDirY) / (player.rayDirX * player.rayDirX));
		map.deltaDistY = sqrt(1 + (player.rayDirX * player.rayDirX) / (player.rayDirY * player.rayDirY));
		map.hit = 0;
		if (player.rayDirX < 0)
		{
			map.stepX = -1;
			map.sideDistX = (player.rayPosX - map.mapX) * map.deltaDistX;
		}
		else
		{
			map.stepX = 1;
			map.sideDistX = (map.mapX + 1.0 - player.rayPosX) * map.deltaDistX;
		}
		if (player.rayDirY < 0)
		{
			map.stepY = -1;
			map.sideDistY = (player.rayPosY - map.mapY) * map.deltaDistY;
		}
		else
		{
			map.stepY = 1;
			map.sideDistY = (map.mapY + 1.0 - player.rayPosY) * map.deltaDistY;
		}
		while (map.hit == 0)
		{
			if (map.sideDistX < map.sideDistY)
			{
				map.sideDistX += map.deltaDistX;
				map.mapX += map.stepX;
				map.side = 0;
			}
			else
			{
				map.sideDistY += map.deltaDistY;
				map.mapY += map.stepY;
				map.side = 1;
			}
			if (worldMap[map.mapX][map.mapY] > 0)
				map.hit = 1;
		}
		if (map.side == 0)
			map.perpWallDist = (map.mapX - player.rayPosX + (1 - map.stepX) / 2) / player.rayDirX;
		else
			map.perpWallDist = (map.mapY - player.rayPosY + (1 - map.stepY) / 2) / player.rayDirY;
		map.lineHeight = (int)(WIN_HEIGHT / map.perpWallDist);
		map.drawStart = -map.lineHeight / 2 + WIN_HEIGHT / 2;
		if (map.drawStart < 0)
			map.drawStart = 0;
		map.drawEnd = map.lineHeight / 2 + WIN_HEIGHT / 2;
		if (map.drawEnd >= WIN_HEIGHT)
			map.drawEnd = WIN_HEIGHT - 1;
		// if (worldMap[map.mapX][map.mapY] == 1)
			// map.clr = BLUE;
		a.x = x;
		a.y = map.drawStart;
		b.x = x;
		b.y = map.drawEnd;
		if (map.side == 1)
			ft_line(&env, a, b, all.e->clr);
		else
			ft_line(&env, a, b, all.e->clr / 2);
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_hook(env.win, 2, (1L >> 0), ft_hooks, &all);
	// mlx_hook(env.win, 6, (6L>>0), ft_mouse_hooks, env);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}

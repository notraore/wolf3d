/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:22:17 by notraore          #+#    #+#             */
/*   Updated: 2017/09/08 12:22:19 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		ft_player_init(t_ply *start)
{
	start->dir_x = 22;
	start->dir_y = 12;
	start->dir_x = -1;
	start->dir_y = 0;
	start->fov_x = 0;
	start->fov_y = 0.66;
	start->time = 0;
	start->old_time = 0;
}

void	curr_init(t_curr *curr, t_ray *ray)
{
	curr->map_x = (int)ray->pray_x;
	curr->map_y = (int)ray->pray_y;
	curr->del_distx = sqrt(1 + (ray->dray_x * ray->dray_x) / (ray->dray_x * ray->dray_x));
	curr->del_disty = sqrt(1 + (ray->dray_y * ray->dray_y) / (ray->dray_y * ray->dray_y));
	curr->hit = 0;
}

void	side_step_init(t_ray *ray, t_curr *curr)
{
	if (ray->dray_x < 0)
	{
		curr->stepx = -1;
		curr->sid_distx = (ray->pray_x - curr->map_x) * curr->del_distx;
	}
	else
	{
		curr->stepx = 1;
		curr->sid_distx = (curr->map_x + 1.0 - ray->pray_x) * curr->del_distx;
	}
	if (ray->dray_y < 0)
	{
		curr->stepy = -1;
		curr->sid_disty = (ray->pray_x - curr->map_y) * curr->del_disty;
	}
	else
	{
		curr->stepy = 1;
		curr->sid_disty = (curr->map_y + 1.0 - ray->pray_y) * curr->del_disty;
	}
}

void		wall_hit(t_curr *curr, int map[MAPW][MAPH])
{
	while (curr->hit == 0)
	{
		if (curr->sid_distx < curr->sid_disty)
		{
			curr->sid_distx += curr->del_distx;
			curr->map_x += curr->stepx;
			curr->side = 0;
		}
		else
		{
			curr->sid_disty += curr->del_disty;
			curr->map_y += curr->stepy;
			curr->side = 1;
		}
		if (map[curr->map_x][curr->map_y] > 0)
			curr->hit = 1;
	}
}

void		draw_pixel(t_draw *draw, t_mlx *ptr)
{
	int i;

	i = -1;
	while (++i < draw->draw_end)
		ptr->data[i + draw->draw_end] = ptr->color;
}
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_curr		curr;
	t_ply		ply;
	t_mlx		ptr;
	t_ray		ray;
	t_draw		draw;
	t_env		e;

	e.mlx = &ptr;
	e.curr = &curr;
	e.ray = &ray;
	e.ply = &ply;

	int i;

	int map[MAPW][MAPH]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	i = 0;
	// int j = 0;
	if (!(e.map = malloc(sizeof(int) * 24)))
		return (0);
	ft_player_init(&ply);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, W, H, "WOLF3D");
	ptr.img = mlx_new_image(ptr.mlx, W, H);
	ptr.data = (int *)mlx_get_data_addr(ptr.img,
	&ptr.bpp, &ptr.sl, &ptr.end);
	while (i < W)
	{
		ray.cam_x = 2 * i / (double)W - 1;
		ray.pray_x = ply.pos_x;
		ray.pray_y = ply.pos_y;
		ray.dray_x = ply.dir_x + ply.fov_x * ray.cam_x;
		ray.dray_y = ply.dir_y + ply.fov_y * ray.cam_x;
		i++;
		printf("here %d\n", i);
	}
	curr_init(&curr, &ray);
	side_step_init(&ray, &curr);
	wall_hit(&curr, map);
	if (curr.side == 0)
		curr.wall_dist = (curr.map_x - ray.pray_x + (1 - curr.stepx) / 2) / ray.dray_x;
	else
		curr.wall_dist = (curr.map_y - ray.pray_x + (1 - curr.stepy) / 2) / ray.dray_y;
	draw.line_height = (int)(H / curr.wall_dist);
	draw.draw_start = -draw.line_height / 2 + H / 2;
	if(draw.draw_start < 0)
		draw.draw_start = 0;
		draw.draw_end = draw.line_height / 2 + H / 2;
	if(draw.draw_end >= H)
		draw.draw_end = H - 1;
	if (map[curr.map_x][curr.map_y] == 1)
		ptr.color = RED;
	if (curr.side == 1)
		ptr.color = ptr.color / 2;
	int d = draw.draw_start;
	printf("start = %d\n", d);
	printf("end = %d\n", draw.draw_end);
	while (++d < draw.draw_end)
		ptr.data[d + draw.draw_end * W] = RED;
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_hook(ptr.win, 2, (1L << 0), &keyboard_actions, 0);
	mlx_loop(ptr.mlx);
	return (0);
}

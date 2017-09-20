/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:04:33 by notraore          #+#    #+#             */
/*   Updated: 2017/09/11 10:04:33 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int			proper_exit(t_all *all)
{
	mlx_destroy_image(all->e->mlx, all->e->img);
	ft_bzero(&all, sizeof(t_all));
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(EXIT_SUCCESS);
	return (0);
}

void		move(t_all *all)
{
	forward_vector(all);
	back_vector(all);
	rot_right(all);
	rot_left(all);
	mlx_destroy_image(all->e->mlx, all->e->img);
	all->e->img = mlx_xpm_file_to_image(all->e->mlx, "./Textures/Sky.xpm",
	&(all->e->sl), &all->e->bpp);
}

void		fire_shot(t_all *all)
{
	all->fire = 1;
	if (all->ammo > 0)
	{
		fire_reticule(all);
		all->ammo -= 1;
		if (all->compet == 1)
			all->radar += 30;
	}
	else
		system("afplay ./song/empty.mp3&");
}

int			key_press(int keycode, t_all *all)
{
	if (keycode == 49 && all->go == 2)
		fire_shot(all);
	if (keycode == 53)
		proper_exit(all);
	if ((keycode == 13 || keycode == 126) && all->go == 2)
		all->up = 1;
	if ((keycode == 1 || keycode == 125) && all->go == 2)
		all->down = 1;
	if ((keycode == 2 || keycode == 124) && all->go == 2)
		all->right = 1;
	if ((keycode == 0 || keycode == 123) && all->go == 2)
		all->left = 1;
	if (keycode == 46 && all->go == 2)
		all->hide_map = all->hide_map == 1 ? 0 : 1;
	if (keycode == 4 && all->go == 2)
		all->hide_hud = all->hide_hud == 1 ? 0 : 1;
	menu(keycode, all);
	if (all->go == 0 && all->game == 0)
		all->go = 1;
	return (0);
}

int			key_release(int keycode, t_all *all)
{
	if (keycode == 49)
		all->fire = 0;
	if (keycode == 13 || keycode == 126)
		all->up = 0;
	if (keycode == 1 || keycode == 125)
		all->down = 0;
	if (keycode == 2 || keycode == 124)
		all->right = 0;
	if (keycode == 0 || keycode == 123)
		all->left = 0;
	return (0);
}

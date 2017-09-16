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

void		proper_exit(t_all *all)
{
	mlx_destroy_image(all->e->mlx, all->e->img);
	ft_bzero(&all, sizeof(t_all));
	exit(EXIT_SUCCESS);
}

void		fire_reticule(t_all *all)
{
	all->fire = 1;
	all->reticule = 20;
	mlx_put_image_to_window(all->e->mlx, all->e->win,
	all->gun_1, W / 2, 400);
}

int			ft_hooks(int keycode, t_all *all)
{
	if (keycode == 53)
		proper_exit(all);
	if (keycode == 13 || keycode == 126)
		forward_vector(all);
	if (keycode == 1 || keycode == 125)
		back_vector(all);
	if (keycode == 2 || keycode == 124)
		rot_right(all);
	if (keycode == 0 || keycode == 123)
		rot_left(all);
	if (keycode == 49)
		fire_reticule(all);
	if (keycode == 46)
		all->hide_map = all->hide_map == 1 ? 0 : 1;
	if (keycode == 4)
		all->hide_hud = all->hide_hud == 1 ? 0 : 1;
	mlx_destroy_image(all->e->mlx, all->e->img);
	all->e->img = mlx_xpm_file_to_image(all->e->mlx, "./Textures/Sky.xpm",
	&(all->e->sl), &all->e->bpp);
	return (0);
}

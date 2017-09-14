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

int			ft_hooks(int keycode, t_all *all)
{
	if (keycode == 53)
		proper_exit(all);
	if (keycode == 13)
		forward_vector(all);
	if (keycode == 1)
		back_vector(all);
	if (keycode == 2)
		rot_right(all);
	if (keycode == 0)
		rot_left(all);
	if (keycode == 49)
		all->reticule = 20;
	mlx_destroy_image(all->e->mlx, all->e->img);
	all->e->img = mlx_xpm_file_to_image(all->e->mlx, "./Textures/Sky.xpm",
	&(all->e->sl), &all->e->bpp);
	return (0);
}

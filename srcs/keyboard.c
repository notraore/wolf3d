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

int			ft_hooks(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		mlx_destroy_image(all->e->mlx, all->e->img);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13)
		forward_vector(all);
	if (keycode == 1)
		back_vector(all);
	if (keycode == 2)
		rot_right(all);
	if (keycode == 0)
		rot_left(all);
	mlx_destroy_image(all->e->mlx, all->e->img);
	all->e->img = mlx_xpm_file_to_image(all->e->mlx, "./Textures/Sky.xpm",
	&(all->e->sl), &all->e->bpp);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:24:14 by notraore          #+#    #+#             */
/*   Updated: 2017/09/14 16:24:16 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			ft_game_over(t_all *all)
{
	system("killall afplay 2&>/dev/null >/dev/null");
	mlx_destroy_image(all->e->mlx, all->e->img);
	if (!(all->e->img = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/gameover.xpm",
	&(all->e->sl), &all->e->bpp)))
		ft_kill("texture error");
	mlx_put_image_to_window(all->e->mlx, all->e->win,
	all->e->img, 0, 0);
	all->go = 0;
	system("afplay ./song/end.mp3&");
}

void			loop_hud(t_all *all)
{
	mlx_put_image_to_window(all->e->mlx, all->e->win, all->blaz_f, W - 100, 0);
	mlx_put_image_to_window(all->e->mlx, all->e->win, all->bullet, 0, H - 100);
	mlx_string_put(all->e->mlx, all->e->win, W / 2 - 200, 30, WHITE,
	"Get to the other side of the map, youre at the bottom.");
	mlx_string_put(all->e->mlx, all->e->win, 35, H - 62, WHITE,
	ft_itoa(all->ammo));
}

void			ft_ggwp(t_all *all)
{
	system("killall afplay 2&>/dev/null >/dev/null");
	mlx_destroy_image(all->e->mlx, all->e->img);
	if (!(all->e->img = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/credit.xpm", &(all->e->sl), &all->e->bpp)))
		ft_kill("texture error");
	mlx_put_image_to_window(all->e->mlx, all->e->win,
	all->e->img, 0, 0);
	all->go = 0;
	system("afplay ./song/yay.mp3&");
}

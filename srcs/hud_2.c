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
	if (all->compet)
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

void			display_tips(t_all *all)
{
	if (all->go == 1)
	{
		if (all->tips < 1000 )
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 150, H - 30,
			RED, "Tips : Blue walls are heading north.");
		else if (all->tips < 2000)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 150, H - 30,
			RED, "Tips : Enjoy the music ? Finish the competition mode to see credit.");
		else if (all->tips < 3000)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 150, H - 30,
			RED, "Tips : In competition mode, shot a bullet add time to the timer.");
		else if (all->tips < 4000)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 150, H - 30,
			RED, "Tips : Blue walls are heading north.");
		else if (all->tips < 5000)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 150, H - 30,
			RED, "Tips : Blue walls are heading north.");
		else if (all->tips < 6000)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 150, H - 30,
			RED, "Tips : Blue walls are heading north.");
		else if (all->tips < 7000)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 150, H - 30,
			RED, "Tips : Blue walls are heading north.");
	}
	all->tips = (all->tips <= 7000) ? all->tips + 1 : 0;
	printf("%d\n", all->tips);
}

void			display_help(t_all *all)
{
	if (all->arrpos == 0 && all->go == 1)
		mlx_string_put(all->e->mlx, all->e->win, 40, 250 + all->arrpos,
		WHITE, "300 ammo - No timer - No objectif - Just enjoy");
	if (all->arrpos == 100 && all->go == 1)
	{
		mlx_string_put(all->e->mlx, all->e->win, 15, H - 410,
		WHITE, "You start at the bottom of the map, you must reach the");
		mlx_string_put(all->e->mlx, all->e->win, 15, H - 380,
		WHITE, "top before the time goes to 0. You have 3 bullets");
		mlx_string_put(all->e->mlx, all->e->win, 15, H - 350,
		WHITE, "shot one bullet with space get additional time to your timer.");
		mlx_string_put(all->e->mlx, all->e->win, 15, H - 290,
		RED, "Disturbing Wall Texture (Epilepsy warning)");
	}
	display_tips(all);
}

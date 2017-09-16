/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:23:24 by notraore          #+#    #+#             */
/*   Updated: 2017/09/14 17:23:25 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			load_texture_pack(t_all *all)
{
	if (!((all->e->img = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/Sky.xpm", &(all->e->sl), &all->e->bpp))))
		ft_kill("Texture error");
	if (!((all->gun_0 = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/uzi_walk.xpm", &(all->e->sl), &all->e->bpp))))
		ft_kill("Texture error");
	if (!((all->gun_1 = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/uzi_fire.xpm", &(all->e->sl), &all->e->bpp))))
		ft_kill("Texture error");
	if (!((all->blaz_face = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/blazkowicz.xpm", &(all->e->sl), &all->e->bpp))))
		ft_kill("Texture error");
	if (!((all->bullet = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/bullet.xpm", &(all->e->sl), &all->e->bpp))))
		ft_kill("Texture error");
	if (!((all->infini = mlx_xpm_file_to_image(all->e->mlx,
	"./Textures/infini.xpm", &(all->e->sl), &all->e->bpp))))
		ft_kill("Texture error");
}

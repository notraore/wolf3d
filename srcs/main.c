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

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_mlx		ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, W, H, "WOLF3D");
	ptr.img = mlx_new_image(ptr.mlx, W, H);
	ptr.data = (int *)mlx_get_data_addr(ptr.img,
	&ptr.bpp, &ptr.sl, &ptr.end);
	ptr.data[300 + 300 * W] = 0xFFFFFF;
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_hook(ptr.win, 2, (1L << 0), &keyboard_actions, 0);
	mlx_loop(ptr.mlx);
	return (0);
}

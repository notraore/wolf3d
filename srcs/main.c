/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:18:52 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/11 19:10:25 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int				open_close_fd(t_all *all)
{
	int i;

	i = 0;
	all->line = NULL;
	(!(all->fd = open(all->argv, O_RDONLY)) ? exit(-1) : 0);
	while ((all->value = get_next_line(all->fd, &all->line)) == 1)
	{
		if (all->line)
		{
			free(all->line);
			all->line = NULL;
		}
		i++;
	}
	if (all->line)
	{
		free(all->line);
		all->line = NULL;
	}
	close(all->fd);
	return (i);
}

void			ft_parce_file(t_all *all)
{
	all->i = open_close_fd(all);
	(!(all->fd = open(all->argv, O_RDONLY)) ? exit(-1) : 0);
	all->map = (int **)ft_memalloc(sizeof(int *) * all->i + 1);
	all->taille = (int *)ft_memalloc(sizeof(int) * all->i + 1);
	all->i = 0;
	while ((all->value = get_next_line(all->fd, &all->line)) == 1)
	{
		all->tmp = ft_strsplit(all->line, ' ');
		while (all->tmp[all->i++])
			all->i += 1;
		all->map[all->j] = ft_memalloc(sizeof(int) * all->i + 1);
		all->i = -1;
		while (all->tmp[all->i += 1])
			all->map[all->j][all->i] = ft_atoi(all->tmp[all->i]);
		all->taille[all->j] = all->i;
		free_tab(all->tmp);
		free(all->line);
		all->j += 1;
	}
	all->map[all->j] = NULL;
}

void			check_file(t_all *all)
{
	int i;
	int j;
	int last;

	i = 0;
	j = 0;
	last = all->i - 1;
	while (j < all->j)
	{
		i = 0;
		while (i < all->i)
		{
			if (j == 0 || j == all->j)
			{
				if (all->map[j][i] == 0)
					ft_kill("Map not well closed. Please check map borders.");
			}
			if (all->map[j][0] == 0 || all->map[j][last] == 0)
				ft_kill("Map not well closed. Please check map borders.");
			i++;
		}
		j++;
	}
}

int				main(int argc, char **argv)
{
	t_ply		player;
	t_env		env;
	t_map		map;
	t_all		all;

	if (argc != 2)
		ft_print_err(argc);
	all.e = &env;
	all.argv = argv[1];
	all.p = &player;
	ft_parce_file(&all);
	check_file(&all);
	init_player(&all);
	env.mlx = mlx_init();
	all.e->img = mlx_xpm_file_to_image(all.e->mlx,
	"./Textures/Munt.xpm", &(all.e->sl), &env.bpp);
	env.win = mlx_new_window(env.mlx, W, H, "test");
	env.img_datas = (int *)mlx_get_data_addr(env.img,
	&(env.bpp), &(env.sl), &(env.end));
	all.m = &map;
	mlx_loop_hook(all.e->mlx, ft_loop, &all);
	mlx_hook(env.win, 2, (1L >> 0), ft_hooks, &all);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:18:52 by notraore          #+#    #+#             */
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

void			ft_player_position(t_all *all, int x, int y)
{
	all->one_x += 1;
	all->p->posx = y;
	all->p->posy = x;
}

void			ft_parce_file(t_all *all)
{
	if (!(all->i = open_close_fd(all)))
		ft_kill("Map doesn't exist. Please, enter a valid map name.");
	(!(all->fd = open(all->argv, O_RDONLY)) ? exit(-1) : 0);
	all->map = (int **)malloc(sizeof(int *) * all->i + 1);
	all->taille = (int *)malloc(sizeof(int) * all->i + 1);
	all->i = 0;
	while ((all->value = get_next_line(all->fd, &all->line)) == 1)
	{
		all->tmp = ft_strsplit(all->line, ' ');
		while (all->tmp[all->i++])
			all->i += 1;
		all->map[all->j] = malloc(sizeof(int) * all->i + 1);
		all->i = -1;
		while (all->tmp[all->i += 1])
		{
			if (ft_strcmp(all->tmp[all->i], "x") == 0)
				ft_player_position(all, all->i, all->j);
			all->map[all->j][all->i] = ft_atoi(all->tmp[all->i]);
		}
		all->taille[all->j] = all->i;
		free(all->line);
		free_tab(all->tmp);
		all->j += 1;
	}
}

int				ft_tile_screen(t_all *all)
{
	if (all->go == 0 && all->game == 0)
	{
		mlx_put_image_to_window(all->e->mlx, all->e->win, all->tile, 0, 0);
		if (all->loop <= 40)
			mlx_string_put(all->e->mlx, all->e->win, W / 2 - 110, H - 100,
			WHITE, "PRESS ANY KEY TO START");
		all->loop = all->loop >= 80 ? 0 : all->loop + 1;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_ply		player;
	t_env		env;
	t_map		map;
	t_all		all;

	if (argc != 2)
		ft_print_err(argc);
	ft_bzero(&all, sizeof(t_all));
	all.e = &env;
	all.argv = argv[1];
	all.p = &player;
	ft_parce_file(&all);
	check_file(&all);
	ft_mlx(&all);
	init_player(&all);
	system("killall afplay 2&>/dev/null >/dev/null\n \
	afplay ./song/lac.mp3&");
	all.m = &map;
	mlx_loop_hook(all.e->mlx, ft_loop, &all);
	mlx_hook(env.win, 2, (1L << 0), key_press, &all);
	mlx_hook(env.win, 3, (1L << 1), key_release, &all);
	mlx_hook(env.win, 17, (1L << 17), proper_exit, &all);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}

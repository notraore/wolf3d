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
		{
			if (ft_strcmp(all->tmp[all->i], "x") == 0)
				ft_player_position(all, all->i, all->j);
			all->map[all->j][all->i] = ft_atoi(all->tmp[all->i]);
		}
		all->taille[all->j] = all->i;
		free_tab(all->tmp);
		free(all->line);
		all->j += 1;
	}
	all->map[all->j] = NULL;
}

void			ft_mlx(t_all *all)
{
	all->e->mlx = mlx_init();
	load_texture_pack(all);
	all->e->win = mlx_new_window(all->e->mlx, W, H, "WOLF3D");
	all->e->img_datas = (int *)mlx_get_data_addr(all->e->img,
	&(all->e->bpp), &(all->e->sl), &(all->e->end));
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
	ft_mlx(&all);
	ft_draw_minimap(&all);
	init_player(&all);
	all.m = &map;
	mlx_loop_hook(all.e->mlx, ft_loop, &all);
	mlx_hook(env.win, 2, (1L >> 0), ft_hooks, &all);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:22:42 by notraore          #+#    #+#             */
/*   Updated: 2017/09/08 12:22:43 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOOLBOX_H
# define TOOLBOX_H

# include "mlx.h"
# include "./libft/libft.h"

# define W 512
# define H 384
#define MAPW 24
#define MAPH 24
# define RED 0xFF0000

typedef struct s_mlx	t_mlx;
typedef struct s_ray	t_ray;
typedef struct s_env	t_env;
typedef struct s_curr	t_curr;
typedef struct s_draw	t_draw;
typedef struct s_ply	t_ply;

struct					s_mlx
{
	int					sl;
	int					end;
	int					bpp;
	int					**map;
	int					*data;
	int					color;
	void				*mlx;
	void				*win;
	void				*img;
};

struct					s_ply
{
	double				dir_x;
	double				dir_y;
	double				pos_x;
	double				pos_y;
	double				fov_x;
	double				fov_y;
	double				old_fovx;
	double				r_spd;
	double				m_spd;
	double				old_time;
	double				time;
};

struct					s_ray
{
	double				cam_x;
	double				pray_x;
	double				pray_y;
	double				dray_x;
	double				dray_y;
};

struct					s_curr
{
	int					map_x;
	int					map_y;
	int					hit;
	int					side;
	int					stepx;
	int					stepy;
	double				sid_distx;
	double				sid_disty;
	double				del_distx;
	double				del_disty;
	double				wall_dist;
};

struct					s_draw
{
	int					line_height;
	int					draw_start;
	int					draw_end;
};

struct					s_env
{
	t_mlx				*mlx;
	t_ply				*ply;
	t_ray				*ray;
	t_curr				*curr;
	int					**map;
};

int						keyboard_actions(int keycode);//, t_env *e);

#endif

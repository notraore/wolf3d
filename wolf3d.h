/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:15:20 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/09 21:51:29 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 720

# define K_ESC 53
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <math.h>
# include <time.h>
# include <stdbool.h>

typedef struct s_all    t_all;
typedef struct s_ply    t_ply;
typedef struct s_map    t_map;
typedef struct s_env    t_env;
typedef struct s_draw   t_draw;
typedef struct s_coords t_coords;


struct                    s_ply
{
	double  posX;
	double  posY;
	double  dirX;
	double  dirY;
	double  oldX;
	double  planeX;
	double  planeY;
	double  camX;
	double  rayPosX;
	double  rayPosY;
	double  rayDirX;
	double  rayDirY;
	double  moveSpeed;
	double  rotSpeed;
	clock_t  last_frame;
	clock_t  next_frame;



};

struct         s_map
{
	int     mapX;
	int     mapY;
	int     sideDistX;
	int     sideDistY;
	int     deltaDistX;
	int     deltaDistY;
	int     stepX;
	int     stepY;
	int     hit;
	int     side;
	double  perpWallDist;
	int     lineHeight;
	int     drawEnd;
	int     drawStart;
	int     clr;
};

struct		    s_draw
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
};

struct		    s_coords
{
	int				x;
	int				y;
};

struct       s_env
{
	void    *mlx;
	void    *win;
	void    *img;
	int     *img_datas;
	int     bpp;
	int     sl;
	int     end;
	int     clr;
};

struct          s_all
{
	t_env       *e;
	t_map       *m;
	t_draw      *d;
	t_ply       *p;
	t_coords    *cora;
	t_coords    *corb;
};

/*
**movement_input.c
*/
void        forward_vector(t_all *all);
void        back_vector(t_all *all);
void        rot_right(t_all *all);
void        rot_left(t_all *all);

/*
**raycasting.c
*/
void        step_side_nbr(t_all *all);
void        ray_lenght(t_all *all);
void        ray_draw(t_all *all, int x);
void        raycast(t_all *all);
int         ft_loop(t_all *all);

/*
**inits.c
*/
void        all_init(t_all *all, int x);
void        init_player(t_all *all);

/*
**ft_line_and_color.c
*/
void        ft_line(t_all *all, int x, int start, int end);
int         get_color(t_all *all);

int     ft_hooks(int keycode, t_all *all);
int     ft_game(t_all *all);
void    ft_line(t_all *all, int x, int start, int end);

#endif

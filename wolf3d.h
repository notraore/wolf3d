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

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800

# define K_ESC 53
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <math.h>
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
    double  planeX;
    double  planeY;
    double  camX;
    double  rayPosX;
    double  rayPosY;
    double  rayDirX;
    double  rayDirY;
    double  moveSpeed;
    double  rotSpeed;
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

struct                   s_env
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
};



int     ft_hooks(int keycode, t_all *all);

#endif

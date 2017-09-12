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

# define W 1280
# define H 720

# define K_ESC 53
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define GREY 0x745F5F
# define GAY 0xF781F3
# define MARRON 0x61380B
# define YELLOW 0xF7FE2E

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <math.h>
# include <time.h>
# include <stdbool.h>

typedef struct s_all		t_all;
typedef struct s_ply		t_ply;
typedef struct s_map		t_map;
typedef struct s_env		t_env;
typedef struct s_draw		t_draw;
typedef struct s_coords		t_coords;


struct						s_ply
{
	double					fps;
	double					camx;
	double					posx;
	double					posy;
	double					dirx;
	double					diry;
	double					oldx;
	double					planex;
	double					planey;
	double					rayposx;
	double					rayposy;
	double					raydirx;
	double					raydiry;
	double					rotspeed;
	double					movespeed;
	double					deltatime;
	clock_t					last_frame;
	clock_t					next_frame;
};

struct						s_map
{
	int						hit;
	int						clr;
	int						mapx;
	int						mapy;
	int						side;
	int						stepx;
	int						stepy;
	double					sidedistx;
	double					sidedisty;
	double					deltadistx;
	double					deltadisty;
	double					perpwalldist;
};

struct						s_draw
{
	int						dx;
	int						sx;
	int						dy;
	int						sy;
	int						e2;
	int						err;
};

struct						s_coords
{
	int						x;
	int						y;
};

struct						s_env
{
	int						sl;
	int						bpp;
	int						end;
	int						clr;
	int						*img_datas;
	void					*mlx;
	void					*win;
	void					*img;
};

struct						s_all
{
	int						i;
	int						j;
	int						h_copy;
	int						fd;
	int						**map;
	int						value;
	int						*taille;
	char					*argv;
	char					*line;
	char					**tmp;
	void					*xpm;
	t_env					*e;
	t_map					*m;
	t_draw					*d;
	t_ply					*p;
	t_coords				*cora;
	t_coords				*corb;
};

/*
**main.c
*/
int							open_close_fd(t_all *all);
void						ft_parce_file(t_all *all);
void						check_file(t_all *all);

/*
**movement_input.c
*/
void						forward_vector(t_all *all);
void						back_vector(t_all *all);
void						rot_right(t_all *all);
void						rot_left(t_all *all);

/*
**raycasting.c
*/
void						step_side_nbr(t_all *all);
void						ray_lenght(t_all *all);
void						ray_draw(t_all *all, int x);
void						raycast(t_all *all);
int							ft_loop(t_all *all);

/*
**error.c
*/
void						ft_help(void);
void						ft_print_err(int argc);


/*
**inits.c
*/
void						all_init(t_all *all, int x);
void						init_player(t_all *all);

/*
**ft_line_and_color.c
*/
void						ft_line(t_all *all, int x, int start, int end);
int							get_color(t_all *all);

/*
**keyboard.c
*/
int							ft_hooks(int keycode, t_all *all);

/*
**draw_formes
*/
void						draw_circle(int x0, int y0, int radius, t_all *all);

#endif

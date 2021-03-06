/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:15:20 by notraore          #+#    #+#             */
/*   Updated: 2017/09/09 21:51:29 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define W 1280
# define H 720

# define BLUE 0x0000FF
# define FBLUE 0x00BFFF
# define FGREY 0x424242
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define ORG 0xFFA500
# define BLACK 0x00000

# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <time.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct s_all		t_all;
typedef struct s_ply		t_ply;
typedef struct s_map		t_map;
typedef struct s_env		t_env;
typedef struct s_draw		t_draw;
typedef struct s_coords		t_coords;

struct						s_ply
{
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
};

struct						s_map
{
	int						mapx;
	int						mapy;
	double					sidedistx;
	double					sidedisty;
	double					deltadistx;
	double					deltadisty;
	double					perpwalldist;
	int						stepx;
	int						stepy;
	int						side;
	int						hit;
	int						clr;
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
	int						x;
	int						fd;
	int						clr;
	int						fps;
	int						tips;
	int						arrpos;
	int						compet;
	int						**map;
	int						value;
	int						*taille;
	double					radar;
	double					reticule;
	char					*argv;
	char					*line;
	char					**tmp;
	void					*xpm;

	int						dx;
	int						sx;
	int						dy;
	int						sy;
	int						err;
	int						e2;
	int						x0;
	int						y0;
	int						x1;
	int						y1;

	int						lineheight;
	int						drawstart;
	int						drawend;

	int						cirx;
	int						ciry;
	int						cirdx;
	int						cirdy;
	int						cirerr;

	int						hide_hud;
	int						hide_map;
	int						one_x;
	int						fire;
	double					hand_h;
	double					mima;

	void					*gun_0;
	void					*gun_1;
	void					*blaz_f;
	void					*bullet;
	void					*infini;
	void					*tile;
	void					*over;
	void					*mainmenu;
	void					*arrow;
	size_t					ammo;

	int						sl;
	int						bpp;
	int						end;
	int						*img_datas;
	clock_t					time;
	clock_t					oldtime;

	int						up;
	int						down;
	int						left;
	int						right;

	int						go;
	bool					game;
	double					loop;

	t_env					*e;
	t_map					*m;
	t_draw					*d;
	t_ply					*p;
};

/*
**main.c
*/
int							open_close_fd(t_all *all);
void						ft_player_position(t_all *all, int x, int y);
void						ft_parce_file(t_all *all);

/*
**movement_input.c
*/
void						hand_movement(t_all *all);
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
void						calc_dist(t_all *all);

/*
**error.c
*/
void						ft_help(void);
void						ft_print_err(int argc);
void						ft_print_player_pos_error(t_all *all);
void						check_file(t_all *all);

/*
**inits.c
*/
void						ft_mlx(t_all *all);
void						init_screen(t_all *all, int x);
void						init_map(t_all *all);
void						init_player(t_all *all);

/*
**ft_line_and_color.c
*/
int							get_color(t_all *all);
int							get_color_2(t_all *all);
void						ft_line(t_all *all, int x, int start, int end);

/*
**keyboard.c
*/
int							proper_exit(t_all *all);
void						move(t_all *all);
void						fire_shot(t_all *all);
int							key_press(int keycode, t_all *all);
int							key_release(int keycode, t_all *all);

/*
**draw_formes.c
*/
void						circle_init(t_all *all, int radius);
void						draw_circle(int x0, int y0, int radius, t_all *all);
void						line_init(t_all *all);
void						ft_bresenham(t_all *all);

/*
**hud.c
*/
void						ft_draw_minimap(t_all *all);
void						ft_map_reticule_hud(t_all *all);
void						hud_loop_update(t_all *all);
void						fire_reticule(t_all *all);

/*
**hud_2.c
*/
void						loop_hud(t_all *all);
void						ft_game_over(t_all *all);
void						ft_ggwp(t_all *all);
void						display_help(t_all *all);
void						display_tips(t_all *all);
/*
**load_texture.c
*/
void						load_texture_pack(t_all *all);
void						load_texture_pack_2(t_all *all);

/*
**menu.c
*/
void						menu(int keycode, t_all *all);
int							ft_tile_screen(t_all *all);

#endif

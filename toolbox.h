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

# define W 600
# define H 600

typedef struct s_mlx	t_mlx;
typedef struct s_var	t_par;
typedef struct s_cam	t_cam;
typedef struct s_map	t_map;

struct					s_mlx
{
	int					sl;
	int					end;
	int					bpp;
	int					*data;
	void				*mlx;
	void				*win;
	void				*img;
};


struct					s_par
{

};

// struct					s_cam
// {
	
// };

// struct					s_map
// {
	
// };

int		keyboard_actions(int keycode, void *param);

#endif

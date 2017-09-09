/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:17:54 by notraore          #+#    #+#             */
/*   Updated: 2017/09/08 16:17:56 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

int			keyboard_actions(int keycode)//, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	// if (keycode == 13)
	// {
	// 	if(!map[(int)(e->ply->pos_x + e->ply->dir_x * e->ply->m_spd)]
	// 	[(int)(e->ply->pos_y)])
	// 		e->ply->pos_x += e->ply->dir_x * e->ply->m_spd;
	// 	if(!map[(int)(e->ply->pos_x)]
	// 	[(int)(e->ply->pos_y + e->ply->dir_y * e->ply->m_spd)])
	// 		e->ply->pos_y += e->ply->dir_y * e->ply->m_spd;
	// }
	// //move backwards if no wall behind you
	// if (keycode == 1)
	// {
	// 	if(!map[(int)(e->ply->pos_x - e->ply->dir_x * e->ply->m_spd)]
	// 	[(int)(e->ply->pos_y)])
	// 		e->ply->pos_x -= e->ply->dir_x * e->ply->m_spd;
	// 	if(!map[(int)(e->ply->pos_x)]
	// 	[(int)(e->ply->pos_y - e->ply->dir_y * e->ply->m_spd)])
	// 		e->ply->pos_y -= e->ply->dir_y * e->ply->m_spd;
	// }
	// //rotate to the right
	// if (keycode == 2)
	// {
	// 	//both camera direction and camera plane must be rotated
	// 	double old_dirx = e->ply->dir_x;
	// 	e->ply->dir_x = e->ply->dir_x * cos(-e->ply->r_spd) - e->ply->dir_y * sin(-e->ply->r_spd);
	// 	e->ply->dir_y = old_dirx * sin(-e->ply->r_spd) + e->ply->dir_y * cos(-e->ply->r_spd);
	// 	double old_fovx = e->ply->fov_x;
	// 	e->ply->fov_x = e->ply->fov_x * cos(-e->ply->r_spd) - e->ply->fov_y * sin(-e->ply->r_spd);
	// 	e->ply->fov_y = old_fovx * sin(-e->ply->r_spd) + e->ply->fov_y * cos(-e->ply->r_spd);
	// }
	// //rotate to the left
	// if (keycode == 0)
	// {
	// 	double old_dirx = e->ply->dir_x;
	// 	e->ply->dir_x = e->ply->dir_x * cos(e->ply->r_spd) - e->ply->dir_y * sin(e->ply->r_spd);
	// 	e->ply->dir_y = old_dirx * sin(e->ply->r_spd) + e->ply->dir_y * cos(e->ply->r_spd);
	// 	double old_fovx = e->ply->fov_x;
	// 	e->ply->fov_x = e->ply->fov_x * cos(e->ply->r_spd) - e->ply->fov_y * sin(e->ply->r_spd);
	// 	e->ply->fov_y = old_fovx * sin(e->ply->r_spd) + e->ply->fov_y * cos(e->ply->r_spd);
	// }
	printf("keycode = %d\n", keycode);
	return (0);
}

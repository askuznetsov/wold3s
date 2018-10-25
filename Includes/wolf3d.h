/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:09:53 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/25 16:20:32 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

#include "libft.h"
#include <fcntl.h>
#include "/usr/local/include/mlx.h"
#include "math.h"
#include <errno.h>
#include <stdio.h>

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_inervector
{
	int		x;
	int		y;
}               t_inervector;

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int 			bts_per_pix;
	int 			szln;
	int 			weight;
	int 			s_weight;
	int 			height;
	int 			s_height;
	int				end;
	int 			move_up;
	int 			move_down;
	int 			move_right;
	int 			move_left;
	int 			**map;
	int 			ln_h;
	int 			start_dwawing;
	int 			end_drawing;
	int 			i;
	t_vector		pl_pos;
	t_vector		pl_dir;
	t_vector		pl_plane;
	t_vector		r_pos;
	t_vector		r_dir;
	t_vector		r_delta;
	t_vector		wall_side;
	t_vector		step;
	t_inervector	r_map;
	t_list			*list;
	t_list			*tmp;
	double 			pz;
	double 			rt_z;
	double 			r_cam;
	double 			r_dst;
	double			hit;
	double 			hit_side;
	double			spd_move;
	unsigned int	color_one;
	unsigned int	color_two;
	unsigned int	color_three;
	unsigned int	color_four;
	unsigned int	color_s;
	unsigned int	color_g;
	char 			**str;
	char 			*ln;
}				t_mlx;

int 	rd_file(char *argv, t_mlx *mlx);
void	err(void);
void	wrong_file(void);
void	check_map(t_list *lst, t_mlx *mlx);
void	s_position(t_mlx *mlx);
#endif

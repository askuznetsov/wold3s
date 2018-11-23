/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:09:53 by okuznets          #+#    #+#             */
/*   Updated: 2018/11/16 20:56:02 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define IF_W(x) {if (x) {wrong();}}
# define SCR_WDTH 1080
# define SCR_HGHT 720
# define T_WDTH 64
# define T_HGHT 64
# include "libft.h"
# include <fcntl.h>
# include "/usr/local/include/mlx.h"
# include "math.h"
# include <errno.h>
# include <stdio.h>
# include <pthread.h>

typedef struct		s_dir
{
	double			x;
	double			y;
}					t_dir;

typedef struct		s_revdir
{
	int				x;
	int				y;
}					t_revdir;

typedef struct		s_wolf3d
{
	int				**tex;
	void			*mlx;
	void			*win;
	void			*img;
	int				w_val;
	int				h_val;
	t_dir			step;
	int				mv_up;
	int				mv_down;
	int				mv_right;
	int				mv_left;
	double			spd_mv;
	int				start_drawing;
	int				end_drawing;
	t_dir			r_dir;
	t_dir			r_delta;
	double			r_cam;
	double			r_dst;
	t_revdir		r_map;
	t_dir			pl_pos;
	t_dir			pl_dir;
	t_dir			pl_plane;
	t_dir			wall_side;
	double			hit;
	double			hit_side;
	double			rt_z;
	int				**map;
	char			**str;
	char			*ln;
	int				ln_h;
	int				fd;
	int				i;
	int				tex_y;
	int				tex_id;
	int				tex_x;
	int				trigger;
	int				*addr;
	double			wall_x;
	int				str_flag;
}					t_wolf3d;

void				draw(t_wolf3d *wolf, int x);
void				parse_tex(t_wolf3d *wolf);
void				perr(void);
void				wrong(void);
void				check_one(char *a);
int					check_two(t_wolf3d *wolf, int z);
void				check_three(t_list *lst, t_wolf3d *wolf);
void				check_map(t_list *lst, t_wolf3d *wolf);
void				map(char *s, t_wolf3d *wolf, int i);
int					rd_file(char *argv, t_wolf3d *wolf);
void				s_position(t_wolf3d *wolf);
int					ms_hook(void);
void				spd(t_wolf3d *wolf, int tmp);
void				up(t_wolf3d *wolf);
void				down(t_wolf3d *wolf);
void				left(t_wolf3d *wolf);
void				right(t_wolf3d *wolf);
void				raycast(t_wolf3d *wolf);
void				free_lst(t_list *lst);

#endif

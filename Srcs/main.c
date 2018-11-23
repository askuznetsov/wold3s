/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:10:39 by okuznets          #+#    #+#             */
/*   Updated: 2018/11/16 20:16:28 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		k_move(int key, t_wolf3d *wolf)
{
	static int		flag = 0;

	if (key == 3)
		if ((flag = !flag))
			wolf->trigger = wolf->trigger == 0 ? 1 : 0;
	if (key == 126 || key == 13)
		wolf->mv_up = !wolf->mv_up;
	if (key == 125 || key == 1)
		wolf->mv_down = !wolf->mv_down;
	if (key == 123 || key == 0)
		wolf->mv_left = !wolf->mv_left;
	if (key == 124 || key == 2)
		wolf->mv_right = !wolf->mv_right;
	system("afplay ./Srcs/move.mp3&");
	if (key == 69 || key == 24)
		spd(wolf, 1);
	if (key == 78 || key == 27)
		spd(wolf, -1);
	if (key == 53)
	{
		system("pkill afplay");
		exit(1);
	}
	return (0);
}

int		move(t_wolf3d *wolf)
{
	if (wolf->mv_left != 0)
		left(wolf);
	if (wolf->mv_right != 0)
		right(wolf);
	if (wolf->mv_up != 0)
		up(wolf);
	if (wolf->mv_down != 0)
		down(wolf);
	raycast(wolf);
	return (0);
}

void	init_params(t_wolf3d *wolf)
{
	int x;
	int y;
	int z;

	wolf->str_flag = 0;
	wolf->pl_dir.x = -1;
	wolf->pl_dir.y = 0;
	wolf->pl_plane.x = 0;
	wolf->pl_plane.y = 1;
	wolf->rt_z = 0.04;
	wolf->spd_mv = 0.04;
	wolf->mv_up = 0;
	wolf->mv_down = 0;
	wolf->mv_left = 0;
	wolf->mv_right = 0;
	wolf->mlx = mlx_init();
	wolf->img = mlx_new_image(wolf->mlx, SCR_WDTH, SCR_HGHT);
	wolf->addr = (int *)mlx_get_data_addr(wolf->img, &x, &y, &z);
	parse_tex(wolf);
}

int		main(int argc, char **argv)
{
	t_wolf3d	wolf;
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((read(fd, NULL, 0)) == -1)
			perr();
		wolf.i = 0;
		if (rd_file(argv[1], &wolf) == -1)
			perr();
		init_params(&wolf);
		system("afplay ./Srcs/Harry.mp3&");
		wolf.win = mlx_new_window(wolf.mlx, SCR_WDTH, SCR_HGHT,
		"Harry Potter and the Chamber of Secrets");
		mlx_do_key_autorepeatoff(wolf.mlx);
		mlx_key_hook(wolf.win, k_move, &wolf);
		mlx_hook(wolf.win, 2, 1L << 0, k_move, &wolf);
		mlx_hook(wolf.win, 17, 1L << 17, ms_hook, 0);
		mlx_loop_hook(wolf.mlx, move, &wolf);
		mlx_loop(wolf.mlx);
	}
	else
		ft_putstr("Error\nUsage: ./wolf3d map/\n");
	return (0);
}

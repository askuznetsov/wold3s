/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:10:39 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/26 19:31:06 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		k_move(int key, t_mlx *mlx)
{
	static int		flag = 0;

	if (key == 12)
	{
		if ((flag = !flag))
			swap_colors(mlx);
	}
	if (key == 126 || key == 13)
		mlx->move_up = !mlx->move_up;
	if (key == 125 || key == 1)
		mlx->move_down = !mlx->move_down;
	if (key == 123 || key == 0)
		mlx->move_left = !mlx->move_left;
	if (key == 124 || key == 2)
		mlx->move_right = !mlx->move_right;
	if (key == 69 || key == 24)
		spd(mlx, 1);
	if (key == 78 || key == 27)
		spd(mlx, -1);
	if (key == 53)
	{
		system("pkill afplay");
		exit(1);
	}
	return (0);
}

int		move(t_mlx *mlx)
{
	if (mlx->move_left != 0)
		left(mlx);
	if (mlx->move_right != 0)
		right(mlx);
	if (mlx->move_up != 0)
		up(mlx);
	if (mlx->move_down != 0)
		down(mlx);
	raycast(mlx);
	return (0);
}

void	init_params(t_mlx *mlx)
{
	mlx->width = 1080;
	mlx->height = 720;
	mlx->color_one = 0x6e4003;
	mlx->color_two = 0x0c7569;
	mlx->color_three = 0x750c2a;
	mlx->color_four = 0x5d0c75;
	mlx->color_s = 0x196ad4;
	mlx->color_g = 0x11630d;
	mlx->pl_dir.x = -1;
	mlx->pl_dir.y = 0;
	mlx->pz = 0;
	mlx->pl_plane.x = 0;
	mlx->pl_plane.y = 1;
	mlx->rt_z = 0.04;
	mlx->spd_move = 0.04;
	mlx->move_up = 0;
	mlx->move_down = 0;
	mlx->move_left = 0;
	mlx->move_right = 0;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->data = (int*)mlx_get_data_addr(mlx->img,
	&mlx->bts_per_pix, &mlx->szln, &mlx->end);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((read(fd, NULL, 0)) == -1)
			err();
		mlx.i = 0;
		if (rd_file(argv[1], &mlx) == -1)
			err();
		init_params(&mlx);
		system("afplay ./Srcs/duke_music.mp3&");
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Wolf3D");
		mlx_do_key_autorepeatoff(mlx.mlx);
		mlx_key_hook(mlx.win, k_move, &mlx);
		mlx_hook(mlx.win, 2, 1L << 0, k_move, &mlx);
		mlx_hook(mlx.win, 17, 1L << 17, ms_hook, 0);
		mlx_loop_hook(mlx.mlx, move, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putstr("Error\nUsage: ./wolf3d map/\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:10:39 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/24 14:22:59 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 	mouse_hook(void)
{
	exit(1);
	return (0);
}

int 	k_move(int key, t_mlx *mlx)
{
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
		exit(1);
	return (0);
}

int 	move(t_mlx *mlx)
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
	mlx->weight = 1080;
	mlx->height = 720;
	mlx->d1 = 0x002570;
	mlx->d2 = 0x00704a;
	mlx->d3 = 0x6a6d03;
	mlx->d4 = 0x6d026b;
	mlx->d_s = 0x0090ff;
}

int		main(int argc, char **argv)
{
}

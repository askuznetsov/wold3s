/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:43:12 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/25 17:11:11 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_distation(t_mlx *mlx)
{
	if (mlx->hit_side == 0)
		mlx->r_dst = (mlx->r_map.x - mlx->pl_pos.x +
				(1 - mlx->step.x) / 2) / mlx->r_dir.x;
	else
		mlx->r_dst = (mlx->r_map.y - mlx->pl_pos.y +
				(1 - mlx->step.y) / 2) / mlx->r_dir.y;
}

void	distation(t_mlx *mlx)
{
	while (mlx->hit == 0)
	{
		if (mlx->wall_side.x < mlx->wall_side.y)
		{
			mlx->wall_side.x += mlx->r_delta.x;
			mlx->r_map.x += mlx->step.x;
			mlx->hit_side = 0;
		}
		else
		{
			mlx->wall_side.y += mlx->r_delta.y;
			mlx->r_map.y += mlx->step.y;
			mlx->hit_side = 1;
		}
		if (mlx->map[mlx->r_map.x][mlx->r_map.y] > 0)
		{
			mlx->hit = 1;
			check_distation(mlx);
		}
	}
}

void	moves(t_mlx *mlx)
{
	if (mlx->r_dir.x < 0)
	{
		mlx->step.x = -1;
		mlx->wall_side.x = (mlx->pl_pos.x -
				(int)mlx->pl_pos.x) * mlx->r_delta.x;
	}
	else
	{
		mlx->step.x = 1;
		mlx->wall_side.x = ((int)mlx->pl_pos.x + 1 -
				mlx->pl_pos.x) * mlx->r_delta.x;
	}
	if (mlx->r_dir.y < 0)
	{
		mlx->step.y = -1;
		mlx->wall_side.y = (mlx->pl_pos.y -
				(int)mlx->pl_pos.y) * mlx->r_delta.y;
	}
	else
	{
		mlx->step.y = 1;
		mlx->wall_side.y = ((int)mlx->pl_pos.y + 1 -
				mlx->pl_pos.y) * mlx->r_delta.y;
	}
}

void	raycast(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->width)
	{
		mlx->r_cam = 2 * i / (double)mlx->width - 1;
		mlx->r_dir.x = mlx->pl_dir.x + mlx->pl_plane.x * mlx->r_cam;
		mlx->r_dir.y = mlx->pl_dir.y + mlx->pl_plane.y * mlx->r_cam;
		mlx->r_map = (t_inervector){(int)mlx->pl_pos.x, (int)mlx->pl_pos.y};
		mlx->r_delta.x = sqrt(1 + pow(mlx->r_dir.y, 2) / pow(mlx->r_dir.x, 2));
		mlx->r_delta.y = sqrt(1 + pow(mlx->r_dir.x, 2) / pow(mlx->r_dir.y, 2));
		mlx->hit = 0;
		mlx->r_dst = -1;
		mlx->hit_side = -1;
		moves(mlx);
		distation(mlx);
		line_draw(mlx, i);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

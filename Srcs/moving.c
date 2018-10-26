/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:18:19 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/25 16:40:01 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	spd(t_mlx *mlx, int tmp)
{
	if (tmp == 1)
	{
		if (mlx->spd_move < 0.1)
		{
			mlx->rt_z += 0.01;
			mlx->spd_move += 0.01;
		}
	}
	else
	{
		if (mlx->spd_move > 0.01)
		{
			mlx->rt_z -= 0.01;
			mlx->spd_move -= 0.01;
		}
	}
}

void	up(t_mlx *mlx)
{
	if (mlx->map[(int)(mlx->pl_pos.x + mlx->pl_dir.x * mlx->spd_move)]
	[(int)mlx->pl_pos.y] == 0)
		mlx->pl_pos.x += mlx->pl_dir.x * mlx->spd_move;
	if (mlx->map[(int)mlx->pl_pos.x]
	[(int)(mlx->pl_pos.y + mlx->pl_dir.y * mlx->spd_move)] == 0)
		mlx->pl_pos.y += mlx->pl_dir.y * mlx->spd_move;
}

void	down(t_mlx *mlx)
{
	if (mlx->map[(int)(mlx->pl_pos.x - mlx->pl_dir.x * mlx->spd_move)]
	[(int)mlx->pl_pos.y] == 0)
		mlx->pl_pos.x -= mlx->pl_dir.x * mlx->spd_move;
	if (mlx->map[(int)mlx->pl_pos.x]
	[(int)(mlx->pl_pos.y - mlx->pl_dir.y * mlx->spd_move)] == 0)
		mlx->pl_pos.y -= mlx->pl_dir.y * mlx->spd_move;
}

void	right(t_mlx *mlx)
{
	t_vector old_direction;

	old_direction.x = mlx->pl_dir.x;
	mlx->pl_dir.x = mlx->pl_dir.x * cos(-mlx->rt_z) -
					mlx->pl_dir.y * sin(-mlx->rt_z);
	mlx->pl_dir.y = old_direction.x * sin(-mlx->rt_z) +
					mlx->pl_dir.y * cos(-mlx->rt_z);
	old_direction.x = mlx->pl_plane.x;
	mlx->pl_plane.x = mlx->pl_plane.x * cos(-mlx->rt_z) -
					mlx->pl_plane.y * sin(-mlx->rt_z);
	mlx->pl_plane.y = old_direction.x * sin(-mlx->rt_z) +
					mlx->pl_plane.y * cos(-mlx->rt_z);
}

void	left(t_mlx *mlx)
{
	t_vector old_direction;

	old_direction.x = mlx->pl_dir.x;
	mlx->pl_dir.x = mlx->pl_dir.x * cos(mlx->rt_z) -
					mlx->pl_dir.y * sin(mlx->rt_z);
	mlx->pl_dir.y = old_direction.x * sin(mlx->rt_z) +
					mlx->pl_dir.y * cos(mlx->rt_z);
	old_direction.x = mlx->pl_plane.x;
	mlx->pl_plane.x = mlx->pl_plane.x * cos(mlx->rt_z) -
					mlx->pl_plane.y * sin(mlx->rt_z);
	mlx->pl_plane.y = old_direction.x * sin(mlx->rt_z) +
					mlx->pl_plane.y * cos(mlx->rt_z);
}

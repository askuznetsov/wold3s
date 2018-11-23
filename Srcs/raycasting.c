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

void	check_distation(t_wolf3d *wolf)
{
	if (wolf->hit_side == 0)
		wolf->r_dst = (wolf->r_map.x - wolf->pl_pos.x +
				(1 - wolf->step.x) / 2) / wolf->r_dir.x;
	else
		wolf->r_dst = (wolf->r_map.y - wolf->pl_pos.y +
				(1 - wolf->step.y) / 2) / wolf->r_dir.y;
}

void	distation(t_wolf3d *wolf)
{
	while (wolf->hit == 0)
	{
		if (wolf->wall_side.x < wolf->wall_side.y)
		{
			wolf->wall_side.x += wolf->r_delta.x;
			wolf->r_map.x += wolf->step.x;
			wolf->hit_side = 0;
		}
		else
		{
			wolf->wall_side.y += wolf->r_delta.y;
			wolf->r_map.y += wolf->step.y;
			wolf->hit_side = 1;
		}
		if (wolf->map[wolf->r_map.x][wolf->r_map.y] > 0)
		{
			wolf->hit = 1;
			check_distation(wolf);
		}
	}
}

void	moves(t_wolf3d *wolf)
{
	if (wolf->r_dir.x < 0)
	{
		wolf->step.x = -1;
		wolf->wall_side.x = (wolf->pl_pos.x -
				(int)wolf->pl_pos.x) * wolf->r_delta.x;
	}
	else
	{
		wolf->step.x = 1;
		wolf->wall_side.x = ((int)wolf->pl_pos.x + 1 -
				wolf->pl_pos.x) * wolf->r_delta.x;
	}
	if (wolf->r_dir.y < 0)
	{
		wolf->step.y = -1;
		wolf->wall_side.y = (wolf->pl_pos.y -
				(int)wolf->pl_pos.y) * wolf->r_delta.y;
	}
	else
	{
		wolf->step.y = 1;
		wolf->wall_side.y = ((int)wolf->pl_pos.y + 1 -
				wolf->pl_pos.y) * wolf->r_delta.y;
	}
}

void	raycast(t_wolf3d *wolf)
{
	int i;

	i = 0;
	ft_bzero(wolf->addr, SCR_WDTH * SCR_HGHT * sizeof(int));
	while (i < SCR_WDTH)
	{
		wolf->r_cam = 2 * i / (double)SCR_WDTH - 1;
		wolf->r_dir.x = wolf->pl_dir.x + wolf->pl_plane.x * wolf->r_cam;
		wolf->r_dir.y = wolf->pl_dir.y + wolf->pl_plane.y * wolf->r_cam;
		wolf->r_map = (t_revdir){(int)wolf->pl_pos.x, (int)wolf->pl_pos.y};
		wolf->r_delta.x = sqrt(1 + pow(wolf->r_dir.y, 2) /
		pow(wolf->r_dir.x, 2));
		wolf->r_delta.y = sqrt(1 + pow(wolf->r_dir.x, 2) /
		pow(wolf->r_dir.y, 2));
		wolf->hit = 0;
		wolf->r_dst = -1;
		wolf->hit_side = -1;
		moves(wolf);
		distation(wolf);
		draw(wolf, i);
		i++;
	}
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
}

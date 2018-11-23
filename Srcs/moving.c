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

void	spd(t_wolf3d *wolf, int tmp)
{
	if (tmp == 1)
	{
		if (wolf->spd_mv < 0.1)
		{
			wolf->rt_z += 0.01;
			wolf->spd_mv += 0.01;
		}
	}
	else
	{
		if (wolf->spd_mv > 0.01)
		{
			wolf->rt_z -= 0.01;
			wolf->spd_mv -= 0.01;
		}
	}
}

void	up(t_wolf3d *wolf)
{
	if (wolf->map[(int)(wolf->pl_pos.x + wolf->pl_dir.x * wolf->spd_mv * 2.5)]
	[(int)wolf->pl_pos.y] == 0)
		wolf->pl_pos.x += wolf->pl_dir.x * wolf->spd_mv;
	if (wolf->map[(int)wolf->pl_pos.x]
	[(int)(wolf->pl_pos.y + wolf->pl_dir.y * wolf->spd_mv * 2.5)] == 0)
		wolf->pl_pos.y += wolf->pl_dir.y * wolf->spd_mv;
}

void	down(t_wolf3d *wolf)
{
	if (wolf->map[(int)(wolf->pl_pos.x - wolf->pl_dir.x * wolf->spd_mv * 2.5)]
	[(int)wolf->pl_pos.y] == 0)
		wolf->pl_pos.x -= wolf->pl_dir.x * wolf->spd_mv;
	if (wolf->map[(int)wolf->pl_pos.x]
	[(int)(wolf->pl_pos.y - wolf->pl_dir.y * wolf->spd_mv * 2.5)] == 0)
		wolf->pl_pos.y -= wolf->pl_dir.y * wolf->spd_mv;
}

void	right(t_wolf3d *wolf)
{
	t_dir old_direction;

	old_direction.x = wolf->pl_dir.x;
	wolf->pl_dir.x = wolf->pl_dir.x * cos(-wolf->rt_z) -
					wolf->pl_dir.y * sin(-wolf->rt_z);
	wolf->pl_dir.y = old_direction.x * sin(-wolf->rt_z) +
					wolf->pl_dir.y * cos(-wolf->rt_z);
	old_direction.x = wolf->pl_plane.x;
	wolf->pl_plane.x = wolf->pl_plane.x * cos(-wolf->rt_z) -
					wolf->pl_plane.y * sin(-wolf->rt_z);
	wolf->pl_plane.y = old_direction.x * sin(-wolf->rt_z) +
					wolf->pl_plane.y * cos(-wolf->rt_z);
}

void	left(t_wolf3d *wolf)
{
	t_dir old_direction;

	old_direction.x = wolf->pl_dir.x;
	wolf->pl_dir.x = wolf->pl_dir.x * cos(wolf->rt_z) -
					wolf->pl_dir.y * sin(wolf->rt_z);
	wolf->pl_dir.y = old_direction.x * sin(wolf->rt_z) +
					wolf->pl_dir.y * cos(wolf->rt_z);
	old_direction.x = wolf->pl_plane.x;
	wolf->pl_plane.x = wolf->pl_plane.x * cos(wolf->rt_z) -
					wolf->pl_plane.y * sin(wolf->rt_z);
	wolf->pl_plane.y = old_direction.x * sin(wolf->rt_z) +
					wolf->pl_plane.y * cos(wolf->rt_z);
}

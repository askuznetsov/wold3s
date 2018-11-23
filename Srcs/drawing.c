/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:01:36 by okuznets          #+#    #+#             */
/*   Updated: 2018/11/16 21:04:58 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		change_view(int color, t_wolf3d *wolf)
{
	if (wolf->hit_side == 0 && wolf->r_dir.x > 0)
		color = 0xff0000;
	else if (wolf->hit_side == 0 && wolf->r_dir.x < 0)
		color = 0x00ff00;
	else if (wolf->hit_side == 1 && wolf->r_dir.y > 0)
		color = 0x0000ff;
	else if (wolf->hit_side == 1 && wolf->r_dir.y < 0)
		color = 0xffff00;
	return (color);
}

void	vert_line(t_wolf3d *wolf, int x, int color)
{
	int y;
	int d;

	y = wolf->start_drawing;
	while (y < wolf->end_drawing)
	{
		d = y * 256 - SCR_HGHT * 128 + wolf->ln_h * 128;
		wolf->tex_y = ((d * T_HGHT) / wolf->ln_h) / 256;
		wolf->tex_id = wolf->tex_id > 9 ? 9 : wolf->tex_id;
		wolf->tex_id = wolf->tex_id < 0 ? 0 : wolf->tex_id;
		if (wolf->tex_id == 8 && wolf->r_dst < 0.2)
			wolf->map[wolf->r_map.x][wolf->r_map.y] = 0;
		color = wolf->tex[wolf->tex_id][T_HGHT * wolf->tex_y + wolf->tex_x];
		if (wolf->trigger == 1)
			color = change_view(color, wolf);
		wolf->addr[SCR_WDTH * y + x] = color;
		++y;
	}
}

void	draw(t_wolf3d *wolf, int x)
{
	int color;

	color = 0;
	wolf->ln_h = (int)((double)(SCR_HGHT) / wolf->r_dst);
	wolf->start_drawing = (int)(-wolf->ln_h / 2.0 + (double)(SCR_HGHT) / 2.0);
	wolf->start_drawing = wolf->start_drawing < 0 ? 0 : wolf->start_drawing;
	wolf->end_drawing = (int)(wolf->ln_h / 2.0 + (double)(SCR_HGHT) / 2.0);
	wolf->end_drawing = wolf->end_drawing >= (double)(SCR_HGHT) ?
						SCR_HGHT - 1 : wolf->end_drawing;
	wolf->tex_id = wolf->map[wolf->r_map.x][wolf->r_map.y];
	if (wolf->hit_side == 0)
		wolf->wall_x = wolf->pl_pos.y + wolf->r_dst * wolf->r_dir.y;
	else
		wolf->wall_x = wolf->pl_pos.x + wolf->r_dst * wolf->r_dir.x;
	wolf->wall_x -= floor(wolf->wall_x);
	wolf->tex_x = (int)(wolf->wall_x * (double)(T_WDTH));
	if (wolf->hit_side == 0 && wolf->r_dir.x > 0)
		wolf->tex_x = T_WDTH - wolf->tex_x - 1;
	if (wolf->hit_side == 1 && wolf->r_dir.y < 0)
		wolf->tex_x = T_WDTH - wolf->tex_x - 1;
	vert_line(wolf, x, color);
}

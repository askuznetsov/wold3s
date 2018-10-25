/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:01:36 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/25 15:12:47 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	side(t_mlx *mlx)
{
	if ((mlx->step.x == -1 && mlx->step.y == -1) ||
	(mlx->step.x == 1 && mlx->step.y == -1))
		return (mlx->color_one);
	if ((mlx->step.x == -1 && mlx->step.y == 1) ||
	(mlx->step.x == 1 && mlx->step.y == 1))
		return (mlx->color_two);
	return (0);
}

void			put_pixel(t_mlx *mlx, int x, int y, unsigned int tmp)
{
	int count;

	if (tmp != mlx->color_s && tmp != mlx->color_g)
	{
		if (mlx->hit_side == 1)
			tmp = side(mlx);
		else if ((mlx->step.x == -1 && mlx->step.y == -1) ||
		(mlx->step.x == -1 && mlx->step.y == 1))
			tmp = mlx->color_three;
		else
			tmp = mlx->color_four;
	}
	count = (y * mlx->weight + x);
	if (count <= mlx->weight * mlx->height)
		mlx->data[count] = tmp;
}

void			line_draw(t_mlx *mlx, int x)
{
	int 			y;
	unsigned int	tmp;

	mlx->ln_h = (int)(mlx->height / mlx->r_dst);
	mlx->start_dwawing = -mlx->ln_h / 2 + mlx->height / 2;
	if (mlx->start_dwawing < 0)
		mlx->start_dwawing = 0;
	mlx->end_drawing = mlx->ln_h / 2 + mlx->height / 2;
	if (mlx->end_drawing >= mlx->height)
		mlx->end_drawing = mlx->height - 1;
	tmp = 0x111111;
	y = 0;
	while (y++ < mlx->start_dwawing + mlx->pz)
		put_pixel(mlx, x, y, mlx->color_s);
	y -= 1;
	while (y++ <= mlx->end_drawing + mlx->pz && y < mlx->height)
		put_pixel(mlx, x, y, tmp);
	y -= 1;
	while (y++ <= mlx->height)
		put_pixel(mlx, x, y, mlx->color_g);
}

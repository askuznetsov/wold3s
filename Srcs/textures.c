/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:15:23 by okuznets          #+#    #+#             */
/*   Updated: 2018/11/16 20:24:49 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	get_addr(t_wolf3d *wolf, int num, void *txtr)
{
	int x;
	int y;
	int z;

	if (txtr == NULL)
	{
		ft_putstr("Texture number is missing\n");
		exit(-1);
	}
	wolf->tex[num] = (int *)mlx_get_data_addr(txtr, &x, &y, &z);
}

void	parse_tex(t_wolf3d *wolf)
{
	int		x;
	int		y;
	int		num;
	void	*txtr;

	num = 1;
	wolf->tex = (int **)malloc(sizeof(int *) * 10);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/mossy.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/redbrick.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/colorstn.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/wood.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/bluestone.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/greystone.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/bricksx64.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/slyth.xpm", &x, &y);
	get_addr(wolf, num++, txtr);
	txtr = mlx_xpm_file_to_image(wolf->mlx, "./textures/bricks.xpm", &x, &y);
	get_addr(wolf, num, txtr);
}

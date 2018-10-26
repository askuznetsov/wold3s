/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hook&swap_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:28:28 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/26 19:29:30 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ms_hook(void)
{
	system("pkill afplay");
	exit(1);
	return (0);
}

void	swap_colors(t_mlx *mlx)
{
	unsigned int tmp;

	tmp = mlx->color_one;
	mlx->color_one = mlx->color_two;
	mlx->color_two = mlx->color_three;
	mlx->color_three = mlx->color_four;
	mlx->color_four = tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:05:56 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/24 13:32:41 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wrong_file(void)
{
	printf("Wrong file\n");
	exit(1);
}

void	check_map(t_list *lst, t_mlx *mlx)
{
	int height;
	int weight;

	weight = 0;
	while (lst)
	{
		height = ft_strlen(lst->content);
		lst = lst->next;
		weight++;
	}
	if ((height != (mlx->s_weight * 2) - 1) || (weight != mlx->s_height))
		wrong_file();
}

int 	getting_number(char *s)
{
	int	tmp;

	if (*s == '-')
		return (-getting_number(s + 1));
	if (*s == '+')
		return (getting_number(s + 1));
	tmp = 0;
	while (*s && *s >= '0' && *s <= '9')
	{
		tmp *= 10;
		tmp = tmp + *s - '0';
		s++;
	}
	return (tmp);
}

void	position(char **s, t_mlx *mlx)
{
	int i;

	if (s[0] != NULL && s[1] != NULL)
	{
		mlx->s_weight = getting_number(s[0]);
		mlx->s_height = getting_number(s[1]);
		if ((mlx->s_weight != mlx->s_height) || mlx->s_weight < 4)
			wrong_file();
	}
	if (s[2] != NULL && s[3] != NULL)
	{
		mlx->pl_pos = (t_vector){getting_number(s[2]) + 0.5, getting_number(s[3]) + 0.5};
		if (mlx->pl_pos.x < 1.5 || mlx->pl_pos.x > mlx->s_weight)
			mlx->pl_pos.x = 1.5;
		if (mlx->pl_pos.y < 1.5 || mlx->pl_pos.y >= mlx->s_height)
			mlx->pl_pos.y = 1.5;
	}
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	s_position(t_mlx *mlx)
{
	mlx->str = ft_strsplit(mlx->ln, ' ');
	free(mlx->ln);
	position(mlx->str, mlx);
}

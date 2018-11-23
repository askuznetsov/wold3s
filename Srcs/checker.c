/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:05:56 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/25 17:41:48 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wrong(void)
{
	ft_putstr("Wrong file!");
	exit(1);
}

void	check_map(t_list *lst, t_wolf3d *wolf)
{
	int width;

	width = 0;
	while (lst)
	{
		lst = lst->next;
		width++;
	}
	if (width != wolf->h_val)
		wrong();
}

int		getting_number(char *s)
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

void	position(char **s, t_wolf3d *wolf)
{
	int i;

	if (s[0] != NULL && s[1] != NULL)
	{
		wolf->w_val = getting_number(s[0]);
		wolf->h_val = getting_number(s[1]);
		if ((wolf->w_val != wolf->h_val) || wolf->w_val < 5)
			wrong();
	}
	if (s[2] != NULL && s[3] != NULL)
	{
		wolf->pl_pos = (t_dir){getting_number(s[2]) +
		0.5, getting_number(s[3]) + 0.5};
		if (wolf->pl_pos.x < 1.5 || wolf->pl_pos.x > wolf->w_val)
			wolf->pl_pos.x = 1.5;
		if (wolf->pl_pos.y < 1.5 || wolf->pl_pos.y >= wolf->h_val)
			wolf->pl_pos.y = 1.5;
	}
	else
		wrong();
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	s_position(t_wolf3d *wolf)
{
	wolf->str = ft_strsplit(wolf->ln, ' ');
	free(wolf->ln);
	position(wolf->str, wolf);
}

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

void	check_one(char *a)
{
	int i;

	i = 0;
	while (a[i] != '\0')
	{
		if ((a[i] >= '0' && a[i] <= '9') || a[i] == ' ' || a[i] == '\n')
		{
			i++;
			continue;
		}
		else
			wrong();
	}
}

int		check_two(t_wolf3d *wolf, int z)
{
	char	*a;
	int		i;

	i = 0;
	a = wolf->ln;
	while (a[i] != '\0')
	{
		if ((z == wolf->h_val || z == 1) &&
			(a[i] == '1' || a[i] == ' ' || a[i] == '\n'))
		{
			i++;
			continue;
		}
		if (z > 1 && ((a[i] >= '0' && a[i] <= '9') ||
						a[i] == ' ' || a[i] == '\n'))
		{
			IF_W(i == 0 && a[i] != '1');
			IF_W(i == (wolf->w_val * 2 - 2) && a[i] != '1');
			i++;
			continue;
		}
		else
			wrong();
	}
	return (i);
}

void	check_three(t_list *lst, t_wolf3d *wolf)
{
	t_list *tmp;

	close(wolf->fd);
	check_map(lst, wolf);
	wolf->map = (int**)malloc(sizeof(int*) * wolf->w_val);
	tmp = lst;
	while (lst && wolf->i < wolf->w_val)
	{
		map(lst->content, wolf, wolf->i);
		lst = lst->next;
		wolf->i++;
	}
	free_lst(tmp);
}

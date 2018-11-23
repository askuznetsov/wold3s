/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:15:43 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/25 16:42:45 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	perr(void)
{
	perror("\033[31mFile opening error");
	exit(1);
}

void	map(char *s, t_wolf3d *wolf, int i)
{
	char	**split;
	int		count;

	count = 0;
	wolf->map[i] = (int*)malloc(sizeof(int) * wolf->h_val);
	split = ft_strsplit(s, ' ');
	while (split[count] && count <= wolf->h_val)
	{
		wolf->map[i][count] = ft_atoi(split[count]);
		if ((i == 0 || i == wolf->h_val - 1) && wolf->map[i][count] != 1)
			wrong();
		if (count == 0 && wolf->map[i][count] != 1)
			wrong();
		if (wolf->map[i][count] < 0)
			wolf->map[i][count] = 0;
		count++;
	}
	count = -1;
	while (split[++count])
		free(split[count]);
	free(split);
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		free(lst->content);
		lst = lst->next;
		free(tmp);
	}
}

int		rd_file(char *argv, t_wolf3d *wolf)
{
	t_list	*lst;
	char	*a;
	int		i;
	int		z;

	z = 1;
	wolf->fd = open(argv, O_RDONLY);
	if (wolf->fd < 0 || (get_next_line(wolf->fd, &wolf->ln) < 1))
		return (-1);
	a = wolf->ln;
	check_one(a);
	s_position(wolf);
	while (get_next_line(wolf->fd, &wolf->ln) == 1)
	{
		i = check_two(wolf, z);
		if (i != wolf->w_val * 2 - 1)
			wrong();
		ft_lst_push_back(&lst, wolf->ln, ft_strlen(wolf->ln));
		free(wolf->ln);
		z++;
	}
	check_three(lst, wolf);
	return (0);
}

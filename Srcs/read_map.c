/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:37:36 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/22 15:56:31 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 	check_arr(char **arr)
{
	size_t	i;
	size_t	j;
	int 	*tmp;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (ft_isdigit(arr[i][j]) == 0)
				return (-1);
			j++;
		}
		tmp = (int*)malloc(sizeof(*tmp));
		*tmp = ft_atoi(arr[i]);
		free(arr[i]);
		arr[i] = (char*)tmp;
		i++;
	}
	if (i == 0)
		return (-1);
	return ((int)i);
}

void	ft_del_lst(void *ptr, size_t size)
{
	size = 0;
	free(ptr);
}

char 	***read_map(int fd)
{
	t_list	*list;
	char	*line;
	char 	**arr;
	int 	check;
	char 	***res;

	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		arr = ft_strsplit(line, ' ');
		check = check_arr(arr);
		if (check < 0)
			return (NULL);
		else
		{
			ft_lst_push_back(&list, ft_lstnew(arr, (check + 1) * sizeof(*arr)));
			free(arr);
		}
	}
	res = (char ***)(ft_lst_expand(list));
	ft_lstdel(&list, &ft_del_lst);
	return (res);
}
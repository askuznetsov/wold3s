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

void	err(void)
{
	perror("\033[31mFile opening error");
	exit(1);
}

void	map(char *s, t_mlx *mlx, int i)
{
	char	**split;
	int		count;

	count = 0;
	mlx->map[i] = (int*)malloc(sizeof(int) * mlx->s_height);
	split = ft_strsplit(s, ' ');
	while (split[count] && count <= mlx->s_height)
	{
		mlx->map[i][count] = ft_atoi(split[count]);
		if ((i == 0 || i == mlx->s_height - 1) && mlx->map[i][count] != 1)
			wrong_file();
		if (count == 0 && mlx->map[i][count] != 1)
			wrong_file();
		if (mlx->map[i][count] < 0 || mlx->map[i][count] > 1)
			mlx->map[i][count] = 0;
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

int		rd_file(char *argv, t_mlx *mlx)
{
	int		fd;
	t_list	*lst;
	t_list	*tmp;
	
	char *a;
	int i = 0;
	int z = 1;

	fd = open(argv, O_RDONLY);
	if (fd < 0 || (get_next_line(fd, &mlx->ln) < 1))
		return (-1);
	a = mlx->ln;
	while (a[i] != '\0')
	{
        if ((a[i] >= '0' && a[i] <= '9') || a[i] == ' ' || a[i] == '\n')
        {
            i++;
            continue;
        }
        else
            wrong_file();
    }
	s_position(mlx);
	while (get_next_line(fd, &mlx->ln) == 1)
    {
	    i = 0;
	    a = mlx->ln;
	    while (a[i] != '\0')
        {
            if (z == 1 && (a[i] == '1' || a[i] == ' ' || a[i] == '\n'))
            {
                i++;
                continue;
            }
            if (z > 1 && ((a[i] >= '0' && a[i] <= '9') || a[i] == ' ' || a[i] == '\n'))
            {
                if (i == 0 && a[i] != '1')
                    wrong_file();
                if (i == (mlx->s_width * 2 - 2) && a[i] != '1')
                    wrong_file();
                i++;
                continue;
            }
            if (z == mlx->s_height && (a[i] == '1' || a[i] == ' ' || a[i] == '\n'))
            {
                i++;
                continue;
            }
            else
                wrong_file();
        }
        if (i != mlx->s_width * 2 - 1)
            wrong_file();
        printf("%d\n", i);
		ft_lst_push_back(&lst, mlx->ln, ft_strlen(mlx->ln));
		free(mlx->ln);
		z++;
	}
	close(fd);
	check_map(lst, mlx);
	mlx->map = (int**)malloc(sizeof(int*) * mlx->s_width);
	tmp = lst;
	while (lst && mlx->i < mlx->s_width)
	{
		map(lst->content, mlx, mlx->i);
		lst = lst->next;
		mlx->i++;
	}
	free_lst(tmp);
	return (0);
}

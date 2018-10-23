/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:09:53 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/22 15:54:48 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

#define MAPWIDTH 24
#define MAPHEIGHT 24
#define WDTH 800
#define HGHT 600

#include "libft.h"
#include <fcntl.h>
#include "/usr/local/include/mlx.h"
#include "math.h"

typedef struct s_struct
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double time;
    double oldTime;
}               t_struct;
char 	***read_map(int fd);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:34:43 by rzarquon          #+#    #+#             */
/*   Updated: 2022/02/27 18:21:59 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	open_exit(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->mapdata[++y])
	{
		x = -1;
		while (map->mapdata[y][++x])
		{
			if (map->mapdata[y][x] == 'E')
				render3(x * SCALE, y * SCALE, EXIT2, map);
		}
	}
	map->collects = -1;
}

int	animation(t_map *map)
{
	if (map->collects == 0)
		open_exit(map);
	return (0);
}

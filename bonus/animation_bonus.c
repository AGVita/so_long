/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:34:43 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/04 17:06:33 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

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

static void	coll_animation(t_map *map)
{
	static int	i;
	int			x;
	int			y;

	y = -1;
	while (map->mapdata[++y])
	{
		x = -1;
		while (map->mapdata[y][++x])
		{
			if (i == 3000 && map->mapdata[y][x] == 'C')
				render3(x * SCALE, y * SCALE, COLL2, map);
			else if (i == 6000 && map->mapdata[y][x] == 'C')
				render3(x * SCALE, y * SCALE, COLL3, map);
			else if (i == 9000 && map->mapdata[y][x] == 'C')
				render3(x * SCALE, y * SCALE, COLL4, map);
			else if (i == 12000 && map->mapdata[y][x] == 'C')
				render3(x * SCALE, y * SCALE, COLL1, map);
		}
	}
	i++;
	if (i > 15000)
		i = 0;
}

static void	player_animation(t_map *map)
{
	static int	i;

	if (i == 1500)
		render3(map->px * SCALE, map->py * SCALE, PLAYER2, map);
	else if (i == 3000)
		render3(map->px * SCALE, map->py * SCALE, PLAYER3, map);
	else if (i == 4500)
		render3(map->px * SCALE, map->py * SCALE, PLAYER4, map);
	else if (i == 6000)
		render3(map->px * SCALE, map->py * SCALE, PLAYER5, map);
	else if (i == 7500)
	{
		render3(map->px * SCALE, map->py * SCALE, PLAYER1, map);
		i = 0;
	}
	i++;
}

int	animation(t_map *map)
{
	if (map->collects == 0)
		open_exit(map);
	coll_animation(map);
	player_animation(map);
	return (0);
}

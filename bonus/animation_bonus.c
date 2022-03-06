/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:34:43 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/06 19:52:18 by rzarquon         ###   ########.fr       */
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

static void	enemy_animation(t_map *map)
{
	static int	a;
	t_list		*list;
	t_enemy		*enemy;

	list = map->enems;
	if (a == 3000 || a == 6000 || a == 9000 || a == 12000 || a == 15000)
	{
		while (list)
		{
			enemy = list->data;
			if (a == 3000)
				render3(enemy->x * SCALE, enemy->y * SCALE, ENEMY2, map);
			else if (a == 6000)
				render3(enemy->x * SCALE, enemy->y * SCALE, ENEMY3, map);
			else if (a == 9000)
				render3(enemy->x * SCALE, enemy->y * SCALE, ENEMY4, map);
			else if (a == 12000)
				render3(enemy->x * SCALE, enemy->y * SCALE, ENEMY5, map);
			else if (a == 15000)
				render3(enemy->x * SCALE, enemy->y * SCALE, ENEMY6, map);
			list = list->next;
		}
	}
	if (a++ == 18000)
		a = 0;
}

int	animation(t_map *map)
{
	if (map->collects == 0)
		open_exit(map);
	coll_animation(map);
	player_animation(map);
	enemy_animation(map);
	check_position(map);
	move_enemies(map);
	return (0);
}

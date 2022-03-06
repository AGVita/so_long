/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:27:03 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/06 21:05:15 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

void	check_position(t_map *map)
{
	t_list	*list;
	t_enemy	*enemy;

	list = map->enems;
	while (list)
	{	
		enemy = list->data;
		if (enemy->x == map->px && enemy->y == map->py)
			// game_over(map);
			ft_printf("BEBEBE");
		list = list->next;
	}
}

static void	move_horizontal_enemy(t_map *map, t_enemy *enemy)
{
	if (enemy->flag == 1 && map->mapdata[enemy->y][enemy->x + 1] == '0')
	{
		render3(enemy->x * SCALE, enemy->y * SCALE, GROUND, map);
		render3((enemy->x + 1) * SCALE, enemy->y * SCALE, ENEMY1, map);
		map->mapdata[enemy->y][enemy->x] = '0';
		map->mapdata[enemy->y][enemy->x + 1] = 'H';
		enemy->x += 1;
	}
	else if (enemy->flag)
		enemy->flag = 0;
	else if (enemy->flag == 0 && map->mapdata[enemy->y][enemy->x - 1] == '0')
	{
		render3(enemy->x * SCALE, enemy->y * SCALE, GROUND, map);
		render3((enemy->x - 1) * SCALE, enemy->y * SCALE, ENEMY1, map);
		map->mapdata[enemy->y][enemy->x] = '0';
		map->mapdata[enemy->y][enemy->x - 1] = 'H';
		enemy->x -= 1;
	}
	else
		enemy->flag = 1;
}

static void	move_vertical_enemy(t_map *map, t_enemy *enemy)
{
	if (enemy->flag == 1 && map->mapdata[enemy->y + 1][enemy->x] == '0')
	{
		ft_printf("AAA");
		render3(enemy->x * SCALE, enemy->y * SCALE, GROUND, map);
		render3(enemy->x * SCALE, (enemy->y + 1) * SCALE, ENEMY1, map);
		map->mapdata[enemy->y][enemy->x] = '0';
		map->mapdata[enemy->y + 1][enemy->x] = 'V';
		enemy->y++;
	}
	else if (enemy->flag)
		enemy->flag = 0;
	else if (enemy->flag == 0 && map->mapdata[enemy->y - 1][enemy->x] == '0')
	{
		render3(enemy->x * SCALE, enemy->y * SCALE, GROUND, map);
		render3(enemy->x * SCALE, (enemy->y - 1) * SCALE, ENEMY1, map);
		map->mapdata[enemy->y][enemy->x] = '0';
		map->mapdata[enemy->y - 1][enemy->x] = 'V';
		enemy->y--;
	}
	else
		enemy->flag = 1;
}

void	move_enemies(t_map *map)
{
	static int	time;
	t_list		*list;
	t_enemy		*enemy;

	if (time++ != 5000)
		return ;
	list = map->enems;
	while (list)
	{
		enemy = list->data;
		if (enemy->type == HORIZONTAL)
			move_horizontal_enemy(map, enemy);
		else
			move_vertical_enemy(map, enemy);
		list = list->next;
	}
	time = 0;
}

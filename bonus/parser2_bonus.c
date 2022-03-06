/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:44:27 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/06 17:33:14 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

void	check_chars(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->mapdata[++i])
	{
		j = -1;
		while (map->mapdata[i][++j])
		{
			if (map->mapdata[i][j] == 'P')
				map->player++;
			else if (map->mapdata[i][j] == 'E')
				map->exit++;
			else if (map->mapdata[i][j] == 'C')
				map->collects++;
		}
	}
}

static void	check_wallp2(char *string, t_map *map)
{
	int	i;

	i = 0;
	while (string[i] != '\n')
	{
		if (string[i] != '1')
			puterror("you have problemms with walls\n", map);
		i++;
	}
}

void	check_wallp1(t_map *map)
{
	int	i;

	i = -1;
	while (map->mapdata[++i])
	{	
		if (i == 0 || i == map->height - 1)
			check_wallp2(map->mapdata[i], map);
		else if (map->mapdata[i][0] != '1' || \
				map->mapdata[i][map->length - 2] != '1')
			puterror("you have problemms with walls\n", map);
	}
}

static	void	add_enemy(t_map *map, int y, int x)
{
	t_list	*list;
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (map->mapdata[y][x] == 'V')
		enemy->type = HORIZONTAL;
	else
		enemy->type = VERTICAL;
	enemy->x = x;
	enemy->y = y;
	enemy->flag = 1;
	list = ft_lstnew(enemy);
	if (!list)
		puterror("memory allocation failed\n", map);
	ft_lstadd_back(&map->enems, list);
}

void	check_enemies(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			if (map->mapdata[y][x] == 'V' || map->mapdata[y][x] == 'H')
				add_enemy(map, y, x);
			x++;
		}
		y++;
	}
}

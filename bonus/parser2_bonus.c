/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:44:27 by rzarquon          #+#    #+#             */
/*   Updated: 2022/02/27 20:50:18 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

static void	check_chars(t_map *map)
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

static void	check_wallp1(t_map *map)
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

void	check_was(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->mapdata[++i])
	{
		j = 0;
		while (map->mapdata[i][j] != '\n')
			if (!ft_strchr("1EP0C", map->mapdata[i][j++]))
				puterror("forbidden symbol on the map\n", map);
	}
	check_wallp1(map);
	check_chars(map);
	if (map->collects == 0)
		puterror("you have no collectibles on the map\n", map);
	if (map->player != 1)
		puterror("invalid number of players\n", map);
	if (map->exit == 0)
		puterror ("you have no way out\n", map);
}

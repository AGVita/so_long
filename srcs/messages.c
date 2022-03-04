/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:44:15 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/04 19:20:22 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	puterror(char	*type_of_error, t_map *map)
{
	int	i;

	i = -1;
	printf("Map is not valid because: %s", type_of_error);
	if (map->mapdata != NULL)
	{
		while (map->mapdata[++i])
			free(map->mapdata[i]);
	}
	free(map->mapdata);
	exit(1);
}

int	exit_game(t_map *map)
{
	int	i;

	i = 0;
	while (map->mapdata[i])
	{
		free(map->mapdata[i]);
		i++;
	}
	free(map->mapdata);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
}

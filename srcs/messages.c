/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:44:15 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/05 16:44:56 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	puterror(char	*type_of_error, t_map *map)
{
	int	i;

	i = -1;
	ft_printf("Map is not valid because: %s", type_of_error);
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
	ft_printf("Game closed\n");
	free(map->mapdata);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
}

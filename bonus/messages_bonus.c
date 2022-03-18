/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:44:15 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/07 15:08:37 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

void	del_data(void *data)
{
	t_enemy	*enemy;

	enemy = data;
	free (enemy);
}

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
	exit (1);
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
	ft_lstclear(&map->enems, del_data);
	ft_printf("Game closed\n");
	free(map->mapdata);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
}

void	print_info_about_moves(t_map *map)
{
	char	*moves;

	moves = ft_itoa(map->steps++);
	render3(0, 0, WALL2, map);
	mlx_string_put(map->mlx, map->mlx_win, 20, 40, 0x000000, moves);
	free(moves);
}

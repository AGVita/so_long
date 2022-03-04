/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:36:53 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/04 20:17:24 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	exit_door(t_map *map)
{
	printf("Congratulations, you won the game for the %d steps\n", map->steps);
	exit_game(map);
	exit (0);
}

static void	movement_realization(int x, int y, t_map *map)
{
	if (map->collects == -1 && map->mapdata[y][x] == 'E')
		exit_door(map);
	else if (map->mapdata[y][x] == '1' || map->mapdata[y][x] == 'E')
		return ;
	else if (map->mapdata[y][x] == '0')
	{
		render3(map->px * SCALE, map->py * SCALE, GROUND, map);
		render3(x * SCALE, y * SCALE, PLAYER, map);
	}
	else if (map->mapdata[y][x] == 'C')
	{
		render3(map->px * SCALE, map->py * SCALE, GROUND, map);
		render3(x * SCALE, y * SCALE, PLAYER, map);
		map->mapdata[y][x] = '0';
		map->collects--;
	}
	map->px = x;
	map->py = y;
	printf ("Moves: %d \r", map->steps++);
}

static int	key_hook(int keycode, t_map *map)
{
	if (keycode == KEYW || keycode == KEYW2)
		movement_realization(map->px, map->py - 1, map);
	else if (keycode == KEYA || keycode == KEYA2)
		movement_realization(map->px - 1, map->py, map);
	else if (keycode == KEYS || keycode == KEYS2)
		movement_realization(map->px, map->py + 1, map);
	else if (keycode == KEYD || keycode == KEYD2)
		movement_realization(map->px + 1, map->py, map);
	else if (keycode == 53)
		exit_game(map);
	return (0);
}

static void	init_map(t_map *map)
{
	map->mlx = mlx_init();
	map->collects = 0;
	map->exit = 0;
	map->player = 0;
	map->steps = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		puterror("wrong number of arguments\n", &map);
	init_map(&map);
	parser(argv[1], &map);
	map.mlx_win = mlx_new_window(map.mlx, (map.length - 1) * SCALE, \
								map.height * SCALE, "SO_LONG");
	render(&map);
	mlx_key_hook(map.mlx_win, key_hook, &map);
	mlx_loop_hook(map.mlx, animation, &map);
	mlx_hook(map.mlx_win, 17, 0, exit_game, &map);
	mlx_loop(map.mlx);
	return (0);
}

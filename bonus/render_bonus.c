/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:28 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/06 20:49:54 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

void	render3(int x, int y, char *image, t_map *map)
{
	int		w;
	int		h;

	map->image = mlx_xpm_file_to_image(map->mlx, image, &w, &h);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->image, x, y);
}

static void	render2(int x, int y, char c, t_map *map)
{
	if (c == '1' && x - y == 0)
		render3(x, y, WALL2, map);
	else if (c == '1')
		render3(x, y, WALL, map);
	else if (c == '0')
		render3(x, y, GROUND, map);
	else if (c == 'C')
		render3(x, y, COLL1, map);
	else if (c == 'P')
	{
		map->px = x / SCALE;
		map->py = y / SCALE;
		render3(x, y, GROUND, map);
		render3(x, y, PLAYER3, map);
		map->mapdata[map->py][map->px] = '0';
	}
	else if (c == 'E')
		render3(x, y, EXIT, map);
	else if (c == 'H' || c == 'V')
		render3(x, y, ENEMY2, map);
}

void	render(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			render2(x * SCALE, y * SCALE, map->mapdata[y][x], map);
			x++;
		}
		y++;
	}
}

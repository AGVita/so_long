/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:40:42 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/06 18:27:31 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

static void	check_rectangle(t_map *map)
{
	int	i;

	map->length = ft_strlen(map->mapdata[0]);
	i = 0;
	while (i < map->height)
	{
		if (map->length != (int)ft_strlen(map->mapdata[i++]))
			puterror("the map is not rectangular\n", map);
		i++;
	}
}

static int	get_height(char *filename, t_map *map)
{
	char	*s;
	int		fd;
	int		height;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		puterror("problems with fd\n", map);
	s = get_next_line(fd);
	while (s)
	{
		height++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	read_file(char	*filename, t_map *map)
{
	int	i;
	int	fd;

	map->height = get_height(filename, map);
	if (map->height == 0)
		puterror("Map is empty\n", map);
	map->mapdata = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (map->mapdata == NULL)
		puterror("memory allocation failed\n", map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		puterror("problems with fd\n", map);
	i = 0;
	while (i < map->height)
	{
		map->mapdata[i] = get_next_line(fd);
		i++;
	}
	map->mapdata[i] = 0;
	close(fd);
}

static void	check_was(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->mapdata[++i])
	{
		j = 0;
		while (map->mapdata[i][j] != '\n')
			if (!ft_strchr("1EP0CVH", map->mapdata[i][j++]))
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

void	parser(char	*filename, t_map *map)
{
	int	len;

	len = ft_strlen(filename);
	if (!(ft_strnstr(filename + (len - 4), ".ber", 4)))
		puterror("extension is not .ber\n", map);
	read_file(filename, map);
	check_rectangle(map);
	check_was(map);
	check_enemies(map);
}

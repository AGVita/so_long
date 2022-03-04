/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:36:55 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/04 19:20:43 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define SCALE 60
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define KEYW 13
# define KEYA 0
# define KEYS 1
# define KEYD 2
# define KEYW2 126
# define KEYA2 123
# define KEYS2 125
# define KEYD2 124

# define PLAYER "images/p1.xpm"
# define COLL "images/c1.xpm"
# define WALL "images/w1.xpm"
# define WALL2 "images/w2.xpm"
# define GROUND "images/grass.xpm"
# define EXIT "images/ex1.xpm"
# define EXIT2 "images/ex2.xpm"

typedef struct s_map{
	int		exit;
	int		player;
	int		collects;
	int		height;
	int		length;
	int		px;
	int		py;
	char	**mapdata;
	int		steps;
	void	*mlx;
	void	*mlx_win;
	void	*image;
}t_map;

int		exit_game(t_map *map);
char	*ft_strjoin(char	*s1, char	*s2);
size_t	ft_strlen(char	*s);
char	*ft_strchr(char	*s, int c);
char	*get_next_line(int fd);
void	puterror(char	*type_of_error, t_map *map);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
void	parser(char	*filename, t_map *map);
void	check_was(t_map *map);
void	render(t_map *map);
void	render3(int x, int y, char *image, t_map *map);
int		animation(t_map *map);

#endif
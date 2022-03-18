/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:36:55 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/18 14:47:35 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# define HEX "0123456789abcdef"
# define HEXU "0123456789ABCDEF"
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

# define PLAYER1 "images/p1.xpm"
# define PLAYER2 "images/p2.xpm"
# define PLAYER3 "images/p3.xpm"
# define PLAYER4 "images/p4.xpm"
# define PLAYER5 "images/p5.xpm"
# define WALL "images/w1.xpm"
# define WALL2 "images/w2.xpm"
# define GROUND "images/grass.xpm"
# define EXIT "images/ex1.xpm"
# define EXIT2 "images/ex2.xpm"
# define COLL1 "images/c1.xpm"
# define COLL2 "images/c2.xpm"
# define COLL3 "images/c3.xpm"
# define COLL4 "images/c4.xpm"
# define ENEMY1 "images/e1.xpm"
# define ENEMY2 "images/e2.xpm"
# define ENEMY3 "images/e3.xpm"
# define ENEMY4 "images/e4.xpm"
# define ENEMY5 "images/e5.xpm"
# define ENEMY6 "images/e6.xpm"

typedef enum e_enemy_type
{
	VERTICAL,
	HORIZONTAL
}	t_enemy_type;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;

}	t_list;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				flag;
	t_enemy_type	type;
}	t_enemy;

typedef struct s_map
{
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
	t_list	*enems;

}	t_map;

int		exit_game(t_map *map);
char	*ft_strjoin(char	*s1, char	*s2);
size_t	ft_strlen(char	*s);
char	*ft_strchr(char	*s, int c);
char	*get_next_line(int fd);
void	puterror(char	*type_of_error, t_map *map);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
void	parser(char	*filename, t_map *map);
void	render(t_map *map);
void	render3(int x, int y, char *image, t_map *map);
int		animation(t_map *map);
int		ft_printf(const char *s, ...);
int		print_char(int i);
int		print_string(char *s);
int		print_integer(long n, int count);
int		print_xx(unsigned long n, int count);
int		print_xu(unsigned int n, int count);
void	print_info_about_moves(t_map *map);
char	*ft_itoa(int n);
void	check_wallp1(t_map *map);
void	check_chars(t_map *map);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	check_enemies(t_map *map);
void	move_enemies(t_map *map);
void	check_position(t_map *map);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 18:41:06 by rzarquon          #+#    #+#              #
#    Updated: 2022/03/18 14:48:12 by rzarquon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	so_long

SRCS	=	srcs/main.c srcs/get_next_line.c srcs/messages.c \
			srcs/parser.c srcs/get_next_line_utils.c \
			srcs/parser2.c srcs/render.c srcs/animation.c \
			srcs/ft_printf.c srcs/ft_printf_utils.c \

SRCS_B	=	bonus/main_bonus.c bonus/get_next_line_bonus.c bonus/messages_bonus.c \
			bonus/parser_bonus.c bonus/get_next_line_utils_bonus.c \
			bonus/parser2_bonus.c bonus/render_bonus.c bonus/animation_bonus.c \
			bonus/ft_printf_bonus.c bonus/ft_printf_utils_bonus.c \
			bonus/ft_itoa.c bonus/ft_lists.c bonus/enemies_bonus.c

HEADER	=	include/so_long.h include/so_long_bonus.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))
OBJ_B	=	$(patsubst %.c, %.o, $(SRCS_B))

Y = "\033[33m"
X = "\033[0m"
G = "\033[32m"



CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

MLX		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)
	
$(NAME)	:	$(OBJ) $(HEADER)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(MLX)
	@echo $(G)Finished [$(NAME)]$(X)

%.o	:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus	:
	@make OBJ="$(OBJ_B)"

clean	:
	@echo $(Y)Deleting object files...$(X)
	@rm -f $(OBJ) $(OBJ_B)
	@echo $(G)Files deletion completed...$(X)

fclean	: clean
	@echo $(Y)and deleting [$(NAME)]...$(X)
	@rm -f $(NAME)
	@echo $(G)[$(NAME)]deletion completed...$(X)

re		: fclean all

.PHONY	:	all clean fclean re bonus
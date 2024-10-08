# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 12:39:34 by belamiqu          #+#    #+#              #
#    Updated: 2023/12/07 19:55:28 by belamiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c so_long_checkmap.c so_long_utils.c so_long_graphics.c \
	  so_long_moves.c so_long_moves_utils.c so_long_floodfill.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -I./minilibx_opengl/ -L./minilibx_opengl# -g3 -fsanitize=address

all: lib $(NAME)

$(NAME): $(SRC) $(OBJ) so_long.h
	$(CC) $(FLAGS) -lmlx -framework OpenGl -framework AppKit $(SRC) -o $(NAME) 

%.o: %.CC
	$(CC) -c $(FLAGS) -Imlx $< -o $@

execute:
	./$(NAME) maps/map3.ber

clean:
	rm -rf $(OBJ)
	$(MAKE) -C minilibx_opengl clean

fclean:	clean
		rm -rf $(NAME)

re: fclean all

lib:
	$(MAKE) -C minilibx_opengl

.PHONY: all execute clean fclean re lib
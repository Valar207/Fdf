# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrossi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 18:31:54 by vrossi            #+#    #+#              #
#    Updated: 2019/09/18 10:55:57 by vrossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
HEADERS = libft.h
FLAGS =  -Wall -Wextra -Werror
FILES = src/main.c \
		src/get_coord.c \
		src/draw_line.c \
		src/ft_print_map.c \
		src/events.c \
		src/rotation.c \
		src/color.c \
		src/init_var.c \
		src/key_events.c \
		src/fill_pix.c
LIB = ./src/libft/libft.a

OBJ =	$(FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) -I /usr/local/include $(FILES) -L /usr/local/lib -lmlx $(LIB) -framework openGL -framework AppKit

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

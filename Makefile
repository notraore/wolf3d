# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: notraore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 16:56:22 by lramirez          #+#    #+#              #
#    Updated: 2017/09/02 19:32:56 by notraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
CC=gcc
SRC=srcs/main.c srcs/keyboard.c srcs/inits.c srcs/ft_line_and_color.c\
srcs/raycasting.c srcs/movement_input.c srcs/errors.c\
srcs/draw_formes.c srcs/hud.c
OBJ=main.o movement_input.o inits.o ft_line_and_color.o raycasting.o keyboard.o\
draw_formes.o errors.o hud.o
FLAGS=-Wall -Wextra -Werror
LIB=-L ./libft -lft
MLX=-L ./miniLibx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "\033[92m\t\t\t---> ✓ libft created. ✓ <---\033[0m"
	@ make -C ./libft
	# @ make -C ./minilibx
	@ echo "\033[92m\t---> ✓ wolf3d program has been successfully created. ✓ <---\033[0m"
	@ $(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIB)
$(OBJ): $(SRC)
	@ $(CC) $(FLAGS) -c $(SRC)
clean:
	@ echo "\033[1;33m---> All .o files cleared. ✓ <---\033[0m"
	@ rm -f $(OBJ)
	@ make -C ./libft clean
	# @ make -C ./minilibx clean
fclean: clean
	@ echo "\033[1;33m---> Everything has been cleared. ✓ <---\033[2;00m"
	@ rm -f $(NAME)
	@ make -C ./libft fclean
	# @ make -C ./minilibx fclean
re: fclean all

.PHONY: clean, fclean, re

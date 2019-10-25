# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 17:09:24 by mmonahan          #+#    #+#              #
#    Updated: 2019/10/25 17:37:11 by mmonahan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =  main.c \
		put_line.c \
		input_map.c \
		fdf.c \
		draw_grid.c \
		initialization.c \
		calculation.c \
		info.c \
		validation.c \
		put_map_point_fd.c \
		hook_deal_key.c \
		get_next_line/get_next_line.c

HEADER = fdf.h

MLX = minilibx_macos

INCLUDES_MLX = $(MLX)/*.h

FLAGS_MLX =

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
		@echo "Сборка библиотеки libft.a"
		@make -C libft/ fclean && make -C libft/
		@echo "Сборка библиотеки mlx"
		@make -C minilibx_macos/ re
		@gcc $(SRC) $(FLAGS) -I $(HEADER) -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L libft -lft
clean:
		@make -C libft/ clean
		@make -C minilibx_macos/ clean
		@echo "Удаляем файлы компиляции"
		@rm -f $(OBJ)

fclean: clean
		@make -C libft/ fclean
		@make -C minilibx_macos/ fclean
		@echo "Удаляем $(NAME)"
		@rm -f $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

re: clean fclean
.PHONY: all clean fclean re

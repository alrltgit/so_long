# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apple <apple@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:11:03 by apple             #+#    #+#              #
#    Updated: 2025/03/04 11:02:12 by apple            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = src/game.c \
src/move_player.c \
src/read_map.c \
src/so_long.c \
src/map_validation/map_chars_check.c \
src/map_validation/map_form_check.c \
src/map_validation/map_is_empty_check.c \
src/map_validation/map_valid_path_check.c \
src/map_validation/map_walls_check.c \
src/helpers/create_node.c \
src/helpers/free.c \
src/helpers/helpers.c \
src/helpers/move_player_helper_func.c \
src/helpers/read_map_helper_funcs.c

OBJS = $(SRC:.c=.o)

LIBFT_PATH = libft

MLX_PATH = mlx
MLX_LIB = libmlx.a

LIBFT_NAME = libft.a

SO_LONG_NAME = so_long

$(SO_LONG_NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_PATH) -lft -o $(SO_LONG_NAME)

all: $(SO_LONG_NAME)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	$(RM) $(LIBFT_PATH)/ft_printf/libftprintf.a
	$(RM) $(MLX_PATH)/$(MLX_LIB)
	$(RM) $(SO_LONG_NAME)

re: fclean all

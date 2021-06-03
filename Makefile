# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 18:03:37 by jtambra           #+#    #+#              #
#    Updated: 2021/05/23 18:37:41 by jtambra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

NAME = cub3D

LIBFT_DIR = ./libft/

MLX_DIR = ./mlx/
MLX = $(MLX_DIR)libmlx.dylib

GNL_DIR = ./get_next_line/

INC = -I./includes/ -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

LIBS = -L $(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit -lm

FLAGS = -Wall -Wextra -Werror -O3 $(INC) -MD

CC = gcc

GNL = $(GNL_DIR)get_next_line.c\
		$(GNL_DIR)get_next_line_utils.c \
		$(GNL_DIR)get_next_line_utils2.c

SRCS = $(addprefix ./srcs/,\
		cub3D.c\
		initialization/init_config.c\
		render/render.c\
		raycasting/raycasting.c\
		moving/moving.c\
		screenshot/make_screenshot.c\
		parse/parse_line.c\
		parse/parse_color.c\
		parse/parse_texture.c\
		parse/parse_resolution.c\
		parse/parse_map.c\
		parse/check_map.c\
		parse/parse_position.c\
		parse/check_config_map.c\
		parse/tools.c\
		raycasting/calculations.c\
		raycasting/wall_calculations.c\
		raycasting/draw_textures.c\
		raycasting/draw_sprites.c\
		raycasting/drawing_sprites.c\
		raycasting/malloc_sprites.c\
		moving/move_back_forw.c\
		moving/move_left_right.c\
		moving/turn_left_right.c\
		moving/set_direction.c\
		render/get_texture.c)

OBJS = $(SRCS:.c=.o)
D_FILES = $(SRCS:.c=.d)
GNL_OBJS = $(GNL:.c=.o)
D_FILES_GNL = $(GNL:.c=.d)


all: $(NAME)

debug: FLAGS += -fsanitize=address -g
debug: all

$(NAME): ${OBJS} ${GNL_OBJS} | tools
		cp $(MLX) libmlx.dylib
		${CC} ${FLAGS} -o ${NAME} ${OBJS} ${GNL_OBJS} ${LIBS} ${MLX}
include $(wildcard $(D_FILES))

.c.o:
	${CC} ${FLAGS} -c $< -o $@

tools:
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)

clean:
	rm -f ${OBJS} ${GNL_OBJS} ${D_FILES} ${D_FILES_GNL}
	rm -f Cub3D.bmp
	rm -f libmlx.dylib
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -rf ${NAME}
	make -C $(LIBFT_DIR) fclean

re: fclean all

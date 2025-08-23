# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/07/23 13:57:19 by jaehlee           #+#    #+#              #
#    Updated: 2025/07/23 13:57:19 by jaehlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes -I mlx -I libft -I get_next_line

SRCS = src/main.c \
        utils/game.c \
        utils/img.c \
        utils/map.c \
        utils/player.c \
        utils/utils.c
        #utils/move.c \#


OBJS = $(SRCS:%.c=%.o)

MLX_DIR = mlx
LIBFT_DIR = libft
GNL_DIR = get_next_line

GNL_SRCS = $(GNL_DIR)/get_next_line.c \
           $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
GNL_LIB = $(GNL_DIR)/gnl.a

LFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a $(GNL_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -l:gnl.a $(LFLAGS) -o $(NAME)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR) all

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) all

$(GNL_LIB): $(GNL_OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(GNL_OBJS)

fclean: clean
	$(MAKE) -C $(MLX_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(GNL_LIB)

re: fclean all

.PHONY: all clean fclean re
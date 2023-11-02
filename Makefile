# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 15:05:59 by ncruz-ga          #+#    #+#              #
#    Updated: 2023/10/25 11:20:04 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/so_long.c src/read_map.c src/check_map src/valid_way.c src/image.c src/player.c src/resize.check_map

OBJ = $(SRC:.c = .o)

MLX_PATH = ./MLX42

MLX = $(MLX_PATH)/libmlx.42.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

SO_LONG = so_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs

LIB_SYS = -Iinclude -lglfw -L "/User/ncruz-ga/.brew/opt/glfw/lib/"

RM = rm -fr

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
				$(LIB) $(SO_LONG) $(OBJ)
				$(CC) $(CFLAGS) $(SO_LONG) $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(OBJ):		src/%.o : src/%.
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)
					@make -s -C $(LIBFT_PATH)

$(MLX)
					@make -s -C $(MLX_PATH)

all:		$(NAME)

clean:
					$(RM) $(OBJ)
					make clean -s -C $(MLX-PATH)
					make clean -s -C $(LIBFT_PATH)

fclean:
					$(RM) $(NAME) $(OBJ) $(SO_LONG) $(LIBFT) $(MLX)
					make fclean -s -C $(MLX-PATH)
					make flcean -s -C $(LIBFT_PATH)

re:			fclean all

solong:		all clean

.PHONY: all re clean fclean solong
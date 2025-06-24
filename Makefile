# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 12:54:07 by nsilva-n          #+#    #+#              #
#    Updated: 2025/06/24 12:34:20 by mlameira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	main.c validate.c init_all.c																									\
		others/ft_close.c others/ft_copy_info.c others/ft_copy_ints.c others/ft_copy_map.c others/ft_debugger.c others/ft_free_strs.c	\
		others/ft_get_info.c others/ft_get_map_size.c others/ft_global.c others/ft_init_global.c others/ft_main_ver.c					\
		others/ft_ver_info.c others/ft_ver_line.c																						\
		exit.c raycasting/dd_ray.c raycasting/floorcast.c					\
		testes.c raycasting/moviment.c raycasting/texture.c\

OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_LIB = ./libft
MLIBX_LIB = ./minilibx-linux
INCLUDE_LFT = ./libft/libft.a
INCLUDE_MLX = ./minilibx-linux/libmlx_Linux.a


all: $(LIBFT) $(NAME)

.c.o:
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C $(LIBFT_LIB)
	@make -C $(MLIBX_LIB) -Lmlx -lXext -lX11
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME} $(INCLUDE_LFT) ${INCLUDE_MLX} -Lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR) 
	@mkdir -p $(OBJ_DIR)/others
	@mkdir -p $(OBJ_DIR)/raycasting 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C ./$(LIBFT_LIB)
	@make clean -C ./$(MLIBX_LIB)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./$(LIBFT_LIB)
	
re: fclean all

.PHONY: all clean fclean re
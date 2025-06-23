# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 12:54:07 by nsilva-n          #+#    #+#              #
#    Updated: 2025/06/23 11:52:10 by mlameira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	testes.c maping.c get_next_line.c get_next_line_utils.c\
			raycasting/dd_ray.c raycasting/moviment.c raycasting/texture.c\
			raycasting/floorcast.c

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
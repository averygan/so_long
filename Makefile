# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:03:20 by agan              #+#    #+#              #
#    Updated: 2023/11/13 17:03:21 by agan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
NAME_BONUS = so_long_bonus
SRCS	= srcs/so_long.c srcs/utils.c srcs/assets.c srcs/render.c srcs/map.c \
			srcs/map_validation.c srcs/free.c srcs/game_init.c srcs/move.c
SRCS_BONUS = srcs_bonus/so_long_bonus.c srcs_bonus/utils_bonus.c srcs_bonus/assets_bonus.c \
				srcs_bonus/render_bonus.c srcs_bonus/map_bonus.c \
				srcs_bonus/map_validation_bonus.c srcs_bonus/free_bonus.c \
				srcs_bonus/game_init_bonus.c srcs_bonus/move_bonus.c srcs_bonus/enemy_bonus.c
OBJS 	= ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -fr

#includes
INC		= -I ./includes/\

#libft
LIBFT_DIR = ./libft
LIBFT_BUILD := ./libft/libft.a

#minilibx
MINILIBX_DIR = ./minilibx-linux/
MINILIBX = $(addprefix $(MINILIBX_DIR), libmlx.a)
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lbsd

all: ${NAME}

${NAME} : ${OBJS} ${LIBFT_BUILD} minilibx
	@$(CC) ${CFLAGS} ${OBJS} ${LIBFT_BUILD} ${MINILIBX_FLAGS} -o ${NAME}
	@echo "so_long compiled!"

.c.o:
	@$(CC) ${CFLAGS} -c $< -o $@

bonus : ${OBJS_BONUS} ${LIBFT_BUILD} minilibx
	@$(CC) ${CFLAGS} ${OBJS_BONUS} ${LIBFT_BUILD} ${MINILIBX_FLAGS} -o ${NAME_BONUS}
	@echo "so_long bonus compiled!"

#libft
${LIBFT_BUILD}:
	@make -s -C ${LIBFT_DIR}

minilibx:
	@$(MAKE) -s -C ${MINILIBX_DIR}

clean:
	@make -s clean -C ${LIBFT_DIR}
	@make -s clean -C ${MINILIBX_DIR}
	@rm -fr ${OBJS}
	@rm -fr ${OBJS_BONUS}

fclean: clean
	@make -s fclean -C ${LIBFT_DIR}
	@make -s clean -C ${MINILIBX_DIR}
	@rm -f ${NAME}
	@rm -f ${NAME_BONUS}
	@echo "fclean Completed!"

re: fclean all

.PHONY: all clean fclean re
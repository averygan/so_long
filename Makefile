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
SRCS	= srcs/so_long.c srcs/utils.c
OBJS 	= ${SRCS:.c=.o}
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

#libft
${LIBFT_BUILD}:
	@make -s -C ${LIBFT_DIR}

minilibx:
	@$(MAKE) -s -C ${MINILIBX_DIR}

clean:
	@make -s clean -C ${LIBFT_DIR}
	@make -s clean -C ${MINILIBX_DIR}
	@rm -fr ${OBJS}

fclean: clean
	@make -s fclean -C ${LIBFT_DIR}
	@make -s clean -C ${MINILIBX_DIR}
	@rm -f ${NAME}
	@echo "fclean Completed!"

re: fclean all

.PHONY: all clean fclean re
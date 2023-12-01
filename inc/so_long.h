/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:11:56 by agan              #+#    #+#             */
/*   Updated: 2023/11/30 13:11:57 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

# define BUF_SIZE 1000

#ifdef __linux__
#	include "../minilibx-linux/mlx.h"
#  define OS_LINUX 1
#  define W_KEY 119
#  define S_KEY 115
#  define A_KEY 97
#  define D_KEY 100
#  define ESC 65307
#  define ON_DESTROY 17
#endif

// Struct to store data for images
typedef struct	s_img 
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	t_img side;
	t_img tile;
	t_img wall;
}	t_map;

// Struct for game attributes
typedef struct s_game 
{
	void *mlx;
	void *window;
	int	width;
	int height;
	char **map_arr;
	t_map map;
}	t_game;

// Stores possible legal moves
typedef struct s_moves
{
	int up;
	int down;
	int left;
	int right;
}	t_moves;

// Utils functions
int error_handler(int err);
int exit_handler(void);

#endif


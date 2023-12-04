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

// Define path for assets
# define WALL_PATH	"./assets/tiles/tree.xpm"
# define FLOOR_PATH	"./assets/tiles/floor.xpm"
# define SPRITE_SIZE 32

// Struct to store data for images
typedef struct	s_img 
{
	void	*ptr;
	int		bpp;
	int		line_length;
	int		x;
	int		y;
	int		endian;
}	t_img;

// Struct for game attributes
typedef struct s_game 
{
	void	*mlx;
	void	*window;
	int		width;
	int 	height;
	char	**map_arr;
	int		coin;
	t_img	wall;
	t_img	floor;
	int start[2];
	int exit[2];
}	t_game;

typedef struct s_player
{
	int coins_collected;
	int position[2];
	int win;
	int lose;
} t_player;

// Stores possible legal moves
typedef struct s_moves
{
	int up;
	int down;
	int left;
	int right;
}	t_moves;

// Map validation functions

// Game functions
int game_init(t_game *game);
void set_window_size(t_game *game);

// Utils functions
int error_handler(int err);
int exit_handler(void);
void struct_init(t_game *game);

// Map functions
int map_init(char **argv, t_game *game);
void map_to_window(t_game *game, int y, int x);
void render_map(t_game *game);

// Assets functions
t_img load_image(void *mlx, char *path);
void init_assets(t_game *game);

#endif


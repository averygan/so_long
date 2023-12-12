/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:11:56 by agan              #+#    #+#             */
/*   Updated: 2023/12/11 13:36:14 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>

# define BUF_SIZE 1000

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define OS_LINUX 1
#  define W_KEY 119
#  define S_KEY 115
#  define A_KEY 97
#  define D_KEY 100
#  define ESC 65307
#  define ON_DESTROY 17
# endif

// Define path for assets
# define WALL_PATH	"./assets/tiles/wall.xpm"
# define FLOOR_PATH	"./assets/tiles/floor.xpm"
# define HERO_L_PATH "./assets/sprite/hero_l.xpm"
# define HERO_R_PATH "./assets/sprite/hero_r.xpm"
# define HERO_U_PATH "./assets/sprite/hero_u.xpm"
# define HERO_D_PATH "./assets/sprite/hero_d.xpm"
# define HERO_2_L_PATH "./assets/sprite/hero_2_l.xpm"
# define HERO_2_R_PATH "./assets/sprite/hero_2_r.xpm"
# define HERO_2_U_PATH "./assets/sprite/hero_2_u.xpm"
# define HERO_2_D_PATH "./assets/sprite/hero_2_d.xpm"
# define EXIT_PATH "./assets/tiles/exit.xpm"
# define C_PATH "./assets/sprite/bomb.xpm"

# define SPRITE_SIZE 32

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

// Struct to store data for images
typedef struct s_img
{
	void	*ptr;
	int		bpp;
	int		line_length;
	int		x;
	int		y;
	int		endian;
}	t_img;

// Stores possible legal moves
typedef struct s_moves
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_moves;

typedef struct s_player
{
	int		coins;
	t_coord	pos;
	bool	win;
	int		move_count;
	t_moves	valid_move;
	int 	curr_dir;
	int 	animation;
}	t_player;

typedef struct s_map
{
	int		valid_path;
	int		valid_collectibles;
	int		valid_start;
	int		valid_exit;
	int		c_visible;
	t_img	wall;
	t_img	floor;
	t_img	hero[4];
	t_img	hero_2[4];
	t_img	collectible;
	t_img	exit;
}	t_map;

// Struct for game attributes
typedef struct s_game 
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	char		**map_arr;
	int			coin;
	char		*map_buf;
	t_player	player;
	t_map		map;
}	t_game;

// Map initialization and parsing functions
int		map_init(char **argv, t_game *game);
void	set_window_size(t_game *game);
void	player_pos(t_game *game);
void	init_map_struct(t_game *game);

// Map validation functions
void	map_validation(t_game *game);
void	path_checker(t_game *game, char ***tmp_map, int y, int x);
void	map_checker(char **map_arr, t_game *game);
void	wall_checker(t_game *game);
void	rectangle_checker(char **map, t_game *game);

// Game init functions
int		game_init(t_game *game);

// Movement functions
void	update_legal_moves(t_game *game, t_coord pos, t_moves *valid_move);
int		key_handler(int keysym, t_game *game);
void	update_pos(t_game *game, t_coord *pos, int dir);

// Utils functions
int		close_game(t_game *game);
int		error_handler(int err, t_game *game);
void	exit_handler(int close, t_game *game);
void	struct_init(t_game *game);

// Render functions
void	img_to_window(t_game *game, t_img *ptr, int y, int x);
void	map_to_window(t_game *game, int y, int x);
void	render_player(t_game *game);
void	render_collectibles(t_game *game);
void	render_map(t_game *game);

// Assets functions
t_img	load_image(void *mlx, char *path);
void	init_assets(t_game *game);

// Free functions
void	free_map(char **s);

#endif

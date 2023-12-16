/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:54 by agan              #+#    #+#             */
/*   Updated: 2023/12/05 17:34:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Fuction to init struct variables
void	struct_init(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->player.move_count = 0;
	game->player.coins = 0;
}

// Init height and width
void	set_window_size(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
			x++;
		y++;
	}
	game->width = x;
	game->height = y;
}

// Game init function to initialize mlx and game window
int	game_init(t_game *game)
{
	struct_init(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width * 
			SPRITE_SIZE, game->height * SPRITE_SIZE, "so_long");
	init_assets(game);
	render_map(game);
	render_player(game);
	render_collectibles(game);
	mlx_key_hook(game->window, key_handler, game);
	mlx_hook(game->window, ON_DESTROY, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}

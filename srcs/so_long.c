/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:02:59 by agan              #+#    #+#             */
/*   Updated: 2023/11/13 17:30:43 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Game init function to initialize mlx and game window
int game_init(t_game *game)
{
	struct_init(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width * SPRITE_SIZE, game->height * SPRITE_SIZE, "so_long");
	init_assets(game);
	render_map(game);
	mlx_hook(game->window, ON_DESTROY, 0, exit_handler, &game);
	mlx_loop(game->mlx);
	return (0);
}

// Init height and width
void set_window_size(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while(game->map_arr[y][x])
			x++;
		y++;
	}
	game->width = x;
	game->height = y;
}

// Main takes in argument and runs error checking for map
// If input is valid, initialize game
int	main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		// Read .ber file
		if (map_init(argv, &game) == -1)
			error_handler(0);
		game_init(&game);
	}
}

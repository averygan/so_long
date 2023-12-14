/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:54 by agan              #+#    #+#             */
/*   Updated: 2023/12/11 13:39:55 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

// Init enemy
void enemy_init(t_game *game)
{
	int		i;
	t_coord	coord;

	i = 0;
	coord.y = 0;
	while (game->map_arr[coord.y])
	{
		coord.x = 0;
		while (game->map_arr[coord.y][coord.x])
		{
			if (game->map_arr[coord.y][coord.x] == 'X')
			{
				game->enemy[i].pos.y = coord.y;
				game->enemy[i].pos.x = coord.x;
				game->enemy[i].curr_dir = RIGHT_N;
				i++;
			}
			coord.x++;
		}
		coord.y++;
	}
}

// Fuction to init struct variables
void	struct_init(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->player.move_count = 0;
	game->player.coins = 0;
	game->player.curr_dir = 3;
	game->player.animation = 0;
}

// Function to render move count
void	render_moves(t_game *game)
{
	char *num;

	num = ft_itoa(game->player.move_count);
	mlx_string_put(game->mlx, game->window, 16, 16, WHITE, "Moves: ");
	mlx_string_put(game->mlx, game->window, 55, 16, WHITE, num);
	free(num);
}

int	update_game(t_game *game)
{
	render_collectibles(game, false);
	move_enemy(game);
	check_enemy_collision(game);
	render_moves(game);
	return (0);
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
	render_collectibles(game, true);
	if (game->enemy_count > 0)
	{
		enemy_init(game);
		render_enemy(game);
	}
	render_player(game);
	mlx_key_hook(game->window, key_handler, game);
	mlx_hook(game->window, ON_DESTROY, 0, close_game, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_loop(game->mlx);
	return (0);
}

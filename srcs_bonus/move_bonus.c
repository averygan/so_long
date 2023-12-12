/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:44:33 by agan              #+#    #+#             */
/*   Updated: 2023/12/11 13:40:43 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

// Update position of player
void	update_pos(t_game *game, t_coord *pos, int dir)
{
	game->player.curr_dir = dir;
	if (dir == 0)
		pos->y--;
	else if (dir == 1)
		pos->y++;
	else if (dir == 2)
		pos->x--;
	else if (dir == 3)
		pos->x++;
	game->player.move_count++;
	ft_printf("moves: %d\n", game->player.move_count);
}

void	ft_delay(int delay)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i++ <= delay)
	{
		while (j++ <= delay)
			asm("nop");
	}
}

// Function to update map based on player's movement
void	update_map(t_game *game)
{
	t_coord	coord;

	coord.y = game->player.pos.y;
	coord.x = game->player.pos.x;
	render_map(game);
	render_player(game);
	if (game->map_arr[coord.y][coord.x] == 'C')
	{
		game->player.coins++;
		game->map_arr[coord.y][coord.x] = '0';
	}
	if (game->map_arr[coord.y][coord.x] == 'E' && game->player.coins == 
		game->map.valid_collectibles)
	{
		game->player.win = 1;
		exit_handler(2, game);
	}
	render_collectibles(game);
}

// Function for game logic based on key pressed
int	key_handler(int keysym, t_game *game)
{
	update_legal_moves(game, game->player.pos, &game->player.valid_move);
	if (keysym == ESC)
		close_game(game);
	else if (keysym == W_KEY && game->player.valid_move.up)
		update_pos(game, &(game->player.pos), 0);
	else if (keysym == S_KEY && game->player.valid_move.down)
		update_pos(game, &(game->player.pos), 1);
	else if (keysym == A_KEY && game->player.valid_move.left)
		update_pos(game, &(game->player.pos), 2);
	else if (keysym == D_KEY && game->player.valid_move.right)
		update_pos(game, &(game->player.pos), 3);
	update_map(game);
	return (0);
}

// Function to update player's legal moves when keyhook pressed
void	update_legal_moves(t_game *game, t_coord pos, t_moves *valid_move)
{
	valid_move->up = 0;
	valid_move->down = 0;
	valid_move->left = 0;
	valid_move->right = 0;
	if (game->map_arr[pos.y - 1][pos.x] != '1')
		valid_move->up = 1;
	if (game->map_arr[pos.y + 1][pos.x] != '1')
		valid_move->down = 1;
	if (game->map_arr[pos.y][pos.x + 1] != '1')
		valid_move->right = 1;
	if (game->map_arr[pos.y][pos.x - 1] != '1')
		valid_move->left = 1;
}

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
		exit_handler(2, game);
	render_enemy(game);
}

// Helper function for key handler
void	movement_handler(t_game *game, int dir)
{
	if (dir == UP_N)
	{
		game->player.curr_dir = UP_N;
		if (game->player.valid_move.up)
			update_pos(game, &(game->player.pos), 0);
	}
	if (dir == DOWN_N)
	{
		game->player.curr_dir = DOWN_N;
		if (game->player.valid_move.down)
			update_pos(game, &(game->player.pos), 1);
	}
	if (dir == LEFT_N)
	{
		game->player.curr_dir = LEFT_N;
		if (game->player.valid_move.left)
			update_pos(game, &(game->player.pos), 2);
	}
	if (dir == RIGHT_N)
	{
		game->player.curr_dir = RIGHT_N;
		if (game->player.valid_move.right)
			update_pos(game, &(game->player.pos), 3);
	}
}

// Function for game logic based on key pressed
int	key_handler(int keysym, t_game *game)
{
	update_legal_moves(game, game->player.pos, &game->player.valid_move);
	if (keysym == ESC)
		close_game(game);
	else if (keysym == W_KEY || keysym == UP_KEY)
		movement_handler(game, UP_N);
	else if (keysym == S_KEY || keysym == DOWN_KEY)
		movement_handler(game, DOWN_N);
	else if (keysym == A_KEY || keysym == LEFT_KEY)
		movement_handler(game, LEFT_N);
	else if (keysym == D_KEY || keysym == RIGHT_KEY)
		movement_handler(game, RIGHT_N);
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

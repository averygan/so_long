/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:44:33 by agan              #+#    #+#             */
/*   Updated: 2023/12/07 11:44:34 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void update_pos(t_game *game, t_coord *pos, char dir)
{
	if (dir == 'w')
		pos->y--;
	else if (dir == 's')
		pos->y++;
	else if (dir == 'a')
		pos->x--;
	else if (dir == 'd')
		pos->x++;
	game->player.move_count++;
	ft_printf("moves: %d\n", game->player.move_count);
}

void update_map(t_game *game)
{
	t_coord coord;

	coord.y = game->player.pos.y;
	coord.x = game->player.pos.x;
	render_map(game);
	render_player(game);
	if (game->map_arr[coord.y][coord.x] == 'C')
	{
		game->player.coins++;
		game->map_arr[coord.y][coord.x] = '0';
		ft_printf("collected %d/%d\n", game->player.coins, game->map.valid_collectibles);
	}
	if (game->map_arr[coord.y][coord.x] == 'E' && game->player.coins == game->map.valid_collectibles)
	{
		game->player.win = 1;
		exit_handler(2);
	}
	render_collectibles(game);
}

int key_handler(int keysym, t_game *game)
{
	update_legal_moves(game, game->player.pos, &game->player.valid_move);
	if (keysym == ESC)
		exit_handler(0);
	else if (keysym == W_KEY && game->player.valid_move.up)
		update_pos(game, &(game->player.pos), 'w');
	else if (keysym == S_KEY && game->player.valid_move.down)
		update_pos(game, &(game->player.pos), 's');
	else if (keysym == A_KEY && game->player.valid_move.left)
		update_pos(game, &(game->player.pos), 'a');
	else if (keysym == D_KEY && game->player.valid_move.right)
		update_pos(game, &(game->player.pos), 'd');
	// printf("curr pos is %d %d\n", game->player.pos.y, game->player.pos.x);
	update_map(game);
	return (0);
}

void update_legal_moves(t_game *game, t_coord pos, t_moves *valid_move)
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
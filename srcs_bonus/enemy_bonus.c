/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:19:29 by agan              #+#    #+#             */
/*   Updated: 2023/12/12 17:19:29 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

// Check if enemy has collided with player
void	check_enemy_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemy[i].pos.y == game->player.pos.y && \
			game->enemy[i].pos.x == game->player.pos.x)
			exit_handler(3, game);
		i++;
	}
}

// Update enemy's current position
void	update_enemy_pos(t_enemy *enemy)
{
	if (enemy->curr_dir == UP_N)
		enemy->pos.y--;
	if (enemy->curr_dir == DOWN_N)
		enemy->pos.y++;
	if (enemy->curr_dir == LEFT_N)
		enemy->pos.x--;
	if (enemy->curr_dir == RIGHT_N)
		enemy->pos.x++;
}

// If enemy meets a wall, change direction to next valid move
void	change_enemy_dir(t_game *game, t_enemy *enemy)
{
	while (!enemy_valid_move(game, *enemy))
	{
		if (enemy->curr_dir < 3)
			enemy->curr_dir++;
		else
			enemy->curr_dir = 0;
	}
	update_enemy_pos(enemy);
}

// Render enemy's new pos on map
void	move_enemy(t_game *game)
{
	static int	counter;
	int			i;

	counter++;
	if (counter < ENEMY_SPEED)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		if (enemy_valid_move(game, game->enemy[i]))
		{
			img_to_window(game, game->map.floor.ptr, game->enemy[i].pos.y, 
				game->enemy[i].pos.x);
			update_enemy_pos(&game->enemy[i]);
		}
		else
		{
			img_to_window(game, game->map.floor.ptr, game->enemy[i].pos.y, 
				game->enemy[i].pos.x);
			change_enemy_dir(game, &game->enemy[i]);
		}
		render_enemy(game);
		i++;
	}
	counter = 0;
}

// Checks if enemy's next move is valid
int	enemy_valid_move(t_game *game, t_enemy enemy)
{
	if (enemy.curr_dir == UP_N && !ft_strrchr("1CE", 
			game->map_arr[enemy.pos.y - 1][enemy.pos.x]))
		return (1);
	if (enemy.curr_dir == DOWN_N && !ft_strrchr("1CE", 
			game->map_arr[enemy.pos.y + 1][enemy.pos.x]))
		return (1);
	if (enemy.curr_dir == LEFT_N && !ft_strrchr("1CE", 
			game->map_arr[enemy.pos.y][enemy.pos.x - 1]))
		return (1);
	if (enemy.curr_dir == RIGHT_N && !ft_strrchr("1CE", 
			game->map_arr[enemy.pos.y][enemy.pos.x + 1]))
		return (1);
	return (0);
}

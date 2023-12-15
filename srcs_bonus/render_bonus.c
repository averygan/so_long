/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:36 by agan              #+#    #+#             */
/*   Updated: 2023/12/11 13:40:51 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	img_to_window(t_game *game, t_img *ptr, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->window, ptr, 
		(x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

// Function to render player and collectibles
void	render_player(t_game *game)
{
	if (game->player.animation == 1)
	{
		if (game->player.curr_dir == 0)
			img_to_window(game, game->map.hero[0].ptr, game->player.pos.y,
				game->player.pos.x);
		if (game->player.curr_dir == 1)
			img_to_window(game, game->map.hero[1].ptr, game->player.pos.y,
				game->player.pos.x);
		if (game->player.curr_dir == 2)
			img_to_window(game, game->map.hero[2].ptr, game->player.pos.y,
				game->player.pos.x);
		if (game->player.curr_dir == 3)
			img_to_window(game, game->map.hero[3].ptr, game->player.pos.y,
				game->player.pos.x);
		game->player.animation = 0;
	}
	else
	{
		if (game->player.curr_dir == 0)
			img_to_window(game, game->map.hero_2[0].ptr, game->player.pos.y,
				game->player.pos.x);
		if (game->player.curr_dir == 1)
			img_to_window(game, game->map.hero_2[1].ptr, game->player.pos.y,
				game->player.pos.x);
		if (game->player.curr_dir == 2)
			img_to_window(game, game->map.hero_2[2].ptr, game->player.pos.y,
				game->player.pos.x);
		if (game->player.curr_dir == 3)
			img_to_window(game, game->map.hero_2[3].ptr, game->player.pos.y,
				game->player.pos.x);
		game->player.animation = 1;
	}
}

void	render_collectibles(t_game *game, bool start)
{
	t_coord	coord;
	static int counter;
	static int i;

	counter++;
	if (counter < 30000 && start == false)
		return ;
	coord.y = 0;
	while (game->map_arr[coord.y])
	{
		coord.x = 0;
		while (game->map_arr[coord.y][coord.x])
		{
			if (game->map_arr[coord.y][coord.x] == 'C')
			{
				if (i == 0)
					img_to_window(game, game->map.collectible[0].ptr, coord.y, coord.x);
				if (i == 1)
					img_to_window(game, game->map.collectible[1].ptr, coord.y, coord.x);
				if (i == 2)
					img_to_window(game, game->map.collectible[2].ptr, coord.y, coord.x);
			}
			coord.x++;
		}
		coord.y++;
	}
	i++;
	if (i == 3)
		i = 0;
	counter = 0;
}

// Function to render n enemies
void	render_enemy(t_game *game)
{
	int i;

	i = 0;
	while (i < game->enemy_count)
	{
		img_to_window(game, game->map.enemy[0].ptr, game->enemy[i].pos.y, game->enemy[i].pos.x);
		i++;
	}
}

// If map is valid, render map
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
		{
			if (game->map_arr[y][x] == '1')
				img_to_window(game, game->map.wall.ptr, y, x);
			else if (game->map_arr[y][x] == 'E')
				img_to_window(game, game->map.exit.ptr, y, x);
			else if (game->map_arr[y][x] != 'C')
				img_to_window(game, game->map.floor.ptr, y, x);
			x++;
		}
		y++;
	}
	return ;
}

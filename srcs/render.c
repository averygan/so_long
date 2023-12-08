/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:36 by agan              #+#    #+#             */
/*   Updated: 2023/12/04 13:26:41 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	img_to_window(t_game *game, t_img *ptr, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->window, ptr, 
		(x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

// Function to render player and collectibles
void	render_player(t_game *game)
{
	img_to_window(game, game->map.hero.ptr, game->player.pos.y,
		game->player.pos.x);
}

void	render_collectibles(t_game *game)
{
	t_coord	coord;

	coord.y = 0;
	while (game->map_arr[coord.y])
	{
		coord.x = 0;
		while (game->map_arr[coord.y][coord.x])
		{
			if (game->map_arr[coord.y][coord.x] == 'C')
				img_to_window(game, game->map.collectible.ptr, 
					coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
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
			else
				img_to_window(game, game->map.floor.ptr, y, x);
			x++;
		}
		y++;
	}
	return ;
}

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

// Push map images to window
void map_to_window(t_game *game, int y, int x)
{
	if (game->map_arr[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->map.wall.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->window, game->map.floor.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

// If map is valid, render map
void render_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
		{
			map_to_window(game, y, x);
			x++;
		}
		y++;
	}
	return ;
}
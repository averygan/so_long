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

// void	ft_delay(int delay)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i++ <= delay)
// 	{
// 		while (j++ <= delay)
// 			asm("nop");
// 	}
// }

// // Render first frame -> delay -> render second frame
// void	render_animation(t_game *game)
// {
// 	if (game->player.curr_dir == 0)
// 		img_to_window(game, game->map.hero_2[0].ptr, game->player.pos.y,
// 			game->player.pos.x);
// 	if (game->player.curr_dir == 1)
// 		img_to_window(game, game->map.hero_2[1].ptr, game->player.pos.y,
// 			game->player.pos.x);
// 	if (game->player.curr_dir == 2)
// 		img_to_window(game, game->map.hero_2[2].ptr, game->player.pos.y,
// 			game->player.pos.x);
// 	if (game->player.curr_dir == 3)
// 		img_to_window(game, game->map.hero_2[3].ptr, game->player.pos.y,
// 			game->player.pos.x);
// }

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

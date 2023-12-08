/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:14 by agan              #+#    #+#             */
/*   Updated: 2023/12/05 16:26:14 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Checks if map is rectangle
void rectangle_checker(char **map)
{
	int y;
	int x;
	int width;

	y = 0;
	width = ft_strlen(map[y]);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x != width)
			error_handler(2);
		y++;
	}
}

// Checks if map is surrounded by walls
void wall_checker(t_game *game)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (game->map_arr[y][x])
	{
		if (game->map_arr[y][x] != '1')
			error_handler(3);
		x++;
	}
	while (y < game->height - 1)
	{
		if (game->map_arr[y][0] != '1' || game->map_arr[y][game->width - 1] != '1')
			error_handler(3);
		y++;
	}
	x = 0;
	while (game->map_arr[y][x])
	{
		if (game->map_arr[y][x] != '1')
			error_handler(3);
		x++;
	}
}

// Checks if map has at least 1 exit, 1 collectible and 1 starting position
void map_checker(char **map_arr, t_game *game)
{
	t_coord coord;

	coord.y = 0;
	while (map_arr[coord.y])
	{
		coord.x = 0;
		while(map_arr[coord.y][coord.x])
		{
			if (map_arr[coord.y][coord.x] == 'E')
				game->map.valid_exit++;
			if (map_arr[coord.y][coord.x] == 'C')
				game->map.valid_collectibles++;
			if (map_arr[coord.y][coord.x] == 'P')
				game->map.valid_start++;
			coord.x++;
		}
		coord.y++;
	}
	if (!game->map.valid_start || !game->map.valid_exit || !game->map.valid_collectibles)
		error_handler(2);
	if (game->map.valid_exit > 1 || game->map.valid_start > 1)
		error_handler(2);
}

// Checks if there is a valid path
void path_checker(t_game *game, char ***tmp_map, int y, int x)
{
	int collectibles;

	collectibles = 0;
	if (y - 1 < 0 || x - 1 < 0 || y >= game->height || 
		x >= game->width || (*tmp_map)[y][x] == '1')
		return ;
	if ((*tmp_map)[y][x] == 'E')
		game->map.valid_path = 1;
	if ((*tmp_map)[y][x] == 'C')
		game->map.c_visible++;
	if (game->map.valid_path && game->map.c_visible >= game->map.valid_collectibles)
		return ;
	(*tmp_map)[y][x] = '1';
	path_checker(game, tmp_map, y - 1, x);
	path_checker(game, tmp_map, y + 1, x);
	path_checker(game, tmp_map, y, x + 1);
	path_checker(game, tmp_map, y, x - 1);
}

void map_validation(t_game *game, char *buf)
{
	char **tmp_map;

	rectangle_checker(game->map_arr);
	wall_checker(game);
	map_checker(game->map_arr, game);
	player_pos(game);
	tmp_map = ft_split(buf, '\n');
	// for (int i = 0; tmp_map[i]; i++)
	// 	printf("%s\n", tmp_map[i]);
	// printf("\n");
	path_checker(game, &tmp_map, game->player.pos.y, game->player.pos.x);
	// for (int i = 0; tmp_map[i]; i++)
	// 	printf("%s\n", tmp_map[i]);
	free_tmp_map(tmp_map);
	if (!game->map.valid_path || game->map.c_visible < game->map.valid_collectibles)
		error_handler(4);
}

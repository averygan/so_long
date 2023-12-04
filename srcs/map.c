/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:47:38 by agan              #+#    #+#             */
/*   Updated: 2023/12/04 14:47:39 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Check map format
int ber_checker(char *filename)
{
	int len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".ber", 4))
		error_handler(1);
	return (0);
}

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
	if (y == width)
		error_handler(2);
}

// Checks if map is surrounded by walls

// Checks if there is a valid path

// Checks if map has at least 1 exit, 1 collectible and 1 starting position
// int map_validation(char **map_arr)
// {

// }

// Function to initialize map
// -> Read .ber file
// -> malloc map_arr
// -> assign map_arr
// -> checks if map is valid
int map_init(char **argv, t_game *game)
{
	char	*buf;
	int fd;
	int bytes_read;

	ber_checker(argv[1]);
	fd = open(argv[1], O_RDONLY);
	buf = ft_calloc(BUF_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buf, BUF_SIZE);
	if (bytes_read == -1)
		return(free(buf), -1);
	// Alloc map
	game->map_arr = ft_split(buf, '\n');
	free(buf);
	// Error handling for map
	rectangle_checker(game->map_arr);
	return (0);
}

// Push map images to window
void map_to_window(t_game *game, int y, int x)
{
	if (game->map_arr[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->window, game->floor.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
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

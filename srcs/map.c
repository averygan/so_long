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

void init_map_struct(t_game *game)
{
	game->map.valid_path = 0;
	game->map.valid_path = 0;
	game->map.valid_collectibles = 0;
	game->map.valid_start = 0;
	game->map.valid_exit = 0;
	game->map.c_visible = 0;
}

// Determine player starting position
void player_pos(t_game *game)
{
	t_coord coord;

	coord.y = 0;
	while (game->map_arr[coord.y])
	{
		coord.x = 0;
		while (game->map_arr[coord.y][coord.x])
		{
			if (game->map_arr[coord.y][coord.x] == 'P')
			{
				game->player.pos.x = coord.x;
				game->player.pos.y = coord.y;
				return ;
			}
			coord.x++;
		}
		coord.y++;
	}
}

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
	init_map_struct(game);
	fd = open(argv[1], O_RDONLY);
	buf = ft_calloc(BUF_SIZE + 1, sizeof(char));
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUF_SIZE);
	if (bytes_read == -1)
		return(free(buf), -1);
	// Alloc map
	game->map_arr = ft_split(buf, '\n');
	// Error handling for map
	set_window_size(game);
	map_validation(game, buf);
	free(buf);
	return (0);
}

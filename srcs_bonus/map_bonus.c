/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:47:38 by agan              #+#    #+#             */
/*   Updated: 2023/12/11 13:40:36 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

// Initialize map variables
void	init_map_struct(t_game *game)
{
	game->map.valid_path = 0;
	game->map.valid_collectibles = 0;
	game->map.valid_start = 0;
	game->map.valid_exit = 0;
	game->map.c_visible = 0;
	game->enemy_count = 0;
}

// Determine player starting position
void	player_pos(t_game *game)
{
	t_coord	coord;

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

// Checks if characters in the map are valid
void	char_checker(t_game *game, char *buf)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (buf[i])
	{
		if (buf[i] != '0' && buf[i] != '1' && buf[i] != 'C' && 
			buf[i] != 'E' && buf[i] != 'P' && buf[i] != 'X' && buf[i] != '\n')
		{
			free(buf);
			error_handler(8, game);
		}
		i++;
	}
	i = -1;
	while (buf[++i])
		if (buf[i] != '\n')
			flag = 0;
	if (flag)
	{
		free(buf);
		error_handler(3, game);
	}
}

// Checks for empty file or empty line in file
void	empty_line_checker(t_game *game, char *buf)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			free(buf);
			error_handler(9, game);
		}
		i++;
	}
	i = -1;
	while (buf[++i])
		if (buf[i] != '\n')
			flag = 0;
	if (flag)
	{
		free(buf);
		error_handler(9, game);
	}
}

// Function to initialize map
// -> Read .ber file
// -> malloc map_arr
// -> assign map_arr
// -> checks if map is valid
int	map_init(char **argv, t_game *game)
{
	char	*buf;
	int		fd;
	int		bytes_read;

	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		error_handler(1, game);
	init_map_struct(game);
	fd = open(argv[1], O_RDONLY);
	buf = ft_calloc(BUF_SIZE + 1, sizeof(char));
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUF_SIZE);
	if (bytes_read == -1 || bytes_read == 0)
		return (free(buf), -1);
	empty_line_checker(game, buf);
	char_checker(game, buf);
	game->map_arr = ft_split(buf, '\n');
	set_window_size(game);
	game->map_buf = buf;
	map_validation(game);
	free(game->map_buf);
	return (0);
}

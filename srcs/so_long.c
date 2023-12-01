/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:02:59 by agan              #+#    #+#             */
/*   Updated: 2023/11/13 17:30:43 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	int i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int map_render()

// Game init function to initialize mlx and game window
int game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1000, 800, "so_long");
	game->map.ptr = mlx_new_image(game->mlx, 1000, 800);
	game->map.addr = mlx_get_data_addr(game->map.ptr, &(game->map.bpp), &(game->map.line_length), &(game->map.endian));
	mlx_put_image_to_window(game->mlx, game->window, game->map.ptr, 0, 0);
	mlx_hook(game->window, ON_DESTROY, 0, &exit_handler, &game);
	mlx_loop(game->mlx);
	return (0);
}

int map_init(char **argv, t_game *game)
{
	char	*buf;
	int fd;
	int bytes_read;

	fd = open(argv[1], O_RDONLY);
	buf = ft_calloc(BUF_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buf, BUF_SIZE);
	if (bytes_read == -1)
		return(free(buf), -1);
	// Alloc map
	game->map_arr = ft_split(buf, '\n');
	free(buf);
	// Error handling for map
	return (0);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		// Read .ber file
		if (map_init(argv, &game) == -1)
			error_handler(0);
		game_init(&game);
		// Check map
	}
}

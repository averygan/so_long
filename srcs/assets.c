/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:27:07 by agan              #+#    #+#             */
/*   Updated: 2023/12/04 13:27:08 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Function to convert xpm to image
t_img load_image(void *mlx, char *path)
{
	t_img img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

// Function to initialize all game assets
void init_assets(t_game *game)
{
	game->wall = load_image(game->mlx, WALL_PATH);
	game->floor = load_image(game->mlx, FLOOR_PATH);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:51:19 by agan              #+#    #+#             */
/*   Updated: 2023/12/11 13:40:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

// Function to handle errors and redirect to exit
int	error_handler(int err, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	if (err == 1)
		ft_putstr_fd("Please input a .ber file\n", 2);
	if (err == 2)
		ft_putstr_fd("Please input two arguments\n", 2);
	if (err == 3)
		ft_putstr_fd("Invalid ber file\n", 2);
	if (err == 1 || err == 2 || err == 3)
		exit (0);
	if (err == 4)
		ft_putstr_fd("Map does not meet requirements.\n", 2);
	else if (err == 5)
		ft_putstr_fd("Map needs to be surrounded by walls.\n", 2);
	else if (err == 6)
		ft_putstr_fd("Map does not have valid symbols.\n", 2);
	else if (err == 7)
		ft_putstr_fd("Map does not have a valid path.\n", 2);
	exit_handler(0, game);
	exit(0);
}

// Function to close game if esc or x window pressed
int	close_game(t_game *game)
{
	exit_handler(1, game);
	return (0);
}

// Free all images
void	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map.hero[0].ptr);
	mlx_destroy_image(game->mlx, game->map.hero[1].ptr);
	mlx_destroy_image(game->mlx, game->map.hero[2].ptr);
	mlx_destroy_image(game->mlx, game->map.hero[3].ptr);
	mlx_destroy_image(game->mlx, game->map.hero_2[0].ptr);
	mlx_destroy_image(game->mlx, game->map.hero_2[1].ptr);
	mlx_destroy_image(game->mlx, game->map.hero_2[2].ptr);
	mlx_destroy_image(game->mlx, game->map.hero_2[3].ptr);
	mlx_destroy_image(game->mlx, game->map.enemy[0].ptr);
	mlx_destroy_image(game->mlx, game->map.wall.ptr);
	mlx_destroy_image(game->mlx, game->map.floor.ptr);
	mlx_destroy_image(game->mlx, game->map.collectible[0].ptr);
	mlx_destroy_image(game->mlx, game->map.collectible[1].ptr);
	mlx_destroy_image(game->mlx, game->map.collectible[2].ptr);
	mlx_destroy_image(game->mlx, game->map.exit.ptr);
}

// Exit: Teardown images and window
void	exit_handler(int close, t_game *game)
{
	if (game->map_arr)
		free_map(game->map_arr);
	if (close == 0)
		free(game->map_buf);
	if (close == 1)
		ft_printf("Game Exited\n");
	if (close == 2)
		ft_printf("You Won!\n");
	if (close == 3)
		ft_printf("You Lost! So long...\n");
	if (close != 0)
	{
		if (game->map.valid_path)
		{
			free_sprites(game);
			mlx_destroy_window(game->mlx, game->window);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	exit (0);
}

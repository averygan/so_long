/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:02:59 by agan              #+#    #+#             */
/*   Updated: 2023/12/11 13:40:55 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

// Main takes in argument and runs error checking for map
// If input is valid, initialize game
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_handler(2, &game);
	if (map_init(argv, &game) == -1)
		error_handler(3, &game);
	game_init(&game);
}

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

// Main takes in argument and runs error checking for map
// If input is valid, initialize game
int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		exit_handler(1);
	if (map_init(argv, &game) == -1)
		error_handler(0);
	game_init(&game);
}

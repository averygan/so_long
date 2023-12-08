/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:51:19 by agan              #+#    #+#             */
/*   Updated: 2023/12/01 17:51:21 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Function to handle errors and exit
int error_handler(int err)
{
	ft_putstr_fd("Error\n", 2);
	if (err == 0)
		ft_putstr_fd("Invalid map.\n", 2);
	else if (err == 1)
		ft_putstr_fd("Argument is not a .ber file.\n", 2);
	else if (err == 2)
		ft_putstr_fd("Map does not meet requirements.\n", 2);
	else if (err == 3)
		ft_putstr_fd("Map needs to be surrounded by walls.\n", 2);
	else if (err == 4)
		ft_putstr_fd("Map does not have a valid path.\n", 2);
	exit(0);
}

int x_close(void)
{
	exit_handler(0);
	return (0);
}

// Exit: TODO teardown images and window
void exit_handler(int err)
{
	if (err != 0 && err != 2)
		ft_putstr_fd("Error\n", 2);
	else if (err == 1)
		ft_putstr_fd("Input two arguments: ./so_long *.ber\n", 2);
	else if (err == 2)
		ft_putstr_fd("Won!", 0);
	exit(0);
}

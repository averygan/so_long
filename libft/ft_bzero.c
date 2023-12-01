/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:17:14 by agan              #+#    #+#             */
/*   Updated: 2023/09/06 12:23:00 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)s;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}
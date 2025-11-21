/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:59:01 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/19 12:07:05 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	move_up(t_game *game)
{
	move_player(game, 0, -1);
}

void	move_down(t_game *game)
{
	move_player(game, 0, 1);
}

void	move_left(t_game *game)
{
	move_player(game, -1, 0);
}

void	move_right(t_game *game)
{
	move_player(game, 1, 0);
}


int	find_my_man(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
			{
				return 0;
			}
			x++;
		}
		y++;
	}
	return 1;
}

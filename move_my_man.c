/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_my_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:16:58 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/15 14:26:06 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

void	find_my_man(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	count_c(t_game *game)
{
	int	y;
	int	x;
	int	total;

	y = 0;
	total = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				total++;
			}
			x++;
		}
		y++;
	}
	return (total);
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_x
		* 64, game->player_y * 64);
}

void	update_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	img_in_map(game);
	draw_player(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] != '1')
	{
		if_c(game, new_x, new_y);
		if (game->map[new_y][new_x] == 'E')
		{
			if (game->coins_collected == game->total_coins)
			{
				printf("%s", "you win");
				exit(0);
			}
			else
				return ;
		}
		game->player_x = new_x;
		game->player_y = new_y;
		game->moves++;
		update_game(game);
		printf("%d", game->moves);
	}
}

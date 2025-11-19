/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:58:58 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/19 17:06:48 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_S)
		move_down(game);
	return (0);
}

int	man_my_main(char **map, int height, int width, t_game *game)
{
	game->map = map;
	game->width = width;
	game->height = height;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width * 64, height * 64, "so_long");
	mlx_hook(game -> win, 17, 0, close_window, game);
	load_img(game);
	if (!game->wall || !game->floor || !game->exit || !game->player
		|| !game->collectible)
	{
		ft_printf("Error: failed to load one or more images\n");
		return (1);
	}
	game->moves = 0;
	game->coins_collected = 0;
	game->total_coins = count_c(game);
	find_my_man(game);
	game->map[game->player_y][game->player_x] = '0';
	update_game(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	free_map(map);
	return (0);
}

int	map_status(char **map, int height, int *width)
{
	*width = len_of_map(map[0]);
	if (!rec_map(map, height) || !check_wall_tandb(map, *width, height)
		|| !check_wall_side(map, *width, height) || !check_element(map, height,
			*width, 0))
	{
		free_map(map);
		ft_printf("%s", "Error: invalid map\n");
		return (1);
	}
	return (0);
}
int map_are_ok(char **map)
{
	if (!map)
	{
		ft_printf("%s", "Error: cannot read map\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		height;
	int		width;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error: invaled argv");
		return (1);
	}
	map = read_map(argv[1]);

	height = map_height(argv[1]);
	if (height <= 0)
	{
		free_map(map);
		ft_printf("%s", "Error: invalid map height\n");
		return (1);
	}
	if (map_status(map, height, &width))
		return (1);
		if (man_my_main(map, height, width, &game))
		return (1);	
	return (0);
}

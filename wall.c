/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:58:50 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/19 11:40:06 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

int	check_wall_tandb(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_side(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	pp(char **map, int *player, int i, int j)
{
	if (map[i][j] == 'P')
		(*player)++;
	return (*player);
}

int	check_element(char **map, int height, int width, int collectible)
{
	int	player;
	int	exit;
	int	j;
	int	i;

	i = 0;
	player = 0;
	exit = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			pp(map, &player, i, j);
			if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collectible++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (!(player != 1 || exit != 1 || collectible < 1));
}
char **copy_map(t_game *game)
{
	int i;
	i = 0;
	char **cpoy = malloc(sizeof(char *) * (game -> height + 1));
	while(i < game -> height)
		{
			copy[i] = ft_strdup(game -> map[i]);
			i++;
		}
	copy[i] = NULL;
	return copy;
}

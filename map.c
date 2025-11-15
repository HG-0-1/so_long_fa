/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:59:04 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/15 18:25:20 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

int	map_height(void)
{
	int		fd;
	char	*line;
	int		map_len;

	map_len = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while ((line) != NULL)
	{
		map_len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_len);
}

int	len_of_map(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

int	rec_map(char **map, int height)
{
	int	width;
	int	i;
	int	len;

	i = 0;
	width = -1;
	while (i < height)
	{
		len = len_of_map(map[i]);
		if (width == -1)
			width = len;
		else if (len != width)
			return (0);
		i++;
	}
	return (1);
}

char	**read_map(void)
{
	int		i;
	char	**map;
	char	*line;
	int		fd;

	i = 0;
	map = malloc(sizeof(char *) * (map_height() + 1));
	if (!map)
		return (NULL);
	
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	line = get_next_line(fd);
	while ((line) != NULL)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	if_c(t_game *game, int newx, int newy)
{
	if (game->map[newy][newx] == 'C')
	{
		game->map[newy][newx] = '0';
		game->coins_collected++;
	}
}

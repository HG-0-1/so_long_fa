/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:59:01 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/10 18:01:01 by helfayez         ###   ########.fr       */
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
int close_windo(t_game *game)
{
	exit(0);
	return(0);
}

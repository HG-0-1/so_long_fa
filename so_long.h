/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:58:54 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/15 16:07:44 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player;
	int		chplayer;
	int		player_x;
	int		player_y;
	void	*collectible;
	void	*exit;
	void	*floor;
	char	**map;
	int		width;
	int		height;
	int		img_w;
	int		img_h;
	int		moves;
	int		coins_collected;
	int		total_coins;
}			t_game;

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

//move
void		move_up(t_game *game);
void		move_left(t_game *game);
void		move_down(t_game *game);
void		move_right(t_game *game);
//wall
int			check_wall_tandb(char **map, int width, int height);
int			check_wall_side(char **map, int width, int height);
int			pp(char **map, int *player, int i, int j);
int			check_element(char **map, int height, int width, int collectible);
//map
int			map_height(void);
int			len_of_map(char *line);
int			rec_map(char **map, int height);
char		**read_map(void);

int			key_hook(int keycode, t_game *game);

void		load_img(t_game *game);
void		img_in_map(t_game *game);
void		free_map(char **map);
void		move_player(t_game *game, int dx, int dy);
void		update_game(t_game *game);
void		draw_player(t_game *game);
void		find_my_man(t_game *game);
int			count_c(t_game *game);
void		if_c(t_game *game, int newx, int newy);

#endif
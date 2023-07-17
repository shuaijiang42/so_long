/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:18:10 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/17 11:03:11 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

enum e_keys
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
	ESC = 53
};

typedef struct s_game
{
	char	**map;
	char	**f_map;
	char	**f_col_map;
	int		width;
	int		length;
	int		count_p;
	int		count_c;
	int		count_e;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		steps;
}	t_game;

void	error_message_exit(char *message, t_game *game);
void	perror_message_exit(char *message);
t_game	*read_map(int fd, t_game *game);
void	check_file_type(char *path);
t_game	*initiate_struct_game(void);
void	flood_fill(char **map, int x, int y, int *flag);
void	flood_fill_collectable(char **map, int x, int y, int *count);
void	check_map(t_game *game, char *path);
void	get_map_length(int fd, t_game *game);
void	paint_sprite(t_game *game, int x, int y, char *sprite);
void	paint_map(t_game *game);
int		events(int keycode, t_game *game);
void	free_game(t_game *game);
void	free_map(char **map);
#endif
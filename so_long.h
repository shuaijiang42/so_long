/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:18:10 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/11 21:10:01 by shujiang         ###   ########.fr       */
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

/* Enums */
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

enum e_errors{
    WRONG_EXTENSION,
    NOT_RECTANGULAR,
    OPEN_WALL,
    NOT_ENOUGH_ELEMENT,
    INVALID_PATH,
    INVALID_PATH_COLLECTABLE
};


typedef struct s_game
{
    char **map;
    char **f_map;
    char **f_col_map;
    int  width;
    int	 length;
    int	 count_p;
    int  count_c;
    int  count_e;
    int  p_x;
    int  p_y;
} t_game;

void    error_message_exit(char *message, enum e_errors errnum);
void    check_wall(t_game *game);
void    perror_message_exit(char *message);
void    error_message_exit(char *message, enum e_errors errnum);
t_game	*read_map(int fd, t_game *game);
void	check_file_type(char *path);
t_game	*initiate_struct_game(void);
void    check_char(t_game *game);
void	get_position(t_game *game);
void	flood_fill(char **map, int x, int y, int *flag);
void print_map(char **map);
//void	flood_collectable(t_game *game, int *flag);
void	flood_fill_collectable(char **map, int x, int y, int *count);
void	check_map(t_game *game);

#endif
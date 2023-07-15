/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:52:45 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/15 19:51:44 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game, char *path)
{
	int	count;
	int	fd;

	count = 0;
	check_file_type(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_message_exit("Error\nThe file can not be opened");
	get_map_length(fd, game);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_message_exit("Error\nThe file can not be opened");
	game = read_map(fd, game);
	check_wall(game);
	check_char(game);
	check_nbr_element(game);
	get_position(game);
	flood_fill(game->f_map, game->p_x, game->p_y, &count);
	if (count == 0)
		error_message_exit("Invalid path", game);
	count = game->count_c;
	flood_fill_collectable(game->f_col_map, game->p_x, game->p_y, &count);
	if (count != 0)
		error_message_exit("Can't collect all the collectables", game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:52:45 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/13 19:22:39 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int   check_front_end(char *line)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			i++;
		else
			break ;
	}
	if (i < ft_strlen(line))
		return (0);
	return (1);
	/* {
		error_message_exit("The wall is not closed.", 2);
	}    */
}

static void    check_wall(t_game *game)
{
	int i;

	i = 0;
	while(game && game->map && i < game->length)
	{
		if (i == 0 || i == game->length - 1)
		{
			if ((check_front_end((game->map)[i]) == 0))
			{
				free_game(game);
				error_message_exit("The wall is not closed.", 2);
			}
			i++;
		}
		else if ((game->map)[i][0] == '1'  && 
				(game->map)[i][game->width - 1] == '1')
			i++;                    
		else 
			break ;
	}
	if (i != game->length)
	{
		free_game(game);
		error_message_exit("The wall is not closed.", 2); 
	}
}

static void    check_char(t_game *game)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	while (game->map[i] && i < game->length - 1)
	{
		while(j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->count_p++;
			if (game->map[i][j] == 'C')
				game->count_c++;
			if (game->map[i][j] == 'E')
				game->count_e++;
			j++;
		}
		i++;
		j = 0;
	}
	if (game->count_p != 1 || game->count_c < 1 || game->count_e != 1)
	{
		free_game(game);
		error_message_exit("Invalid number of element", 3);
	}	
}

static void	get_position(t_game *game)
{
	int y;
	int x;
	
	y = 0;
	while (game->map && game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
					game->p_x = x;
					game->p_y = y;
			}
			x++;
		}	
		y++;
	}
}

void	check_map(t_game *game, char *path)
{
	int count;
	int fd;

	count = 0;
	check_file_type(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_message_exit("The file can not be opened.");
	get_map_length(fd, game);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_message_exit("The file can not be opened.");
	game = read_map(fd, game);
	check_wall(game);
	check_char(game);
	get_position(game);
	flood_fill(game->f_map, game->p_x, game->p_y, &count);
	if (count == 0)
	{
		free_game(game);
		error_message_exit("Invalid path", 4);
	}
	count = game->count_c;
	flood_fill_collectable(game->f_col_map, game->p_x, game->p_y, &count);
	if (count != 0)
	{
		free_game(game);
		error_message_exit("Invalid path for collecting all the collectables", 5);
	}
}

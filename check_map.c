/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:52:45 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/12 13:32:07 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    check_front_end(char *line)
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
		error_message_exit("The wall is not closed.", 2);   
	
}

void    check_wall(t_game *game)
{
	int i;

	i = 0;
	while(game && game->map && i < game->length)
	{
		if (i == 0 || i == game->length - 1)
		{
			check_front_end((game->map)[i]);
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
		error_message_exit("The wall is not closed.", 2); 
	}
}

void    check_char(t_game *game)
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
		error_message_exit("Invalid number of element", 3);
}

void	get_position(t_game *game)
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

void	flood_fill(char **map, int x, int y, int *flag)
{
	if (map[y][x] == 'E')
	{
		*flag = 1;
		return ;
	}
	map[y][x] = '1';
	if (map[y + 1][x] != '1')
		flood_fill(map, x, y + 1, flag);	
	if (map[y][x + 1] != '1')
		flood_fill(map, x + 1, y, flag);	
	if (map[y - 1][x] != '1')
		flood_fill(map, x, y - 1, flag);		
	if (map[y][x - 1] != '1')
		flood_fill(map, x - 1, y, flag);
}

void	flood_fill_collectable(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == 'C')
		*count -= 1;
	map[y][x] = '1';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E')
		flood_fill_collectable(map, x, y + 1, count);	
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E')
		flood_fill_collectable(map, x + 1, y, count);	
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E')
		flood_fill_collectable(map, x, y - 1, count);		
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E')
		flood_fill_collectable(map, x - 1, y, count);
}

void	check_map(t_game *game)
{
	int flag;
	int count;
	 
	flag = 0;
	count = 0;
	print_map(game->map);
	check_wall(game);
	check_char(game);
	get_position(game);
	flood_fill(game->f_map, game->p_x, game->p_y, &flag);
	if (flag == 0)
		error_message_exit("Invalid path", 4);
	count = game->count_c;
	flood_fill_collectable(game->f_col_map, game->p_x, game->p_y, &count);
	if (count != 0)
		error_message_exit("Invalid path for collecting all the collectables", 5);

}


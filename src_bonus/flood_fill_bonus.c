/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:24:27 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/17 11:06:07 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **map, int x, int y, int *flag)
{
	if (map[y][x] == 'E')
	{
		*flag = 1;
		return ;
	}
	map[y][x] = '1';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'D')
		flood_fill(map, x, y + 1, flag);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'D')
		flood_fill(map, x + 1, y, flag);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'D')
		flood_fill(map, x, y - 1, flag);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'D')
		flood_fill(map, x - 1, y, flag);
}

void	flood_fill_collectable(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == 'C')
		*count -= 1;
	map[y][x] = '1';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E'
		&& map[y + 1][x] != 'D')
		flood_fill_collectable(map, x, y + 1, count);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E'
		&& map[y][x + 1] != 'D')
		flood_fill_collectable(map, x + 1, y, count);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E'
		&& map[y - 1][x] != 'D')
		flood_fill_collectable(map, x, y - 1, count);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E'
		&& map[y][x - 1] != 'D')
		flood_fill_collectable(map, x - 1, y, count);
}

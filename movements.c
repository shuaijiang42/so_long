/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:05:58 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/13 18:54:56 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int m_x, int m_y)
{
	if (game->map[game->p_y + m_y][game->p_x + m_x] != '1')
	{
		if (game->map[game->p_y][game->p_x] != 'E') 
			paint_sprite(game, game->p_x, game->p_y, "floor.xpm");
		if (game->map[game->p_y + m_y][game->p_x + m_x] == 'E' 
			&& game->count_c == 0)
		{
			paint_sprite(game, game->p_x + m_x, game->p_y + m_y, "baoziman.xpm");
			free_game(game);
			exit(0);
		}
		if (game->map[game->p_y + m_y][game->p_x + m_x] == 'C')
		{
			paint_sprite(game, game->p_y + m_y, game->p_x + m_x, "floor.xpm");
			game->count_c--;
		}
		game->p_y += m_y;
		game->p_x += m_x;
		if (game->map[game->p_y][game->p_x] != 'E')
			paint_sprite(game, game->p_x, game->p_y, "baoziman.xpm");
	}
}

int    events(int keycode, t_game *game)
{
	
	if (keycode == ESC)
	{
		free_game(game);
		exit(0);
	}
	if (keycode == W || keycode == UP)
		move_player(game, 0, -1);
	if (keycode == S || keycode == DOWN)
		move_player(game, 0, 1);
	if (keycode == A || keycode == LEFT)
		move_player(game, -1, 0);
	if (keycode == D || keycode == RIGHT)
		move_player(game, 1, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:05:58 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/14 19:04:45 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void put_str_to_screen(t_game *game)
{
	const char	*stps = ft_itoa(game->steps);
	const char 	*msg = ft_strjoin("steps: ", (char *)stps);
	
	free((char *)stps);
	paint_sprite(game, 0, 0, "wall.xpm");
	paint_sprite(game, 1, 0, "wall.xpm");
	mlx_string_put(game->mlx, game->mlx_win, 20, 10, GREEN, (char *)msg);
	ft_printf("Steps: %d\n", game->steps);
	free((char *)msg);
}
static void	move_player(t_game *game, int m_x, int m_y)
{
	if (game->map[game->p_y + m_y][game->p_x + m_x] != '1')
	{
		if (game->map[game->p_y][game->p_x] != 'E')
				paint_sprite(game, game->p_x, game->p_y, "floor.xpm");
		if (game->map[game->p_y + m_y][game->p_x + m_x] == 'E'
				&& game->count_c <= 0)
		{
			paint_sprite(game, game->p_x + m_x,
				game->p_y + m_y, "baoziman.xpm");
			free_game(game);
			exit(0);
		}
		if (game->map[game->p_y + m_y][game->p_x + m_x] == 'C')
		{
			paint_sprite(game, game->p_x + m_x, game->p_y + m_y, "floor.xpm");
			game->count_c--;
		}
		game->steps++;
		game->p_y += m_y;
		game->p_x += m_x;
		put_str_to_screen(game);
		if (game->map[game->p_y][game->p_x] != 'E')
			paint_sprite(game, game->p_x, game->p_y, "baoziman.xpm");
	}
}

int	events(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		free_game(game);
		exit(0);
	}
	if (keycode == W || keycode == UP)
	{
		game->dir = BACK;
		move_player(game, 0, -1);
	}	
	if (keycode == S || keycode == DOWN)
	{
		game->dir = FRONT;
		move_player(game, 0, 1);
	}
	if (keycode == A || keycode == LEFT)
	{
		game->dir = LEFT_SIDE;
		move_player(game, -1, 0);
	}	
	if (keycode == D || keycode == RIGHT)
	{
		game->dir = RIGHT_SIDE;
		move_player(game, 1, 0);
	}
	return (0);
}

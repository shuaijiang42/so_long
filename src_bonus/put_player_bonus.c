/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:20:59 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/17 11:06:19 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_front(t_game *game)
{
	if (game->counter == 1)
		paint_sprite(game, game->p_x, game->p_y, "front1.xpm");
	if (game->counter == 2)
		paint_sprite(game, game->p_x, game->p_y, "front2.xpm");
	if (game->counter == 3)
		paint_sprite(game, game->p_x, game->p_y, "front3.xpm");
	if (game->counter == 4)
		paint_sprite(game, game->p_x, game->p_y, "front4.xpm");
	if (game->counter == 5)
		paint_sprite(game, game->p_x, game->p_y, "front5.xpm");
	if (game->counter == 6)
		paint_sprite(game, game->p_x, game->p_y, "front6.xpm");
}

void	put_player_back(t_game *game)
{
	if (game->counter == 1)
		paint_sprite(game, game->p_x, game->p_y, "back1.xpm");
	if (game->counter == 2)
		paint_sprite(game, game->p_x, game->p_y, "back2.xpm");
	if (game->counter == 3)
		paint_sprite(game, game->p_x, game->p_y, "back3.xpm");
	if (game->counter == 4)
		paint_sprite(game, game->p_x, game->p_y, "back4.xpm");
	if (game->counter == 5)
		paint_sprite(game, game->p_x, game->p_y, "back5.xpm");
	if (game->counter == 6)
		paint_sprite(game, game->p_x, game->p_y, "back3.xpm");
}

void	put_player_left(t_game *game)
{
	if (game->counter == 1)
		paint_sprite(game, game->p_x, game->p_y, "leftside1.xpm");
	if (game->counter == 2)
		paint_sprite(game, game->p_x, game->p_y, "leftside2.xpm");
	if (game->counter == 3)
		paint_sprite(game, game->p_x, game->p_y, "leftside3.xpm");
	if (game->counter == 4)
		paint_sprite(game, game->p_x, game->p_y, "leftside4.xpm");
	if (game->counter == 5)
		paint_sprite(game, game->p_x, game->p_y, "leftside5.xpm");
	if (game->counter == 6)
		paint_sprite(game, game->p_x, game->p_y, "leftside3.xpm");
}

void	put_player_right(t_game *game)
{
	if (game->counter == 1)
		paint_sprite(game, game->p_x, game->p_y, "rightside1.xpm");
	if (game->counter == 2)
		paint_sprite(game, game->p_x, game->p_y, "rightside2.xpm");
	if (game->counter == 3)
		paint_sprite(game, game->p_x, game->p_y, "rightside3.xpm");
	if (game->counter == 4)
		paint_sprite(game, game->p_x, game->p_y, "rightside4.xpm");
	if (game->counter == 5)
		paint_sprite(game, game->p_x, game->p_y, "rightside5.xpm");
	if (game->counter == 6)
		paint_sprite(game, game->p_x, game->p_y, "rightside3.xpm");
}

void	put_player(t_game *game)
{
	if (game->dir == FRONT)
		put_player_front(game);
	if (game->dir == BACK)
		put_player_back(game);
	if (game->dir == LEFT_SIDE)
		put_player_left(game);
	if (game->dir == RIGHT_SIDE)
		put_player_right(game);
}

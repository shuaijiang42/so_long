/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_map_utiles.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:51:16 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/15 19:55:46 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_front_end(char *line)
{
	size_t	i;

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
}

void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game && game->map && i < game->length)
	{
		if (i == 0 || i == game->length - 1)
		{
			if ((check_front_end((game->map)[i]) == 0))
				error_message_exit("The wall is not closed.", game);
			i++;
		}
		else if ((game->map)[i][0] == '1' &&
				(game->map)[i][game->width - 1] == '1')
			i++;
		else
			break ;
	}
	if (i != game->length)
		error_message_exit("The wall is not closed.", game);
}

void	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i] && i < game->length - 1)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->count_p++;
			else if (game->map[i][j] == 'C')
				game->count_c++;
			else if (game->map[i][j] == 'E')
				game->count_e++;
			else if (game->map[i][j] == 'D')
				game->demon++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				error_message_exit("The map has invalid element", game);
			j++;
		}
		i++;
	}
}

void	check_nbr_element(t_game *game)
{
	if (game->count_p != 1 || game->count_c < 1
		|| game->count_e != 1 || game->demon < 1)
		error_message_exit("Invalid number of element", game);
}

void	get_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map && game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
					game->p_x = x;
					game->p_y = y;
			}
			if (game->map[y][x] == 'D')
			{
					game->d_x = x;
					game->d_y = y;
			}
			x++;
		}	
		y++;
	}
}

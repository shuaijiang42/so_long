/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:31:04 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/17 11:06:02 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message_exit(char *message, t_game *game)
{
	free_game(game);
	ft_printf("Error\n%s\n", message);
	exit(1);
}

void	perror_message_exit(char *message)
{
	perror(message);
	exit(1);
}

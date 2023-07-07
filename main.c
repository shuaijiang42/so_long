/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:07:38 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/07 19:05:33 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int fd;
	t_game *game;

	if (argc == 2)
	{
		check_file_type(argv[1]);
		game = malloc(sizeof(t_game));
		initiate_struct_game(game);
		fd = open(argv[1], O_RDONLY);
		game = read_map(fd, game);
		check_wall(game);
		check_char(game);
		free(game);
	}
	return (0);
}
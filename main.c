/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:07:38 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/11 21:47:53 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int fd;
	t_game *game;
	
	game = initiate_struct_game();
	if (argc == 2)
	{
		check_file_type(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error: %s", strerror(fd));
			return 1;
		}
		game = read_map(fd, game);
		check_map(game);
		free(game);
	}

	return (0);
}

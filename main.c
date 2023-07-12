/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:07:38 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/12 15:09:01 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	(void)argc;
	int fd;
	t_game *game;
	
	game = initiate_struct_game();
	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		check_file_type(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error: %s", strerror(fd));
			return 1;
		}
		get_map_length(fd, game);
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

int	main2(void)
{
	t_data	img;
	void	*mlx;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	return 0;
}

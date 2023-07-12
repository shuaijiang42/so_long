/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:07:38 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/12 23:12:17 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_map(t_game *game)
{
	int i; 
	int j;

	i = 0;
	while(i < (game->length))
	{
		j = 0;
		while(j < game->width)
		{
 			if(game->map[i][j] == '0')
				paint_sprite(game, j, i, "floor.xpm");
			if(game->map[i][j] == '1')
				paint_sprite(game, j, i, "wall.xpm");
			if(game->map[i][j] == 'E')
				paint_sprite(game, j, i, "door.xpm");
			if(game->map[i][j] == 'C')
				paint_sprite(game, j, i, "baozi.xpm");
			if(game->map[i][j] == 'P')
				paint_sprite(game, j, i, "baoziman.xpm");	
			j++;
		}
		i++;
	}
}

void	paint_sprite(t_game *game, int x, int y, char *sprite)
{
	void	*img;
	int		img_width;
	int		img_height;
	char 	*path;
	
	path = ft_strjoin("./textures/", sprite);
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * 64, y * 64);
}

int	main(int argc, char **argv)
{
	//int fd;
	t_game *game;
	
	game = initiate_struct_game();
	if (argc == 2)
	{
		/* check_file_type(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror_message_exit("The file can not be opened.");
		get_map_length(fd, game);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror_message_exit("The file can not be opened.");
		game = read_map(fd, game); */
		check_map(game, argv[1]);
		game->mlx = mlx_init();
		game->mlx_win = mlx_new_window(game->mlx, game->width * 64, game->length * 64, "Town of Baozi");
		paint_map(game);
		mlx_loop(game->mlx);
		free(game);
	}

	return (0);
}

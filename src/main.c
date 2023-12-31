/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:07:38 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/17 10:21:56 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	ft_leaks(void)
{
	system("leaks -q so_long");
}
atexit(ft_leaks); */

void	paint_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < (game->length))
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				paint_sprite(game, x, y, "wall.xpm");
			else if (game->map[y][x] == 'E')
				paint_sprite(game, x, y, "door.xpm");
			else
			{
				paint_sprite(game, x, y, "floor.xpm");
				if (game->map[y][x] == 'C')
					paint_sprite(game, x, y, "baozi.xpm");
				else if (game->map[y][x] == 'P')
					paint_sprite(game, x, y, "baoziman.xpm");
			}
			x++;
		}
		y++;
	}
}

void	paint_sprite(t_game *game, int x, int y, char *sprite)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	path = ft_strjoin("./textures/", sprite);
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	if (!img)
		error_message_exit("No xpm image", game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * 64, y * 64);
	free(path);
}

int	ft_close(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc == 2)
	{
		game = initiate_struct_game();
		check_map(game, argv[1]);
		game->mlx = mlx_init();
		game->mlx_win = mlx_new_window(game->mlx, game->width * 64,
				game->length * 64, "Town of Baozi");
		paint_map(game);
		mlx_key_hook(game->mlx_win, events, game);
		mlx_hook(game->mlx_win, 17, 0L, ft_close, game);
		mlx_loop(game->mlx);
		free_map(game->map);
		free(game);
	}
	ft_printf("Error\nWrong number of arguments.\n");
	return (0);
}

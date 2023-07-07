/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:13:36 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/07 18:51:14 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiate_struct_game(t_game *game)
{
	game->map = NULL;
	game->flood_map = NULL;
	game->length = 0;
	game->width = 0;
	game->count_p = 0;
    game->count_c = 0; 
    game->count_e = 0; 
}

void	check_file_type(char *path)
{
	char *extension;
	int i;

	i = 0;
	extension = ft_strrchr(path, '.');
	if (!extension || ft_strlen(extension) != 4 || ft_strncmp(extension, ".ber", 4) != 0)
		error_message_exit("Invalid file type", 0);
}

char	*get_lines(int fd, t_game *game)
{
	char	*file;
	char	*line;
	char	*aux;
	int 	i; 

	i = 0;
	line = get_next_line(fd);
	if(line)
		game->width = ft_strlen(line)-1;
	aux = NULL;
	file = (char *)calloc(1, sizeof(char));
	if (!file)
		perror_message_exit("calloc");
	while (line)
	{	
		i++;
		aux = file;
		file = ft_strjoin(aux, line);
		(free(aux), free(line));
		line = get_next_line(fd);
	}
	return (file);
}

t_game	*read_map(int fd, t_game *game)
{
	int i;

	i = 0;
	game->map = ft_split(get_lines(fd, game), '\n');
	game->flood_map = ft_split(get_lines(fd, game), '\n');
	while (game->map[i])
	{
		if (game->map && (int)ft_strlen(game->map[i])!= game->width)
			error_message_exit("The map is not rectangular.", 1);
		i++;
	}
	game->length = i;
	return (game);
}

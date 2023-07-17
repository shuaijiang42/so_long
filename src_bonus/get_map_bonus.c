/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:13:36 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/17 12:24:54 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_game	*initiate_struct_game(void)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(1, sizeof(*game));
	if (!game)
		return (NULL);
	return (game);
}

void	check_file_type(char *path)
{
	char	*extension;

	if (ft_strcmp("maps/.ber", path) == 0
		||ft_strcmp("./maps/.ber", path) == 0)
	{
		ft_printf("Error\nInvalid file type.\n");
		exit(1);
	}
	extension = ft_strrchr(path, '.');
	if (!extension || ft_strlen(extension) != 4
		|| ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid file type.");
		exit(1);
	}
}

void	get_map_length(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		game->length += 1;
		free(line);
		line = get_next_line(fd);
	}
}	

char	*get_lines(int fd, t_game *game)
{
	char	*whole_line;
	char	*line;
	char	*aux;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nThe map has no content.\n");
		exit(1);
	}		
	game->width = ft_strlen(line) - 1;
	whole_line = (char *)calloc(1, 1);
	if (!whole_line)
		perror_message_exit("calloc");
	while (line)
	{	
		i++;
		aux = whole_line;
		whole_line = ft_strjoin(aux, line);
		(free(aux), free(line));
		line = get_next_line(fd);
	}
	return (whole_line);
}

t_game	*read_map(int fd, t_game *game)
{
	int		i;
	char	*temp1;
	char	*temp2;
	char	*temp3;

	i = 0;
	temp1 = get_lines(fd, game);
	temp2 = ft_strdup(temp1);
	temp3 = ft_strdup(temp1);
	game->map = ft_split(temp1, '\n');
	game->f_map = ft_split(temp2, '\n');
	game->f_col_map = ft_split(temp3, '\n');
	(free(temp1), free(temp2), free(temp3));
	while (game->map[i])
	{
		if (game->map && (int)ft_strlen(game->map[i]) != game->width)
			error_message_exit("The map is not rectangular.", game);
		i++;
	}
	if (game->length != i)
		error_message_exit("The map is not valid.", game);
	return (game);
}

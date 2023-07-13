/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:13:36 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/13 19:18:58 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *initiate_struct_game(void)
{
	t_game *game = NULL;
	
	game = ft_calloc(1, sizeof(*game));
	if (!game)
		return (NULL);	
	return (game); 
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

void	get_map_length(int fd, t_game *game)
{
	char *line;
	
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
	int 	i; 

	i = 0;
	line = get_next_line(fd);	
	if(line)
		game->width = ft_strlen(line) - 1;
	aux = NULL;
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
	int i;
	char *temp1;
	char *temp2;
	char *temp3;
	
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
		if (game->map && (int)ft_strlen(game->map[i])!= game->width)
		{
			free_game(game);
			error_message_exit("The map is not rectangular.", 1);
		}	
		i++;
	}
	if (game->length != i)
	{
		free_game(game);
		error_message_exit("The map is not valid.", 1);
	}
	return (game);
}

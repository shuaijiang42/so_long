/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:52:45 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/07 19:07:03 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    check_front_end(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if ((int)line[i] == (int)'1')
            i++;
        else
            break ;
    }
    if (i < (int)ft_strlen(line))
        error_message_exit("The wall is not closed.", 2);   
    
}

void    check_wall(t_game *game)
{
    int i;

    i = 0;
    while(game && game->map && i < game->length)
    {
        if (i == 0 || i == game->length)
        {
            check_front_end((game->map)[i]);
            i++;
        }
        else if ((int)(game->map)[i][0] == (int)'1'  && 
                (int)(game->map)[i][game->width - 1] == (int)'1')
            i++;                    
        else
            break ; 
    }
    if (i < game->length)
        error_message_exit("The wall is not closed.", 2); 
}

void    check_char(t_game *game)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    while (game->map[i] && i < game->length - 1)
    {
        while(j < game->width)
        {
            if (game->map[i][j] == 'p')
                game->count_p++;
            if (game->map[i][j] == 'c')
                game->count_c++;
            if (game->map[i][j] == 'e')
                game->count_e++;
            j++;
        }
        i++;
        j = 0;
    }
    if (game->count_p != 1 || game->count_c < 1 || game->count_e != 1)
        error_message_exit("Invalid number of element", 3);      
}

void    flood_fill()

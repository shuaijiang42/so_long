/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:31:04 by shujiang          #+#    #+#             */
/*   Updated: 2023/07/07 17:06:15 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error_message_exit(char *message, enum e_errors errnum)
{
    ft_printf("Error\n%s\n", message);
    strerror(errnum);
    exit(1);
}

void    perror_message_exit(char *message)
{
    perror(message);
    exit(1);
}
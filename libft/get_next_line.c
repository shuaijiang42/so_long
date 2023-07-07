/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shujiang <shujiang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:10:24 by shujiang          #+#    #+#             */
/*   Updated: 2023/05/09 12:16:18 by shujiang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strndup(char *src, size_t n)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!src || n == 0)
		return (NULL);
	result = malloc(n + 1);
	if (!result)
		return (NULL);
	while (i < n)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_stash(char *stash, char *buf)
{
	char	*temp;

	if (stash)
	{
		temp = ft_strjoin(stash, buf);
		free(stash);
		stash = temp;
	}
	else
		stash = ft_strndup(buf, ft_strlen(buf));
	return (stash);
}

static char	*read_and_stash(char *stash, int fd)
{
	ssize_t	read_bytes;
	char	*buf;

	read_bytes = 1;
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (stash == NULL && read_bytes == 0)
			break ;
		if (read_bytes == -1)
		{
			free (buf);
			free (stash);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		stash = ft_stash(stash, buf);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free (buf);
	return (stash);
}

static t_strings	extract_new_line(char	*stash)
{
	t_strings	two_parts;
	char		*ptr_nl;

	if (!stash)
	{
		two_parts.line = NULL;
		two_parts.stash = NULL;
		return (two_parts);
	}
	ptr_nl = ft_strchr(stash, '\n');
	if (!ptr_nl)
	{
		two_parts.line = ft_strndup(stash, ft_strlen(stash));
		two_parts.stash = NULL;
	}
	else
	{
		two_parts.line = ft_strndup(stash, (ptr_nl - stash) + 1);
		two_parts.stash = ft_strndup(ptr_nl + 1,
				ft_strlen(stash) - ft_strlen(two_parts.line));
	}
	return (two_parts);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	t_strings	two_parts;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(stash, fd);
	two_parts = extract_new_line(stash);
	free(stash);
	stash = NULL;
	if (!two_parts.stash)
		return (two_parts.line);
	stash = two_parts.stash;
	return (two_parts.line);
}

/* char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	t_strings	two_parts;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(stash, fd);
	if (!stash)
		return (NULL);
	if (stash)
	{
		two_parts = extract_new_line(stash);
		free(stash);
		stash = NULL;
		if (!two_parts.stash)
			return (two_parts.line);
	}
	stash = two_parts.stash;
	return (two_parts.line);
} */

/* int	main()
{
	int i = open("test", O_RDONLY);
	char *s;
	
	while ((s = get_next_line(i)))
	{
		printf("%s", s);
		free(s);
	} 
	
}  */
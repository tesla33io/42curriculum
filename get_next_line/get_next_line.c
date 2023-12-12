/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:19 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/12 11:56:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*read_from_file(int fd)
{
	int		b_read;
	char	*buffer;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[b_read] = '\0';
	return (buffer);
}

char	*get_next(char *line)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
	{
		while (line[i] != '\n')
			i++;
		if (!line[i])
			return (NULL);
		tmp = (char *) malloc((len - i + 1) * sizeof(char));
		while (line[i])
			tmp[j++] = line[i++];
		tmp[j] = '\0';
		free(line);
		return (tmp);
	}
	return (NULL);
}

/* After using the `ft_strjoin` function, I need to `free` what was in */
/* the `line` before, otherwise I will have problems. */

char	*get_line(int fd, char *line)
{
	char	*buffer;
	char	*joined;

	if (!line)
		line = ft_calloc(1, 1);
	while (1)
	{
		buffer = read_from_file(fd);
		if (!buffer)
			return (NULL);
		joined = ft_strjoin(line, buffer);
		if (!joined)
		{
			free(joined);
			return (NULL);
		}
		free(line);
		line = joined;
		free(buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*next;

	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	buffer = get_line(fd, buffer);
	next = get_next(buffer);
	return (buffer);
}

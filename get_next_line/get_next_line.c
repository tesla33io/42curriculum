/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:19 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/12 16:37:09 by astavrop         ###   ########.fr       */
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

/* After using the `ft_strjoin` function, I need to `free` what was in */
/* the `line` before, otherwise I will have problems. */
char	*read_until_nl(int fd, char *buf)
{
	char	*buffer;
	char	*joined;

	if (!buf)
		buf = ft_calloc(1, 1);
	while (1)
	{
		buffer = read_from_file(fd);
		if (!buffer)
			return (NULL);
		joined = ft_strjoin(buf, buffer);
		if (!joined)
			return (NULL);
		free(buf);
		buf = joined;
		free(buffer);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (buf);
}

char	*get_line(char *buffer)
{
	size_t		i;
	size_t		j;
	char		*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *) malloc((i + 2) * sizeof(char));
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_next(char *buffer)
{
	size_t		i;
	size_t		j;
	size_t		buf_len;
	char		*new_buffer;

	buf_len = ft_strlen(buffer);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n' && i < buf_len)
		i++;
	i++;
	new_buffer = (char *) malloc((buf_len - i + 1) * sizeof(char));
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		j++;
		i++;
	}
	new_buffer[j] = '\0';
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*new_buf;
	char			*line;

	buffer = read_until_nl(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
		return (NULL);
	new_buf = get_next(buffer);
	free(buffer);
	buffer = new_buf;
	if (!buffer)
		return (NULL);
	return (line);
}

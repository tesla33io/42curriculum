/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:19 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/10 21:57:32 by astavrop         ###   ########.fr       */
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

char	*get_line(int fd, char *line)
{
	char	*buffer;

	while (1)
	{
		buffer = read_from_file(fd);
		if (!buffer)
			return (NULL);
		line = ft_strjoin(line, buffer);
		free(buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line;

	if (!line)
		line = ft_calloc(1, 1);
	line = get_line(fd, line);
	return (line);
}

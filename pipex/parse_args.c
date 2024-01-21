/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:14:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/22 18:24:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// Append to string array
void	append_tsa(char ****array2D, char ***newRow, int *rowCount)
{
	char	***temp;
	int		i;

	(*rowCount)++;
	temp = (char ***)malloc((*rowCount) * sizeof(char **));
	if (temp == NULL)
	{
		print_error("Memory allocation error.", "", "", -1);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < (*rowCount) - 1)
	{
		temp[i] = (*array2D)[i];
		i++;
	}
	temp[*rowCount - 1] = *newRow;
	free(*array2D);
	*array2D = temp;
}

char	**get_args(int argc, char **argv, t_pipex **data)
{
	int		i;
	char	**entryv;

	(void)argc;
	i = 2;
	while (argv[i + 1])
	{
		entryv = ft_split(argv[i], ' ');
		if (!entryv)
			return (NULL);
		append_tsa(&((*data)->cmd_args), &entryv, &((*data)->row_c));
		i++;
	}
	return (argv);
}

int	parse_args(int argc, char **argv, t_pipex **data)
{
	get_args(argc, argv, &(*data));
	return (0);
}
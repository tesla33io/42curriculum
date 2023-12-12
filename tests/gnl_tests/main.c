/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:37 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/12 16:34:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*ret;
	int		file;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(file)) != NULL)
		{
			printf("\t>%s", ret);
			free(ret);
		}
		close(file);
	}
	else
	{
		printf("\nUsage: make run file=<filename> or ./test <filename>\n\n");
	}
}

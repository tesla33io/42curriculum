/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:37 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/10 21:53:02 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "srcs/get_next_line.h"

int	main(int argc, char **argv)
{
	char	*ret;

	if (argc == 2)
	{
		int		file = open(argv[1], O_RDONLY);
		for (int i = 0; i < 1; i++)
		{
			ret = get_next_line(file);
			(void)ret;
			printf("[%d] %s\n", i, ret);
			free(ret);
		}
	}
	else
	{
		printf("\nUsage: make run file=<filename> or ./test <filename>\n\n");
	}
}
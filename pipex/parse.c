/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:22:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/12 19:08:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./pipex.h"

int	open_files(int argc, char **argv, t_data *data)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	if (argc == 5)
		data->outfile_fd = open(argv[4], O_WRONLY);
	else
	{
		
	}
}

int	parse_data(int argc, char **argv, t_data *data)
{
	(void)argc;
	(void)argv;
	data = (t_data *) malloc(1 * sizeof(t_data));
	if (!data)
		return (print_error("Memory allocation failed during parsing.", 5));
	return (0);
}

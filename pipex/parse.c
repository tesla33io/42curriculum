/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:22:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/13 15:11:11 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./pipex.h"

int	parse_fd(char **argv, t_data **data)
{
	(*data)->infile_fd = open(argv[1], O_RDONLY);
	if ((*data)->infile_fd < 0)
		return (print_error("Can't open \'INFILE\'", 41));
	(*data)->outfile_fd = open(argv[4], O_WRONLY);
	if ((*data)->outfile_fd < 0)
	{
		(*data)->outfile_fd = open(argv[4], O_WRONLY | O_CREAT, 00777);
		if ((*data)->outfile_fd < 0)
			return (print_error("Can't open \'OUTFILE\'", 42));
	}
	return (0);
}

int	parse_cmd_args(char **argv, t_data **data)
{
	(*data)->first_cmd_argv = ft_strdup(argv[2] + ft_strlen(
				(const char *)(*data)->first_cmdv[0]));
	(*data)->second_cmd_argv = ft_strdup(argv[3] + ft_strlen(
				(const char *)(*data)->second_cmdv[0]));
	return (0);
}

int	parse_data(int argc, char **argv, t_data **data)
{
	(void)argc;
	(void)argv;
	(*data) = (t_data *) malloc(1 * sizeof(t_data));
	if (!(*data))
		return (print_error("Memory allocation failed during parsing.", 3));
	if (parse_fd(argv, &(*data)) != 0)
		return (-1);
	(*data)->first_cmdv = ft_split(argv[2], ' ');
	(*data)->second_cmdv = ft_split(argv[3], ' ');
	parse_cmd_args(argv, &(*data));
	ft_printf("fd: %d %d\ncmd: |%s| |%s|\n", (*data)->infile_fd,
		(*data)->outfile_fd, (*data)->first_cmdv[0], (*data)->second_cmdv[0]);
	ft_printf("argv:\t|%s|\n\t|%s|\n", (*data)->first_cmd_argv,
		(*data)->second_cmd_argv);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:40:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/13 12:28:22 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./pipex.h"

int	print_error(char *message, int code)
{
	ft_printf(B_RED WHITE " <   "S_BOLD S_UNDERLINE "Error!" R B_RED WHITE
		" %s   > " R "\n" R, message);
	return (code);
}

int	check_access(char *file)
{
	if (access(file, R_OK) == 0)
		return (0);
	else
		return (-1);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5 || argc > 5)
	{
		print_error("Wrong input!", 1);
		print_usage();
		return (1);
	}
	else if (argc > 5)
		return (print_error("Too much files!", 2));
	if (check_access(argv[1]) != 0)
		return (print_error("Can't access input file.", 3));
	if (argc == 5 && check_access(argv[4]) != 0)
		return (print_error("Can't access output file.", 4));
	return (0);
}

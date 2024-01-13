/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:21:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/13 12:36:32 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./ft_printf/includes/ft_printf.h"
#include "./pipex.h"

void	print_usage(void)
{
	ft_printf("\nUsage:\t" GREEN "./pipex " BLUE "<INFILE> \"<CMD 1>\" "
		"\"<CMD 2>\" <OUTFILE>" R "\n\n");
	ft_printf("\t" BLUE "<INFILE>"R"\t- Input file for the program.\n");
	ft_printf("\t" BLUE "<OUTFILE>"R"\t- Output file for the program.\n");
	ft_printf("\t" BLUE "<CMD 1>"R"\t\t- First command to be executed.\n");
	ft_printf("\t" BLUE "<CMD 2>"R"\t\t- Second command to be executed.\n\n");
}

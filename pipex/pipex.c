/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/15 19:25:36 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "./pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex		*data;
	int			i;

	i = 0;
	data = init_pipex(env);
	if (check_input(argc, argv) != 0)
		exit (EXIT_FAILURE);
	if (parse_data(argc, argv, &data) != 0)
		exit (EXIT_FAILURE);
	end(&data);
	return (0);
}

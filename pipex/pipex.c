/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/06 20:49:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex		*data;
	int			pip[2];
	int			i;

	i = 1;
	if (check_input(argc, argv) != 0)
		exit (EXIT_FAILURE);
	data = init_pipex(env);
	if (parse_data(argc, argv, &data) != 0)
		end(&data, 1);
	if (parse_args(argc, argv, &data) != 0)
		end(&data, 2);
	if (pipe(pip) == -1)
	{
		print_error("Pipe failure.", "", "", 32);
		end(&data, 32);
	}
	exec_first(&data, env, pip);
	exec_last(&data, env, pip);
	end(&data, data->status);
	return (0);
}

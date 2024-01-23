/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/23 18:14:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./pipex.h"

// void	exec_cmd(t_pipex **data, char **env, int pipefd[2])
// {
	
// }

int	proccess_cmd(char *cmd_path, char **cmd_arg, char **env, int out_fd)
{
	int		pipefd[2];
	pid_t	pid;

	ft_printf(2, "pcmd:: cmd - %s\n", cmd_path);
	if (pipe(pipefd) == -1)
		return (print_error("Pipe failure.", "", "", -1));
	pid = fork();
	if (pid == -1)
		return (print_error("Fork failure.", "", "", -1));
	if (pid == 0)
	{
		dup2(STDOUT_FILENO, pipefd[1]);
		execve(cmd_path, cmd_arg, env);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], out_fd);
		wait(NULL);
		close(pipefd[0]);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		*data;
	int			i;

	i = 1;
	if (check_input(argc, argv) != 0)
		exit (EXIT_FAILURE);
	data = init_pipex(env);
	if (parse_data(argc, argv, &data) != 0)
		end(&data);
	if (parse_args(argc, argv, &data) != 0)
		end(&data);
	exec_first(data->cmd_paths[0], data->cmd_args[0], env, data->in_fd);
	while (i < data->cmd_count)
	{
		proccess_cmd(data->cmd_paths[i], data->cmd_args[i], env,
			data->out_fd);
		if (!data->cmd_paths[0] || !data->cmd_args[0])
		{
			print_error("Something is wrong (", "", "", -1);
			break ;
		}
		i++;
	}
	end(&data);
	return (0);
}

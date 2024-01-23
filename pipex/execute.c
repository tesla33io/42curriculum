/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:07:44 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/23 18:19:01 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./pipex.h"

// return pipe
int	exec_first(char *cmd_path, char **cmd_arg, char **env, int in_fd)
{
	int		pipefd[2];
	pid_t	pid;

	ft_printf(2, "ef:: cmd - %s\n", cmd_path);
	if (pipe(pipefd) == -1)
		return (print_error("Pipe failure.", "", "", -1));
	pid = fork();
	if (pid == -1)
		return (print_error("Fork failure.", "", "", -1));
	if (pid == 0)
	{
		dup2(in_fd, STDIN_FILENO);
		execve(cmd_path, cmd_arg, env);
	}
	else
	{
		close(pipefd[0]);
		dup2(STDOUT_FILENO, pipefd[1]);
		wait(NULL);
		close(pipefd[1]);
	}
	return (0);
}

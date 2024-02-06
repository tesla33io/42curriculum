/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:07:44 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/06 18:31:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./pipex.h"

// Execute first command by inputting the contents of the 'infile' into it.
int	exec_first(t_pipex **data, char **env, int pipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (print_error("(exec_first) Fork failure.", "", "", -1));
	if (!pid)
	{
		close(pipefd[0]);
		dup2((*data)->in_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (execve((*data)->cmd_paths[0], (*data)->cmd_args[0], env) == -1)
		{
			print_error("(exec_first) Command execution failed (",
				(*data)->cmd_paths[0], ").", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &(*data)->status, 0);
	return (0);
}

// Execute last command by outputting the result of the last command
// into 'outfile'.
int	exec_last(t_pipex **data, char **env, int pipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (print_error("(exec_last) Fork failure.", "", "", -1));
	if (!pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		dup2((*data)->out_fd, STDOUT_FILENO);
		if (execve((*data)->cmd_paths[1], (*data)->cmd_args[1], env) == -1)
		{
			print_error("(exec_first) Command execution failed (",
				(*data)->cmd_paths[1], ").", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid, &(*data)->status, 0);
	}
	return (0);
}

void	setup_pipes(t_pip **pip)
{
	dup2((*pip)->in_pipe[0], STDIN_FILENO);
	close((*pip)->in_pipe[0]);
	close((*pip)->in_pipe[1]);
	dup2((*pip)->out_pipe[1], STDOUT_FILENO);
	close((*pip)->out_pipe[0]);
	close((*pip)->out_pipe[1]);
}

void	close_pipes(t_pip **pip)
{
	close((*pip)->in_pipe[0]);
	close((*pip)->in_pipe[1]);
	close((*pip)->out_pipe[0]);
	close((*pip)->out_pipe[1]);
}

int	exec_middle(t_pipex **data, int i, char **env, t_pip **pip)
{
	pid_t	pid;

	ft_printf(2, "exec_middle (%s)\n", (*data)->cmd_paths[i]);
	pid = fork();
	if (pid == -1)
		return (print_error("Fork failure.", "", "", -1));
	if (pid)
	{
		setup_pipes(&(*pip));
		execve((*data)->cmd_paths[i], (*data)->cmd_args[i], env);
	}
	waitpid(pid, &(*data)->status, 0);
	return (0);
}

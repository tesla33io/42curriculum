/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:22:43 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/17 17:28:32 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

int	parse_fd(int argc, char **argv, t_pipex **data)
{
	(*data)->in_fd = open(argv[1], O_RDONLY);
	if ((*data)->in_fd < 0)
		return (print_error("Can't open \'INFILE\'", "", "", -1));
	(*data)->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 00777);
	if ((*data)->out_fd < 0)
	{
		return (print_error("Can't open \'",
				argv[argc - 1], "\' (OUTFILE).", -1));
	}
	return (0);
}

char	*check_cmd(char *cmd, char **paths)
{
	char	*path;
	char	*full_path;
	char	*bin;

	bin = get_bin(cmd);
	if (!bin)
		return (NULL);
	if ((ft_strncmp(bin, "./", 2) == 0) \
		&& access(bin, X_OK) == 0)
		return (ft_strdup(bin));
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(path, bin);
		free(path);
		if (access(full_path, X_OK) == 0)
		{
			free(bin);
			return (full_path);
		}
		free(full_path);
		paths++;
	}
	print_error("Command \'", bin, "\' not found.", -1);
	free(bin);
	return (NULL);
}

int	parse_cmds(int argc, char **argv, t_pipex **data)
{
	int		i;
	char	*cmd;
	char	*cmd_path;
	char	*cmds;
	char	*tmp_cmds;

	cmds = (char *) ft_calloc(1, sizeof(char *));
	if (!cmds)
		return (-1);
	i = 2;
	while (i < argc - 1)
	{
		cmd = check_cmd(argv[i], (*data)->path);
		if (!cmd)
		{
			free(cmds);
			return (-1);
		}
		cmd_path = ft_strjoin(cmd, ":");
		tmp_cmds = ft_strjoin(cmds, cmd_path);
		free(cmd);
		free(cmd_path);
		free(cmds);
		cmds = tmp_cmds;
		i++;
	}
	(*data)->cmd_paths = ft_split(cmds, ':');
	free(cmds);
	return (0);
}

int	parse_data(int argc, char **argv, t_pipex **data)
{
	int		i;

	i = 0;
	(void)argc;
	(void)argv;
	if (parse_cmds(argc, argv, &(*data)) != 0)
	{
		free((*data)->cmd_paths);
		return (print_error("Fail parsing commands.", "", "", 1));
	}
	while ((*data)->cmd_paths[i])
		i++;
	(*data)->cmd_count = i;
	if (parse_fd(argc, argv, &(*data)) != 0)
	{
		free((*data)->cmd_paths);
		return (print_error("Fail parsing files.", "", "", 1));
	}
	return (0);
}

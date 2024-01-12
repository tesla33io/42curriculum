/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:47:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/12 19:00:58 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define R			"\x1b[0m"

# define BLACK		"\x1b[30m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1b[37m"

# define B_BLACK	"\x1b[40m"
# define B_RED		"\x1b[41m"
# define B_GREEN	"\x1b[42m"
# define B_YELLOW	"\x1b[43m"
# define B_BLUE		"\x1b[44m"
# define B_MAGENTA	"\x1b[45m"
# define B_CYAN		"\x1b[46m"
# define B_WHITE	"\x1b[47m"

# define S_BOLD			"\x1b[1m"
# define S_ITALIC		"\x1b[3m"
# define S_UNDERLINE	"\x1b[4m"

typedef struct s_data
{
	char		*first_cmd;
	char		*first_cmd_argv;
	char		*second_cmd;
	char		*second_cmd_argv;
	int			infile_fd;
	int			outfile_fd;
}	t_data;

// check_input.c
int				check_input(int argc, char **argv);
int				print_error(char *message, int code);

// parse.c
int				parse_data(int argc, char **argv, t_data *data);

#endif // !PIPEX_H

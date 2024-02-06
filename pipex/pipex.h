/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:47:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/06 20:28:16 by astavrop         ###   ########.fr       */
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

# include "./libft/libft.h"
# include "./ft_printf/includes/ft_printf.h"
# include <stddef.h>

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_pipex
{
	int			status;
	int			in_fd;
	int			out_fd;
	t_bool		is_invalid_infile;
	char		**path;
	char		**cmd_paths;
	char		***cmd_args;
	int			row_c;
	int			cmd_count;
}	t_pipex;

typedef struct s_pip
{
	int			in_pipe[2];
	int			out_pipe[2];
}	t_pip;

// check_input.c
int				check_input(int argc, char **argv);
int				print_error(char *msg, char *msg2, char *msg3, int code);

// parse_cmds
int				parse_data(int argc, char **argv, t_pipex **data);

// parse_args
int				parse_args(int argc, char **argv, t_pipex **data);

// parse_utils
char			*get_bin(char *cmd);
void			free_cmd_help_staff(char *cmd, char *cmd_path, char *cmds);
int				return_free(void *ptr, int code);

// execute
int				exec_first(t_pipex **data, char **env, int pipefd[2]);
int				exec_middle(t_pipex **data, int i, char **env, t_pip **pip);
int				exec_last(t_pipex **data, char **env, int pipefd[2]);

// utils
void			print_usage(void);
t_pipex			*init_pipex(char **env);
char			**get_path(char **env);
char			**append_to_list(char **list, char *str);

// clear_data
void			end(t_pipex **data, int code);
void			list_free(char **lst);

// libft
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *s);

#endif // !PIPEX_H

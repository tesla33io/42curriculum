/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:47:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/15 18:59:29 by astavrop         ###   ########.fr       */
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
	int			in_fd;
	int			out_fd;
	t_bool		is_invalid_infile;
	char		**path;
	char		**cmd_paths;
	char		***cmd_args;
	int			cmd_count;
}	t_pipex;

// check_input.c
int				check_input(int argc, char **argv);
int				print_error(char *message, int code);

// parse.c
int				parse_data(int argc, char **argv, t_pipex **data);

// utils
void			print_usage(void);
t_pipex			*init_pipex(char **env);
void			end(t_pipex **data);
char			**get_path(char **env);
char			**append_to_list(char **list, char *str);

// libft
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *s);

#endif // !PIPEX_H

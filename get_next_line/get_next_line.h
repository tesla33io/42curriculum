/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:22 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/16 18:50:55 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif // !BUFFER_SIZE

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char		*get_next_line(int fd);

// Utils
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

#endif // !GET_NEXT_LINE_H
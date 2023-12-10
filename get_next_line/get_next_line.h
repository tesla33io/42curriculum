/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:18:22 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/10 22:03:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

char		*get_next_line(int fd);

// Utils
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
#endif // !BUFFER_SIZE

#endif // !GET_NEXT_LINE_H
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:54 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:32:40 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

// DELETE
extern int	g_num_test;
void		print_ok(void);
void		print_ko(void);

int			test_ft_is(int (*func)(int), int arg, int excpected);
int			test_ft_str(int (*func)(char *), char *arg, int excpected);
int			test_ft_memset(int buf_size, char c);
int			test_memcpy(char *str, size_t n);
int			test_bzero(int i);
int			test_memmove(const char *src, size_t n);
int			test_strlcpy(const char *src);
int			test_strlcat(const char *src);
int			test_toupper(int c, int expected);
int			test_tolower(int c, int expected);
int			test_strchr(const char *str, char c);
int			test_strrchr(const char *str, char c);
int			test_strncmp(const char *s1, const char *s2, size_t n);
int			test_memchr(const void *src, char c, size_t n);
int			test_memcmp(const void *s1, const void *s2, size_t n);
int			test_strnstr(char *big, char *little, size_t len);
int			test_calloc(size_t nmemb, size_t size);
// DELETE

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(char *dest, const char *src, size_t n);
void	*ft_memmove(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, char c);
char	*ft_strrchr(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *src, char c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(char *big, char *little, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);

#endif // !LIBFT_H
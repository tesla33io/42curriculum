#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>

// DELETE
extern int g_num_test;
void	print_ok();
void	print_ko();
int		test_ft_is(int (*func)(int), int arg, int excpected);
int		test_ft_str(int (*func)(char *), char *arg, int excpected);
int		test_ft_memset(int buf_size, char c);
int		test_memcpy(char *str, size_t n);
int		test_bzero(int i);
int		test_memmove(const char *src, size_t n);
int		test_strlcpy(const char *src);
int		test_strlcat(const char *src);
int		test_toupper(int c, int expected);

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

#endif // !LIBFT_H
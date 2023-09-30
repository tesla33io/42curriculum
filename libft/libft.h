#ifndef LIBFT_H
#define LIBFT_H

// DELETE
extern int g_num_test;
void	print_ok();
void	print_ko();
int		test_memcpy(char *str, unsigned int n);
int		test_memmove(const char *src, unsigned int n);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *s);
void	*ft_memset(void *s, int c, unsigned int n);
void	ft_bzero(void *s, unsigned int n);
void	*ft_memcpy(char *dest, const char *src, unsigned int n);
void	*ft_memmove(char *dest, const char *src, unsigned int n);

#endif // !LIBFT_H
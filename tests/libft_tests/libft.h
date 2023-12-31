#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

extern int	g_num_test;
void	print_ok(void);
void	print_ko(void);

int		test_ft_is(int (*func)(int), int arg, int excpected);
int		test_ft_str(int (*func)(char *), char *arg, int excpected);
int		test_ft_memset(int buf_size, char c);
int		test_memcpy(char *str, size_t n);
int		test_bzero(int i);
int		test_memmove(const char *src, size_t n);
int		test_strlcpy(const char *src);
int		test_strlcat(const char *src);
int		test_toupper(int c, int expected);
int		test_tolower(int c, int expected);
int		test_strchr(const char *str, char c);
int		test_strrchr(const char *str, char c);
int		test_strncmp(const char *s1, const char *s2, size_t n);
int		test_memchr(const void *src, char c, size_t n);
int		test_memcmp(const void *s1, const void *s2, size_t n);
int		test_strnstr(char *big, char *little, size_t len);
int		test_calloc(size_t nmemb, size_t size);
int		test_strdup(const char *s);
int		test_ft_substr(char const *s, unsigned int start, size_t len, char *expected);
int		test_ft_strjoin(char const *s1, char const *s2, char const *expected);
int		test_ft_strtrim(char const *s1, char const *set, char const *expected);
int		test_ft_split(const char *s, const char c, const char **exp);
int		test_ft_itoa(int n, char *exp);
int		test_ft_strmapi(char const *s, char (*f)(unsigned int, char), char *exp);
int		test_ft_striteri(char *s, void (*f)(unsigned int, char *), char *exp);
int		test_ft_putchar_fd(char c, int fd);
int		test_atoi(const char *nptr, int exp);
int		test_ft_lstnew();
int		test_ft_lstadd_front();
void	free_list(t_list *head);
int		test_ft_lstsize();
int		test_ft_lstlast();
int		test_ft_lstadd_back();
int		test_ft_lstdelone();
int		test_ft_lstclear();

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, void const *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
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
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif // !LIBFT_H
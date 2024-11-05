#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

/* Character Classification and Conversion Functions */

int	ft_isalpha(int ch);
int	ft_isprint(int c);
int	ft_isdigit(int c);
int	ft_isascii(int ch);
int	ft_tolower(int c);
int	ft_toupper(int c);

/* String Manipulation Functions*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

/* File Descriptor Functions*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);


#endif //LIBFT_H

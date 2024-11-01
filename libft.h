#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>


/*
 * Character Classification and Conversion Functions
*/
int	ft_isalpha(int ch);
int	ft_isprint(int c);
int	ft_isdigit(int c);
int	ft_isascii(int ch);
int	ft_tolower(int c);
int	ft_toupper(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif //LIBFT_H

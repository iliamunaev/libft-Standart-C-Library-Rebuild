#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>


/*
 * Character Classification and Conversion Functions
*/
int	ft_isalpha(int ch);
int	ft_isprint(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_isdigit(int c);
int	ft_isascii(int ch);
size_t	ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strnstr(const char *big, const char *little, size_t len);
char    *ft_strrchr(const char *s, int c);

/*
 * String Manipulation Functions
*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

#endif //LIBFT_H

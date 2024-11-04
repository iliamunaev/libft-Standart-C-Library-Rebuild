/*
 * The strrchr() function locates the last occurrence of c (converted to a char)
 * in the string pointed to by s. The terminating NUL character is
 * considered to be part of the string.
 * Return: a pointer to the byte or a null pointer if c does not occur in the string.
 */
#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    const char  *tail;
    size_t  s_len;

    tail = s + ft_strlen(s);
    s_len = ft_strlen(s);
    if ((char)c == '\0')
    {
        return ((char *)tail);
    }
    while (s_len > 0)
    {
        if (*tail == c)
        {
            return ((char *)tail);
        }
        s_len--;
        tail--;
    }
    return (NULL);
}
/*
 * The function returns a pointer to the first occurrence of the character c 
 * in the string s ('\0' included) or NULL if the character is not found.
*/
#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
        {
            return ((char *)s);
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return (NULL);
}

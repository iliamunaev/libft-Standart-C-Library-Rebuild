/*
 * The function returns a pointer to the last occurrence of the character c in the string s
 * ('\0' included) or NULL if the character is not found.
*/
#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    const char  *tail;
    size_t  slen;

    tail = s + ft_strlen(s);
    slen = ft_strlen(s);
    if ((char)c == '\0')
    {
        return ((char *)tail);
    }
    while (slen > 0)
    {
        if (*tail == c)
        {
            return ((char *)tail);
        }
        slen--;
        tail--;
    }
    return (NULL);
}
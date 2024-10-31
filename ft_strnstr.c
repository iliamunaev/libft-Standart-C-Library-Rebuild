/*
* The function locates the first occurrence of the  null-terminated
* string little in the string big, where not more than len characters are searched.
* If little is an empty string, big is returned; if little	occurs nowhere
* in big, NULL is returned; otherwise a pointer to	the first character of
* the first occurrence of little is returned.
*/
#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t little_len;

    little_len = ft_strlen(little);
    if (*little == '\0')
    {
        return ((char *)big);
    }
    if (len < little_len)
    {
        return (NULL);
    }
    while (*big != '\0' && len >= little_len)
    {
        if (ft_strncmp(big, little, little_len) == 0)
        {
            return ((char *)big);
        }
        big++;
        len--;
    }
    return (NULL);
}

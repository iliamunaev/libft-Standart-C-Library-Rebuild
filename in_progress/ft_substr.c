/*
* The function allocates (with malloc(3)) and returns a substring
* from the string ’s’. The substring begins at index ’start’ and is of
* maximum size ’len’.
* Return: the substring, NULL if the allocation fails.
*/
#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  s_len;

    s_len = ft_strlen(s);
    if (start >= s_len)
        return (malloc(1)); // for '\0'
    if (len > s_len - start)
        len = s_len - start;
    substr = malloc(len + 1);
    if (!substr)
        return (NULL);
    ft_strlcpy(substr, s + start, len + 1);
    return (substr);
}
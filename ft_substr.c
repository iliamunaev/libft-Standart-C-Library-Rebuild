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
    
    // If start is beyond the end of s, return an empty string
    if (start >= s_len)
    {
        substr = malloc(1);
        if (!substr)
            return NULL;
        substr[0] = '\0';
        return substr;
    }
    
    // Adjust len if it goes beyond the end of s
    if (len > s_len - start)
        len = s_len - start;

    // Allocate memory for the substring
    substr = malloc(len + 1);
    if (!substr)
        return NULL;

    // Copy substring and null-terminate
    ft_strlcpy(substr, s + start, len + 1);
    return substr;
}
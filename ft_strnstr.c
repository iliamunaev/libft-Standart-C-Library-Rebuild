/*
 * The function locates the first occurrence of the null-terminated
 * string 'little' in the string 'big', where not more than 'len' characters
 * are searched.
 * Return: 'big', if 'little' is an empty string;
 * NULL if 'little' occurs nowhere in 'big';
 * otherwise a pointer to the first character of the first occurrence of 'little'.
 */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t little_len;

    little_len = ft_strlen(little);
    if (!little)
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

/*
 * The function allocates (with malloc(3)) and returns a copy of ’s1’
 * with the characters specified in ’set’ removed from the beginning
 * and the end of the string.
 * Return: the trimmed string, NULL if the allocation fails
 */
#include "libft.h"

static int  is_inset(char const *set, char c)
{
    while (*set)
    {
        if (*set == c)
            return (1);
        set++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    char    *str_trim;

    start = 0;
    end = ft_strlen(s1);
    if (!s1 || !set)
        return (NULL);    
    while (s1[start] && is_inset(set, s1[start]))
    {
        start++;
    }
    while (end > start && is_inset(set, s1[end - 1]))
    {
        end--;
    }
    str_trim = (char *)malloc(end - start + 1);
    if (!str_trim)
    {
        return (NULL);
    ft_strlcpy(str_trim, s1 + start, end - start + 1);    
    return (str_trim);
}
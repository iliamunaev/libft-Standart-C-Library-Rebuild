/*
 * The function allocates (with malloc(3)) and returns a copy of ’s1’
 * with the characters specified in ’set’ removed from the beginning
 * and the end of the string.
 * Return: the trimmed string, NULL if the allocation fails
 */
#include "libft.h"

static int is_inset(char const *set, char c)
{
    while (*set)
    {
        if (*set == c)
            return (1);
        set++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    char *str_trim;

    if (!s1 || !set)
        return (NULL);
        
    start = 0;
    end = ft_strlen(s1);
    
    // Move `start` to the first character not in `set`
    while (s1[start] && is_inset(set, s1[start]))
        start++;

    // Move `end` to the last character not in `set`
    while (end > start && is_inset(set, s1[end - 1]))
        end--;

    // Allocate memory for the trimmed string
    str_trim = (char *)malloc((end - start + 1) * sizeof(char));
    if (!str_trim)
        return (NULL);

    // Copy the trimmed portion of `s1` into `str_trim`
    ft_strlcpy(str_trim, s1 + start, end - start + 1);

    return (str_trim);
}
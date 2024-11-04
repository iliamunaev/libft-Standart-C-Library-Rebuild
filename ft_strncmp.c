/*
 * The function compares two strings s1 and s2 up to
 * the first (at most) 'n' bytes of s1 and s2.
 * Return: an integer less than, equal to, or greater than
 * zero if s1 (or the first n bytes thereof) is found,
 * respectively, to be less than, to match, or be greater than s2.
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n-- > 0)
    {
        if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
        {
            return ((unsigned char)*s1 - (unsigned char)*s2);
        }
        s1++;
        s2++;
    }
    return (0);
}
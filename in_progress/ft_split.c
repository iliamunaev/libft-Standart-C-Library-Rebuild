/*
 * The fnction allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end
 * with a NULL pointer.
 * Return: the array of new strings resulting from the split;
 * NULL if the allocation fails.
*/

#include "libft.h"

static  int is_delimeter(unsigned char index, char const *str, char delimeter)
{
    while (str++)
    {
        if (*str == delimeter)
        {
            return(index)
        }
        index++;
    }
    return(0);
}

char    **ft_split(char const *s, char c)
{
    char  **arr;
    unsigned char   len;
    unsigned char   index;

    len = 0;
    index = 0;
    head = 0;
    // itarate through 's'
    // if 'c' -> count chars in sub_s, allocate memory, add sub_s

    while (index <= ft_strlen(s))
    {
        index = is_delimeter(index, s, c);
        sub_s = s[head:tail];
        sub_s = malloc(len + 1);
        if (!sub_s)
        {
            return(NULL);
            free(arr);
        }
        ft_strlcpy(arr[i], sub_s, len + 1);
        *arr++ = *sub_s;
        head = index + 1;
    }
    return(arr);
}
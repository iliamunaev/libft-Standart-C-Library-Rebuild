/* The function scans the initial n bytes of the memory area pointed to by s
* for the first instance of c. Both c and the bytes of the memory
* area pointed to by s are interpreted as unsigned char.
* Return a pointer to the matching byte or NULL if the character does not
* occur in the given memory area.
*/
#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptrs;

    ptrs = s;
    while (n--)
    {
        if (*ptrs == (unsigned char)c)
        {
            return ((void *)ptrs);
        }
        ptrs++;
    }
    return (NULL);
}

#include <stdio.h>

int main()
{
    char data[] = "Hello, world!";
    char c = 'o';
    size_t n = 10; // Only search in the first 10 bytes

    char *result = ft_memchr(data, c, n);
    if (result != NULL)
    {
        printf("Character '%c' found at position: %ld\n", c, result - data);
    }
    else
    {
        printf("Character '%c' not found in the first %zu bytes.\n", c, n);
    }

    return 0;
}

 /* 
 * The function allocates memory for an array of nmemb elements
 * of size bytes each. The space shall be initialized to all bits 0.
 * Return: a pointer to the allocated memory.
 */
#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char   *memptr;

    // Check for zero-size allocation
    if (nmemb == 0 || size == 0)
    {
        return (NULL);
    }
    memptr = malloc(nmemb * size);
    if (!memptr)
    {
        return (NULL);
    }
    // Set allocated memory to zero
    ft_memset(memptr, 0, nmemb * size);
    return (memptr);
}



/* The function erases the data in the n bytes of the memory starting 
* at the location pointed to by s, by writing zeros (bytes containing '\0')
* to that area.
* Return: None.
*/

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, '\0', n);
}

#include <stdio.h>
int main()
{
    char data[10] = "123456789";

    printf("Before bzero: %s\n", data);
    ft_bzero(data, 5);
    printf("After bzero: ");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%c", data[i] ? data[i] : '.');
    }
    printf("\n");

    return (0);
}
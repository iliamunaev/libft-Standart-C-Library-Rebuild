/*The function  compares the first n bytes (each interpreted as unsigned char)
 * of the memory areas s1 and s2.
 * Returns an integer less than, equal to, or greater than zero if 
 * the first n bytes of s1 is found, respectively, to be less than, 
 * to match, or be greater than the first n bytes of s2.
 */

 #include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ptr1;
    const unsigned char *ptr2;

    ptr1 = s1;
    ptr2 = s2;
    while (n--)
    {
        if (*ptr1 != *ptr2)
        {
            return (*ptr1 - *ptr2);
        }
        ptr1++;
        ptr2++;
    }
    return (0);
}



#include <stdio.h>

int main()
{
    char arr1[] = {1, 2, 3, 4, 5};
    char arr2[] = {1, 2, 3, 4, 6};

    int result = ft_memcmp(arr1, arr2, 5);

    if (result < 0)
        printf("arr1 is less than arr2.\n");
    else if (result > 0)
        printf("arr1 is greater than arr2.\n");
    else
        printf("arr1 is equal to arr2.\n");

    return 0;
}

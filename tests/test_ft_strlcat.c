#include "../test42lib/test42lib.h"

void    test_ft_strlcat(void)
{
    char dest1[10] = "abc";
    const char *src = "defgh";
    size_t size;

    // Case 1: Enough free space for full concatenation
    size = 10;
    ASSERT_EQUAL_INT(8, ft_strlcat(dest1, src, size));
    printf("Before concat (case 1): dest = '%s', src = '%s', size = %zu\n", dest1, src, size);
    printf("After concat (case 1): dest = '%s'\n", dest1);

    // Case 2: Partly free space avalible
    char dest2[10] = "abc";
    size = 6;
    ASSERT_EQUAL_INT(8, ft_strlcat(dest2, src, size));
    printf("Before concat (case 2): dest = '%s', src = '%s', size = %zu\n", dest2, src, size);
    printf("After concat (case 2): dest = '%s'\n", dest2);

    // Case 3: Free space not enough (size = 0)
    char dest3[10] = "abc";
    size = 4;
    ASSERT_EQUAL_INT(8, ft_strlcat(dest3, src, size));
    printf("Before concat (case 3): dest = '%s', src = '%s', size = %zu\n", dest3, src, size);
    printf("After concat (case 3): dest = '%s'\n", dest3);

    // Case 4: Free space not enough (size = 2)
    char dest4[10] = "abc";
    size = 2;
    ASSERT_EQUAL_INT(7, ft_strlcat(dest4, src, size));
    printf("Before concat (case 4): dest = '%s', src = '%s', size = %zu\n", dest4, src, size);    
    printf("After concat (case 4): dest = '%s'\n", dest4);

    // Case 5: Buffer size is zero
    char dest5[10] = "abc";
    size = 0;
    ASSERT_EQUAL_INT(5, ft_strlcat(dest5, src, size));
    printf("Before concat (case 5): dest = '%s', src = '%s', size = %zu\n", dest5, src, size);    
    printf("After concat (case 5): dest = '%s'\n", dest5);
}

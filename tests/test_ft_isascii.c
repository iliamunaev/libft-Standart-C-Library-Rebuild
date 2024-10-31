#include "../test42lib/test42lib.h"

void    test_ft_isascii(void)
{
    // Test 0, 127
    printf("Test 0, 127 ...\n");

    ASSERT_EQUAL_INT(1, ft_isascii(0));
    ASSERT_EQUAL_INT(1, ft_isascii(127));

    // Test -1, 128
    printf("Test -1, 128 ...\n");

    ASSERT_EQUAL_INT(0, ft_isascii(-1));
    ASSERT_EQUAL_INT(0, ft_isascii(128));
}
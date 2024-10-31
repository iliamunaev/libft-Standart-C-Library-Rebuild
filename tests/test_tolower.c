#include "../test42lib/test42lib.h"

void    test_ft_tolower(void)
{
    // Test A, Z, B, Y
    printf("Test A, Z, B, Y ...\n");

    ASSERT_EQUAL_CHAR('a', ft_tolower('A'));
    ASSERT_EQUAL_CHAR('z', ft_tolower('Z'));
    ASSERT_EQUAL_CHAR('b', ft_tolower('B'));
    ASSERT_EQUAL_CHAR('y', ft_tolower('Y'));
}
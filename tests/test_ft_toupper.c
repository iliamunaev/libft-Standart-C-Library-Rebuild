#include "../test42lib/test42lib.h"

void    test_ft_toupper(void)
{
    // Test a, z, b, y
    printf("Test a, z, b, y ...\n");

    ASSERT_EQUAL_CHAR('A', ft_toupper('a'));
    ASSERT_EQUAL_CHAR('Z', ft_toupper('z'));
    ASSERT_EQUAL_CHAR('B', ft_toupper('b'));
    ASSERT_EQUAL_CHAR('Y', ft_toupper('y'));
}
#include "../test42lib/test42lib.h"
#include "tests.h"

void    test_ft_toupper(void)
{
    // Test lowcase a, z
    ASSERT_EQUAL_CHAR('A', ft_toupper('a'));
    ASSERT_EQUAL_CHAR('Z', ft_toupper('z'));

    // Test uppercase A, Z
    ASSERT_EQUAL_CHAR('A', ft_toupper('A'));
    ASSERT_EQUAL_CHAR('Z', ft_toupper('Z'));

    // Test non-alpha
    ASSERT_EQUAL_CHAR('@', ft_toupper('@'));
    ASSERT_EQUAL_CHAR('!', ft_toupper('!'));
}
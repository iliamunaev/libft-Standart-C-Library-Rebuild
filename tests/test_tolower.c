#include "../test42lib/test42lib.h"
#include "tests.h"

void    test_ft_tolower(void)
{
    // Test lowcase a, z
    ASSERT_EQUAL_CHAR('a', ft_tolower('a'));
    ASSERT_EQUAL_CHAR('z', ft_tolower('z'));

    // Test uppercase A, Z
    ASSERT_EQUAL_CHAR('a', ft_tolower('A'));
    ASSERT_EQUAL_CHAR('z', ft_tolower('Z'));

    // Test non-alpha
    ASSERT_EQUAL_CHAR('@', ft_tolower('@'));
    ASSERT_EQUAL_CHAR('!', ft_tolower('!'));
}
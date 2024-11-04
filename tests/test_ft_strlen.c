#include "../test42lib/test42lib.h"
#include "tests.h"

void    test_ft_strlen(void)
{
    // Test 'a', 'abc', 'abs def', '123'
    ASSERT_EQUAL_INT(1, ft_strlen("a"));
    ASSERT_EQUAL_INT(3, ft_strlen("abc"));
    ASSERT_EQUAL_INT(7, ft_strlen("abc def"));
    ASSERT_EQUAL_INT(3, ft_strlen("123"));

    // Test empty str
    ASSERT_EQUAL_INT(0, ft_strlen(""));

    // Test empty str ('\0')
    ASSERT_EQUAL_INT(0, ft_strlen("\0"));
}
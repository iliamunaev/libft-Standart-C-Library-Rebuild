#include "../test42lib/test42lib.h"
#include "tests.h"

void    test_ft_isascii(void)
{
    // Test 0, 127
    ASSERT_RETURN_NONZERO(ft_isascii(0));
    ASSERT_RETURN_NONZERO(ft_isascii(127));

    // Test -1, 128
    ASSERT_RETURN_ZERO(ft_isascii(-1));
    ASSERT_RETURN_ZERO(ft_isascii(128));
}
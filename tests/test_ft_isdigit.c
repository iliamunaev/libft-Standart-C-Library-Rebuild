#include "../test42lib/test42lib.h"
#include "tests.h"

void    test_ft_isdigit(void)
{
    // Test 0, 9
    ASSERT_RETURN_NONZERO(ft_isdigit(0));
    ASSERT_RETURN_NONZERO(ft_isdigit(9));

    // Test A, @
    ASSERT_RETURN_ZERO(ft_isdigit('A'));
    ASSERT_RETURN_ZERO(ft_isdigit('@'));
}
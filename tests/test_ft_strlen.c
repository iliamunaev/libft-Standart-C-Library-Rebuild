#include "../imtest42/imtest42.h"
#include "tests.h"

void    test_ft_strlen(void)
{
    // Test normal strings
    IM_ASSERT_INT_EQUAL(ft_strlen("Hello, World!"), 13);
    IM_ASSERT_INT_EQUAL(ft_strlen(""), 0);
    IM_ASSERT_INT_EQUAL(ft_strlen("42"), 2);

    // Test special characters
    IM_ASSERT_INT_EQUAL(ft_strlen("\n\t\r"), 3);
    IM_ASSERT_INT_EQUAL(ft_strlen("foo\0bar"), 3);
}

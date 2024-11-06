#include "../imtest42/imtest42.h"
#include "tests.h"

void test_ft_isalnum(void)
{
    // Test digits
    IM_ASSERT_NONZERO(ft_isalnum('0'));
    IM_ASSERT_NONZERO(ft_isalnum('5'));
    IM_ASSERT_NONZERO(ft_isalnum('9'));

    // Test lowercase alphabetic characters
    IM_ASSERT_NONZERO(ft_isalnum('a'));
    IM_ASSERT_NONZERO(ft_isalnum('m'));
    IM_ASSERT_NONZERO(ft_isalnum('z'));

    // Test uppercase alphabetic characters
    IM_ASSERT_NONZERO(ft_isalnum('A'));
    IM_ASSERT_NONZERO(ft_isalnum('N'));
    IM_ASSERT_NONZERO(ft_isalnum('Z'));

    // Test non-alphanumeric characters (special characters)
    IM_ASSERT_ZERO(ft_isalnum('@'));
    IM_ASSERT_ZERO(ft_isalnum('['));
    IM_ASSERT_ZERO(ft_isalnum('`'));
    IM_ASSERT_ZERO(ft_isalnum('{'));

    // Test whitespace characters
    IM_ASSERT_ZERO(ft_isalnum(' '));
    IM_ASSERT_ZERO(ft_isalnum('\n'));
    IM_ASSERT_ZERO(ft_isalnum('\t'));

    // Test extended ASCII characters
    IM_ASSERT_ZERO(ft_isalnum(128));
    IM_ASSERT_ZERO(ft_isalnum(255));

    // Test negative values
    IM_ASSERT_ZERO(ft_isalnum(-1));
    IM_ASSERT_ZERO(ft_isalnum(-128));
}

#include "../test42lib/test42lib.h"
#include "tests.h"

void	test_ft_isalpha(void)
{
    // Test lowercase letters
    ASSERT_RETURN_NONZERO(ft_isalpha('a'));
    ASSERT_RETURN_NONZERO(ft_isalpha('z'));

    // Test uppercase letters
    ASSERT_RETURN_NONZERO(ft_isalpha('A'));
    ASSERT_RETURN_NONZERO(ft_isalpha('Z'));

    // Test non-alphabetic characters
    ASSERT_RETURN_ZERO(ft_isalpha('1'));
    ASSERT_RETURN_ZERO(ft_isalpha('@'));
    ASSERT_RETURN_ZERO(ft_isalpha('['));
}
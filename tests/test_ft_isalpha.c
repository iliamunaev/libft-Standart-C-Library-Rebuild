#include "test42lib/test42lib.h"
#include "../libft.h"

void	test_ft_isalpha()
{
    // Test lowercase letters
    ASSERT_EQUAL_INT(1, ft_isalpha('a'), "test_ft_isalpha_lowercase_a");
    ASSERT_EQUAL_INT(1, ft_isalpha('z'), "test_ft_isalpha_lowercase_z");

    // Test uppercase letters
    ASSERT_EQUAL_INT(1, ft_isalpha('A'), "test_ft_isalpha_uppercase_A");
    ASSERT_EQUAL_INT(1, ft_isalpha('Z'), "test_ft_isalpha_uppercase_Z");

    // Test non-alphabetic characters
    ASSERT_EQUAL_INT(0, ft_isalpha('1'), "test_ft_isalpha_digit_1");
    ASSERT_EQUAL_INT(0, ft_isalpha('@'), "test_ft_isalpha_symbol_at");
    ASSERT_EQUAL_INT(0, ft_isalpha('['), "test_ft_isalpha_non_alpha_bracket");
}
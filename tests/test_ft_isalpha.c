#include "../test42lib/test42lib.h"

void	test_ft_isalpha(void)
{
    // Test lowercase letters
    printf("Test lowercase letters...\n");
    ASSERT_EQUAL_INT(1, ft_isalpha('a'));
    ASSERT_EQUAL_INT(1, ft_isalpha('z'));

    // Test uppercase letters
    printf("Test uppercase letters...\n");
    ASSERT_EQUAL_INT(1, ft_isalpha('A'));
    ASSERT_EQUAL_INT(1, ft_isalpha('Z'));

    // Test non-alphabetic characters
    printf("Test non-alphabetic characters...\n");
    ASSERT_EQUAL_INT(0, ft_isalpha('1'));
    ASSERT_EQUAL_INT(0, ft_isalpha('@'));
    ASSERT_EQUAL_INT(0, ft_isalpha('['));
}
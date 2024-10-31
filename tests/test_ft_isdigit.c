#include "../test42lib/test42lib.h"

void    test_ft_isdigit(void)
{
    // Test 0, 9
    printf("Test 0, 9 ...\n");

    ASSERT_EQUAL_INT(1, ft_isdigit(0));
    ASSERT_EQUAL_INT(1, ft_isdigit(9));

    // Test A, @
    printf("Test A, @ ...\n");

    ASSERT_EQUAL_INT(0, ft_isdigit('A'));
    ASSERT_EQUAL_INT(0, ft_isdigit('@'));
}
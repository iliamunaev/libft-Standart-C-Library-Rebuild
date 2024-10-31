#include "../test42lib/test42lib.h"

void    test_ft_strlen(void)
{
    // Test a, abc, absdef
    printf("Test a, abc, abcdef ...\n");

    ASSERT_EQUAL_INT(1, ft_strlen("a"));
    ASSERT_EQUAL_INT(3, ft_strlen("abc"));
    ASSERT_EQUAL_INT(6, ft_strlen("abcdef"));

    // Test empty str
    printf("Test empty str ...\n");

    ASSERT_EQUAL_INT(0, ft_strlen(""));
}
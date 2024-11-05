#include "../test42lib/test42lib.h"
#include "../libft.h"

void    test_ft_itoa(void)
{
    char *result;

    // Zero
    result = ft_itoa(0);
    ASSERT_EQUAL_STR("0", result);
    free(result);

    // Max / Min integers
    result = ft_itoa(2147483647);
    ASSERT_EQUAL_STR("2147483647", result);
    free(result);

    result = ft_itoa(-2147483648);
    ASSERT_EQUAL_STR("-2147483648", result);
    free(result);

    // One-digit numbers
    result = ft_itoa(1);
    ASSERT_EQUAL_STR("1", result);
    free(result);

    result = ft_itoa(-1);
    ASSERT_EQUAL_STR("-1", result);
    free(result);

    result = ft_itoa(9);
    ASSERT_EQUAL_STR("9", result);
    free(result);

    result = ft_itoa(-9);
    ASSERT_EQUAL_STR("-9", result);
    free(result);

    // Two-digit numbers
    result = ft_itoa(10);
    ASSERT_EQUAL_STR("10", result);
    free(result);

    result = ft_itoa(-10);
    ASSERT_EQUAL_STR("-10", result);
    free(result);

    result = ft_itoa(99);
    ASSERT_EQUAL_STR("99", result);
    free(result);

    result = ft_itoa(-99);
    ASSERT_EQUAL_STR("-99", result);
    free(result);

    // Multi-digit numbers
    result = ft_itoa(12345);
    ASSERT_EQUAL_STR("12345", result);
    free(result);

    result = ft_itoa(-12345);
    ASSERT_EQUAL_STR("-12345", result);
    free(result);
}

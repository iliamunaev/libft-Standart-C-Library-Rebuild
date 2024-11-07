#include "../imtest42/imtest42.h"
#include "../libft.h"

void    test_ft_itoa(void)
{
    char *result;

    // Zero
    result = ft_itoa(0);
    IM_ASSERT_STR_EQUAL("0", result);
    free(result);

    // Max / Min integers
    result = ft_itoa(2147483647);
    IM_ASSERT_STR_EQUAL("2147483647", result);
    free(result);

    result = ft_itoa(-2147483648);
    IM_ASSERT_STR_EQUAL("-2147483648", result);
    free(result);

    // One-digit numbers
    result = ft_itoa(1);
    IM_ASSERT_STR_EQUAL("1", result);
    free(result);

    result = ft_itoa(-1);
    IM_ASSERT_STR_EQUAL("-1", result);
    free(result);

    result = ft_itoa(9);
    IM_ASSERT_STR_EQUAL("9", result);
    free(result);

    result = ft_itoa(-9);
    IM_ASSERT_STR_EQUAL("-9", result);
    free(result);

    // Two-digit numbers
    result = ft_itoa(10);
    IM_ASSERT_STR_EQUAL("10", result);
    free(result);

    result = ft_itoa(-10);
    IM_ASSERT_STR_EQUAL("-10", result);
    free(result);

    result = ft_itoa(99);
    IM_ASSERT_STR_EQUAL("99", result);
    free(result);

    result = ft_itoa(-99);
    IM_ASSERT_STR_EQUAL("-99", result);
    free(result);

    // Multi-digit numbers
    result = ft_itoa(12345);
    IM_ASSERT_STR_EQUAL("12345", result);
    free(result);

    result = ft_itoa(-12345);
    IM_ASSERT_STR_EQUAL("-12345", result);
    free(result);
}

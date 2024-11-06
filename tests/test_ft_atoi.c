#include "../imtest42/imtest42.c"
#include "tests.h"
// #include <limits.h>

void 	test_ft_atoi(void)
{
    const char *str;
    int result_ft;
    int result_std;

    // Test 1: Valid positive number
    str = "12345";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 2: Valid negative number
    str = "-54321";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 3: Leading whitespace
    str = "   42";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 4: Leading plus sign
    str = "+100";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 5: Non-digit characters at the end
    str = "123abc";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 6: Invalid string (no digits)
    str = "abc";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 7: Empty string
    str = "";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);
/*
    // Test 8: Number exceeding INT_MAX
    str = "2147483648";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 9: Number less than INT_MIN
    str = "-2147483649";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);
*/
    // Test 10: Leading zeros
    str = "0000123";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 11: Only whitespace
    str = "   ";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 12: Number with intermediate spaces
    str = "12 34";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 13: Multiple signs
    str = "--123";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 14: Non-printable characters
    str = "\n\t\v\f\r42";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 15: Max integer value
    str = "2147483647";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 16: Min integer value
    str = "-2147483648";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);
}

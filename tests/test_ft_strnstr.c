#include "../test42lib/test42lib.h"
#include "tests.h"

void test_ft_strnstr(void)
{
    const char  *big = "Hive Helsinki";
    const char  *little = "Helsinki";

    // 'little' is found within 'len'
    ASSERT_EQUAL_STR("Helsinki", ft_strnstr(big, little, 15));

    // 'little' is not found within 'len'
    ASSERT_EQUAL_NULL(ft_strnstr(big, little, 5));
    ASSERT_EQUAL_NULL(ft_strnstr(big, "42", 15));

    // 'little' is an empty string
    ASSERT_EQUAL_STR(big, ft_strnstr(big, "", 5));
    ASSERT_EQUAL_STR(big, ft_strnstr(big, "\0", 5));

    // 'big' is empty
    ASSERT_EQUAL_NULL(ft_strnstr("", "Hive", 5));

    // 'little' is larger than 'len'
    ASSERT_EQUAL_NULL(ft_strnstr(big, little, 3));

    // Exact match at end boundary
    ASSERT_EQUAL_STR( "Hive", ft_strnstr("Hive", "Hive", 6));
}
#include "../test42lib/test42lib.h"

void test_ft_strnstr(void)
{
    const char *big = "Hello, world!";
    const char *little = "world";

    printf("Case 1: `little` is found within `len`\n");
    ASSERT_EQUAL_STR(ft_strnstr(big, little, 12), "world!");

    printf("Case 2: `little` is not found within `len`\n");
    ASSERT_EQUAL_NULL(ft_strnstr(big, little, 5));

    printf("Case 3: `little` is an empty string\n");
    ASSERT_EQUAL_STR(ft_strnstr(big, "", 5), big);

    printf("Case 4: `big` is empty\n");
    ASSERT_EQUAL_NULL(ft_strnstr("", "world", 5));

    printf("Case 5: `little` is larger than `len`\n");
    ASSERT_EQUAL_NULL(ft_strnstr(big, little, 3));

    printf("Case 6: Exact match at end boundary\n");
    ASSERT_EQUAL_STR(ft_strnstr("world!", "world!", 6), "world!");
}
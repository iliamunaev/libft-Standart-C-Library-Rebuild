#include <stdlib.h>
#include "../imtest42/imtest42.h"
#include "../libft.h"

void test_ft_strnstr(void) {
    const char *big;
    const char *little;
    char *result_ft;
    char *expected;

    // Test 1: Little string is empty
    big = "hello world";
    little = "";
    result_ft = ft_strnstr(big, little, 11);
    expected = (char *)big;  // Expected to return the beginning of 'big'
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 2: Little string not found
    big = "hello world";
    little = "planet";
    result_ft = ft_strnstr(big, little, 11);
    expected = NULL;  // Expected to return NULL
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 3: Little string found at the beginning
    big = "hello world";
    little = "hello";
    result_ft = ft_strnstr(big, little, 11);
    expected = (char *)big;  // Expected to return the start of 'big'
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 4: Little string found in the middle
    big = "say hello to the world";
    little = "hello";
    result_ft = ft_strnstr(big, little, 20);
    expected = (char *)(big + 4);  // Expected to return a pointer to "hello"
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 5: Little string found at the end
    big = "say hello";
    little = "hello";
    result_ft = ft_strnstr(big, little, 9);
    expected = (char *)(big + 4);  // Expected to return a pointer to "hello"
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 6: Little string larger than big string
    big = "hi";
    little = "hello";
    result_ft = ft_strnstr(big, little, 2);
    expected = NULL;  // Expected to return NULL
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 7: len smaller than little string length
    big = "hello world";
    little = "world";
    result_ft = ft_strnstr(big, little, 3);
    expected = NULL;  // Expected to return NULL
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 8: len is zero
    big = "hello world";
    little = "hello";
    result_ft = ft_strnstr(big, little, 0);
    expected = NULL;  // Expected to return NULL
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 9: Big string contains little string after len
    big = "hello world";
    little = "world";
    result_ft = ft_strnstr(big, little, 5);
    expected = NULL;  // Expected to return NULL since "world" is beyond len
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 10: Searching for null terminator
    big = "hello";
    little = "\0";
    result_ft = ft_strnstr(big, little, 5);
    expected = (char *)big;  // Expected to return start of 'big'
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Additional Tests:

    // Test 11: Little string not found within len
    big = "abcdef";
    little = "def";
    result_ft = ft_strnstr(big, little, 3);
    expected = NULL;  // Expected to return NULL
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 12: Big and little are the same
    big = "teststring";
    little = "teststring";
    result_ft = ft_strnstr(big, little, 10);
    expected = (char *)big;  // Expected to return the start of 'big'
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 13: Big is empty, little is not
    big = "";
    little = "a";
    result_ft = ft_strnstr(big, little, 1);
    expected = NULL;  // Expected to return NULL
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 14: Big and little are empty
    big = "";
    little = "";
    result_ft = ft_strnstr(big, little, 1);
    expected = (char *)big;  // Expected to return the start of 'big'
    IM_ASSERT_PTR_EQUAL(result_ft, expected);

    // Test 15: len is larger than big string length
    big = "short";
    little = "rt";
    result_ft = ft_strnstr(big, little, 50);
    expected = (char *)(big + 3);  // Expected to return pointer to "rt"
    IM_ASSERT_PTR_EQUAL(result_ft, expected);
}

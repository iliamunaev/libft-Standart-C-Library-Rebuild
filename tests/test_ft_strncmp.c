#include <string.h>
#include "../imtest42/imtest42.h"
#include "../libft.h"

void	test_ft_strncmp(void)
{
    int ret_ft;
    int ret_std;

    // Test 1: Identical strings
    ret_ft = ft_strncmp("hello", "hello", 5);
    ret_std = strncmp("hello", "hello", 5);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 2: Different strings
    ret_ft = ft_strncmp("hello", "world", 5);
    ret_std = strncmp("hello", "world", 5);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 3: Partial comparison
    ret_ft = ft_strncmp("hello", "helicopter", 3);
    ret_std = strncmp("hello", "helicopter", 3);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 4: String with null characters
    ret_ft = ft_strncmp("abc\0def", "abc\0xyz", 7);
    ret_std = strncmp("abc\0def", "abc\0xyz", 7);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 5: One string is prefix of the other
    ret_ft = ft_strncmp("hello", "hello world", 11);
    ret_std = strncmp("hello", "hello world", 11);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 6: Empty strings
    ret_ft = ft_strncmp("", "", 5);
    ret_std = strncmp("", "", 5);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 7: n is zero
    ret_ft = ft_strncmp("hello", "world", 0);
    ret_std = strncmp("hello", "world", 0);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 8: Strings differ at last character
    ret_ft = ft_strncmp("abcd", "abce", 4);
    ret_std = strncmp("abcd", "abce", 4);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 9: Non-ASCII characters
    ret_ft = ft_strncmp("héllo", "héllö", 5);
    ret_std = strncmp("héllo", "héllö", 5);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 10: Large n value
    ret_ft = ft_strncmp("hello", "hello", 1000);
    ret_std = strncmp("hello", "hello", 1000);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);
}

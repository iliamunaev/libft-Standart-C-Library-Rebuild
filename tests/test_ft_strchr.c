#include <string.h>
#include "../imtest42/imtest42.h"
#include "../libft.h"

void test_ft_strchr(void)
{
    const char *s;
    char *result_ft;
    char *result_std;

    // Test 1: Character present in string
    s = "hello world";
    result_ft = ft_strchr(s, 'o');
    result_std = strchr(s, 'o');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 2: Character not present in string
    s = "hello world";
    result_ft = ft_strchr(s, 'x');
    result_std = strchr(s, 'x');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 3: Search for null terminator
    s = "hello world";
    result_ft = ft_strchr(s, '\0');
    result_std = strchr(s, '\0');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 4: Empty string
    s = "";
    result_ft = ft_strchr(s, 'a');
    result_std = strchr(s, 'a');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 5: Character at the beginning
    s = "abcde";
    result_ft = ft_strchr(s, 'a');
    result_std = strchr(s, 'a');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 6: Character at the end
    s = "abcde";
    result_ft = ft_strchr(s, 'e');
    result_std = strchr(s, 'e');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 8: Character with value greater than 127
    s = "hello\xFFworld";
    result_ft = ft_strchr(s, '\xFF');
    result_std = strchr(s, '\xFF');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 9: Character code greater than 255
    s = "abc";
    result_ft = ft_strchr(s, 300);
    result_std = strchr(s, 300);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 10: Negative character code
    s = "abc";
    result_ft = ft_strchr(s, -1);
    result_std = strchr(s, -1);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);
}

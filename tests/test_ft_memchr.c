#include <string.h>
#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_memchr(void)
{
    const char *s;
    void *result_ft;
    void *result_std;

    // Test 1: Character present in memory area
    s = "hello world";
    result_ft = ft_memchr(s, 'o', 11);
    result_std = memchr(s, 'o', 11);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 2: Character not present in memory area
    s = "hello world";
    result_ft = ft_memchr(s, 'x', 11);
    result_std = memchr(s, 'x', 11);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 3: Search for null terminator
    s = "hello\0world";
    result_ft = ft_memchr(s, '\0', 11);
    result_std = memchr(s, '\0', 11);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 4: n is zero
    s = "hello world";
    result_ft = ft_memchr(s, 'h', 0);
    result_std = memchr(s, 'h', 0);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 5: Empty memory area
    s = "";
    result_ft = ft_memchr(s, 'a', 1);
    result_std = memchr(s, 'a', 1);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 6: Character at beginning of memory area
    s = "abcde";
    result_ft = ft_memchr(s, 'a', 5);
    result_std = memchr(s, 'a', 5);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 7: Character at end of memory area
    s = "abcde";
    result_ft = ft_memchr(s, 'e', 5);
    result_std = memchr(s, 'e', 5);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 9: Character with value greater than 127
    unsigned char data1[] = {0xFF, 0xFE, 0xFD};
    result_ft = ft_memchr(data1, 0xFE, 3);
    result_std = memchr(data1, 0xFE, 3);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 10: Binary data
    unsigned char data2[] = {0x00, 0x01, 0x02, 0x03, 0x04};
    result_ft = ft_memchr(data2, 0x03, 5);
    result_std = memchr(data2, 0x03, 5);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 11: Large n value
    s = "This is a test string for ft_memchr.";
    result_ft = ft_memchr(s, 's', 1000);
    result_std = memchr(s, 's', 1000);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 12: Search for character not in memory area with large n
    s = "Another test string.";
    result_ft = ft_memchr(s, 'z', 1000);
    result_std = memchr(s, 'z', 1000);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 13: n is larger than the string length
    s = "Short string";
    result_ft = ft_memchr(s, 'g', 50);
    result_std = memchr(s, 'g', 50);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 14: n is zero, character is null terminator
    s = "hello";
    result_ft = ft_memchr(s, '\0', 0);
    result_std = memchr(s, '\0', 0);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);
}

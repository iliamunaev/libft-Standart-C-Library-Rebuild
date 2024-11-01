#include "../test42lib/test42lib.h"

int     test_ft_strncmp(void)
{
    // Test 1: Equal strings, full comparison
    ASSERT_STRNCMP("hello", "hello", 5, 0);

    // Test 2: Different strings, first differing character
    ASSERT_STRNCMP("hello", "hellp", 5, 'o' - 'p');

    // Test 3: One string shorter than the other
    ASSERT_STRNCMP("hello", "hel", 5, 'l');

    // Test 4: Case sensitivity
    ASSERT_STRNCMP("Hello", "hello", 5, 'H' - 'h');

    // Test 5: n shorter than string length
    ASSERT_STRNCMP("hello", "hellp", 3, 0);

    // Test 6: Empty string comparison
    ASSERT_STRNCMP("", "", 5, 0);
    ASSERT_STRNCMP("hello", "", 5, 'h');
    ASSERT_STRNCMP("", "hello", 5, -'h');

    return (0);
}

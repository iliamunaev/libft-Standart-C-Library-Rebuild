#include <string.h>   // For memset and strcpy
#include "../imtest42/imtest42.h"
#include "../libft.h"

void test_ft_strlcpy(void) {
    char dest[10];
    size_t ret;

    // Test 1: Basic Copy
    memset(dest, 'A', sizeof(dest));  // Initialize with 'A' to check overwrite behavior
    ret = ft_strlcpy(dest, "Hello", sizeof(dest));
    IM_ASSERT_STR_EQUAL(dest, "Hello"); // Expected content
    IM_ASSERT_INT_EQUAL(ret, 5);               // Expected length of "Hello"

    // Test 2: Size Zero (no space in destination)
    strcpy(dest, "Existing");  // Fill with initial content to verify no changes occur
    ret = ft_strlcpy(dest, "Hello", 0);
    IM_ASSERT_STR_EQUAL(dest, "Existing"); // Expected to remain unchanged
    IM_ASSERT_INT_EQUAL(ret, 5);                  // Expected length of "Hello"

    // Test 3: Size Less Than Source Length (should truncate)
    memset(dest, 0, sizeof(dest));  // Clear buffer
    ret = ft_strlcpy(dest, "HelloWorld", 5);
    IM_ASSERT_STR_EQUAL(dest, "Hell"); // Expected truncated content
    IM_ASSERT_INT_EQUAL(ret, 10);             // Expected full length of "HelloWorld"

    // Test 4: Exact Buffer Size (includes null terminator)
    memset(dest, 0, sizeof(dest));  // Clear buffer
    ret = ft_strlcpy(dest, "Hello", 6);
    IM_ASSERT_STR_EQUAL(dest, "Hello"); // Expected content
    IM_ASSERT_INT_EQUAL(ret, 5);               // Expected length of "Hello"

    // Test 5: Empty Source String
    memset(dest, 0, sizeof(dest));  // Clear buffer
    ret = ft_strlcpy(dest, "", sizeof(dest));
    IM_ASSERT_STR_EQUAL(dest, ""); // Expected empty string
    IM_ASSERT_INT_EQUAL(ret, 0);          // Expected length of ""

    // Test 6: Empty Destination Buffer
    memset(dest, 0, sizeof(dest));  // Clear buffer
    ret = ft_strlcpy(dest, "Hello", 0); // Buffer size is zero
    IM_ASSERT_STR_EQUAL(dest, "");  // Expected content remains unchanged
    IM_ASSERT_INT_EQUAL(ret, 5);           // Expected length of "Hello"
}

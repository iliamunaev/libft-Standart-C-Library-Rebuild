#include <stdio.h>
#include <string.h>
#include "../imtest42/imtest42.h"
#include "../libft.h"

void test_ft_strlcat(void) {
    char dest[20];
    size_t ret;

    // Test 1: Basic Append
    strcpy(dest, "Hello");
    ret = ft_strlcat(dest, " World", sizeof(dest));
    IM_ASSERT_STR_EQUAL(dest, "Hello World");  // Expected buffer content
    IM_ASSERT_INT_EQUAL(ret, 11);              // Expected return value (length of "Hello World")

    // Test 2: Size Zero (no space in buffer)
    strcpy(dest, "Hello");
    ret = ft_strlcat(dest, " World", 0);
    IM_ASSERT_STR_EQUAL(dest, "Hello");        // dest should remain unchanged
    IM_ASSERT_INT_EQUAL(ret, 11);              // Expected return value (len of "Hello" + len of " World")

    // Test 3: Size Less Than dest Length (no concatenation should occur)
    strcpy(dest, "Hello");
    ret = ft_strlcat(dest, " World", 3);
    IM_ASSERT_STR_EQUAL(dest, "Hello");        // dest should remain unchanged
    IM_ASSERT_INT_EQUAL(ret, 9);              // Expected return value (total len of "Hello World")

    // Test 4: Exact Buffer Size
    strcpy(dest, "Hello");
    ret = ft_strlcat(dest, " World", 12);
    IM_ASSERT_STR_EQUAL(dest, "Hello World");  // Expected buffer content
    IM_ASSERT_INT_EQUAL(ret, 11);              // Expected return value (len of "Hello World")

    // Test 5: Insufficient Space (only part of src can fit)
    strcpy(dest, "Hello");
    ret = ft_strlcat(dest, " World", 10);
    IM_ASSERT_STR_EQUAL(dest, "Hello Wor");    // Expected truncated result
    IM_ASSERT_INT_EQUAL(ret, 11);              // Expected return value (len of "Hello World")

    // Test 6: Empty Source String (no change to dest)
    strcpy(dest, "Hello");
    ret = ft_strlcat(dest, "", sizeof(dest));
    IM_ASSERT_STR_EQUAL(dest, "Hello");        // dest should remain unchanged
    IM_ASSERT_INT_EQUAL(ret, 5);               // Expected return value (len of "Hello")

    // Test 7: Empty Destination String (copy src into dest)
    strcpy(dest, "");
    ret = ft_strlcat(dest, "Hello", sizeof(dest));
    IM_ASSERT_STR_EQUAL(dest, "Hello");        // Expected result in dest
    IM_ASSERT_INT_EQUAL(ret, 5);               // Expected return value (len of "Hello")
}

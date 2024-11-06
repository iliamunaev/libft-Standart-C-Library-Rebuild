#include <string.h>   // For comparison with the standard memcpy
#include <stdlib.h>   // For malloc and free

#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_memcpy(void)
{
    char src[100];
    char dest1[100];
    char dest2[100];

    // Initialize src with known data
    memset(src, 'A', sizeof(src));

    // Test 1: Basic Copy
    memcpy(dest1, src, 50);
    ft_memcpy(dest2, src, 50);
    IM_ASSERT_MEM_EQUAL(dest1, dest2, 50);

    // Test 2: Zero Bytes
    memcpy(dest1, src, 0);
    ft_memcpy(dest2, src, 0);
    // No changes should be made to dest1 and dest2

    // Test 3: Full Buffer Copy
    memcpy(dest1, src, sizeof(src));
    ft_memcpy(dest2, src, sizeof(src));
    IM_ASSERT_MEM_EQUAL(dest1, dest2, sizeof(src));

    // Test 4: Overlapping Areas (undefined behavior)
    // Avoid testing overlapping memory areas as behavior is undefined.

    // Test 5: Null Pointers with n = 0
    ft_memcpy(NULL, NULL, 0);  // Should not crash

    // Test 6: Return Value
    char *ret1 = memcpy(dest1, src, 10);
    char *ret2 = ft_memcpy(dest2, src, 10);
    IM_ASSERT_PTR_EQUAL(ret1, dest1);
    IM_ASSERT_PTR_EQUAL(ret2, dest2);
}

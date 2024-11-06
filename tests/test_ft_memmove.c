#include <string.h>   // For comparison with the standard memmove
#include <stdlib.h>   // For malloc and free

#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_memmove(void)
{
    char buffer1[100];
    char buffer2[100];
    char *src;
    char *dest1;
    char *dest2;

    // Initialize buffer with known data
    memset(buffer1, 'A', sizeof(buffer1));
    memcpy(buffer2, buffer1, sizeof(buffer1));

    // Test 1: Basic Copy without Overlap
    src = buffer1;
    dest1 = buffer1 + 20;
    dest2 = buffer2 + 20;
    memmove(dest1, src, 30);
    ft_memmove(dest2, src, 30);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

    // Test 2: Overlapping Regions (dest < src)
    src = buffer1 + 10;
    dest1 = buffer1;
    dest2 = buffer2;
    memmove(dest1, src, 50);
    ft_memmove(dest2, src, 50);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

    // Test 3: Overlapping Regions (dest > src)
    src = buffer1;
    dest1 = buffer1 + 10;
    dest2 = buffer2 + 10;
    memmove(dest1, src, 50);
    ft_memmove(dest2, src, 50);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

    // Test 4: Zero Bytes
    memmove(buffer1, buffer1 + 5, 0);
    ft_memmove(buffer2, buffer2 + 5, 0);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

    // Test 5: Null Pointers with n = 0
    ft_memmove(NULL, NULL, 0);  // Should not crash

    // Test 6: Self-Copy
    memmove(buffer1, buffer1, sizeof(buffer1));
    ft_memmove(buffer2, buffer2, sizeof(buffer2));
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));
}

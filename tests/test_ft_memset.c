#include <string.h> // For comparison with the standard memset
#include <stdlib.h> // For malloc and free

#include "../imtest42/imtest42.h"
#include "tests.h"
/*
void	test_ft_memset(void)
{
    char    buffer1[50];
    char    buffer2[50];
    void    *result_ft;
    void    *result_std;

    // Test 1: Basic usage
    memset(buffer1, 'A', 10);
    ft_memset(buffer2, 'A', 10);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, 10);

    // Test 2: Zero bytes
    memset(buffer1, 'B', 0);
    ft_memset(buffer2, 'B', 0);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, 0);

    // Test 3: Entire buffer
    memset(buffer1, 'C', sizeof(buffer1));
    ft_memset(buffer2, 'C', sizeof(buffer2));
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

    // Test 4: Return value
    result_std = memset(buffer1, 'D', 5);
    result_ft = ft_memset(buffer2, 'D', 5);
    IM_ASSERT_PTR_EQUAL(buffer1, result_std);
    IM_ASSERT_PTR_EQUAL(buffer2, result_ft);

    // Test 5: Non-printable characters
    memset(buffer1, '\n', 5);
    ft_memset(buffer2, '\n', 5);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, 5);

    // Test 6: Negative value for 'c' (should be converted to unsigned char)
    memset(buffer1, -1, 5);
    ft_memset(buffer2, -1, 5);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, 5);

    // Test 7: Large value for 'c' (should be converted to unsigned char)
    memset(buffer1, 300, 5);
    ft_memset(buffer2, 300, 5);
    IM_ASSERT_MEM_EQUAL(buffer1, buffer2, 5);
}
*/
#include <stdio.h>
#include <string.h>

void test_ft_memset() {
    char buffer1[10] = "abcdefghi";
    char buffer2[10] = "abcdefghi";

    ft_memset(buffer1, 'x', 5);
    memset(buffer2, 'x', 5);

    if (memcmp(buffer1, buffer2, 10) == 0)
        printf("PASS: ft_memset works as expected\n");
    else
        printf("FAIL: ft_memset does not match standard memset\n");
}

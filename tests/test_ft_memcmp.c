#include <stdio.h>
#include <string.h>
#include "../imtest42/imtest42.h"
#include "tests.h"

void test_ft_memcmp(void)
{
    int ret_ft;
    int ret_std;
    const char *s1;
    const char *s2;
    void *result;

    // Test 1: Identical memory areas
    printf("Test 1: Identical memory areas\n");
    s1 = "hello world";
    s2 = "hello world";
    ret_ft = ft_memcmp(s1, s2, 11);
    ret_std = memcmp(s1, s2, 11);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 2: Different memory areas
    printf("Test 2: Different memory areas\n");
    s1 = "hello world";
    s2 = "hello there";
    ret_ft = ft_memcmp(s1, s2, 11);
    ret_std = memcmp(s1, s2, 11);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 3: Partial comparison
    printf("Test 3: Partial comparison\n");
    s1 = "hello world";
    s2 = "hello there";
    ret_ft = ft_memcmp(s1, s2, 5);
    ret_std = memcmp(s1, s2, 5);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 4: n is zero
    printf("Test 4: n is zero\n");
    s1 = "abc";
    s2 = "def";
    ret_ft = ft_memcmp(s1, s2, 0);
    ret_std = memcmp(s1, s2, 0);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 5: Empty memory areas
    printf("Test 5: Empty memory areas\n");
    s1 = "";
    s2 = "";
    ret_ft = ft_memcmp(s1, s2, 1);
    ret_std = memcmp(s1, s2, 1);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 6: Binary data
    printf("Test 6: Binary data\n");
    unsigned char data1[] = {0x00, 0x01, 0x02, 0x03};
    unsigned char data2[] = {0x00, 0x01, 0x02, 0x04};
    ret_ft = ft_memcmp(data1, data2, 4);
    ret_std = memcmp(data1, data2, 4);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 7: Non-ASCII characters
    printf("Test 7: Non-ASCII characters\n");
    s1 = "héllo";
    s2 = "héllö";
    ret_ft = ft_memcmp(s1, s2, 5);
    ret_std = memcmp(s1, s2, 5);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 8: Large n value
    printf("Test 8: Large n value\n");
    s1 = "test";
    s2 = "test";
    ret_ft = ft_memcmp(s1, s2, 1000);
    ret_std = memcmp(s1, s2, 1000);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 9: One memory area is prefix of the other
    printf("Test 9: One memory area is prefix of the other\n");
    s1 = "hello";
    s2 = "hello world";
    ret_ft = ft_memcmp(s1, s2, 11);
    ret_std = memcmp(s1, s2, 11);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 10: Difference at last byte
    printf("Test 10: Difference at last byte\n");
    s1 = "abcd";
    s2 = "abce";
    ret_ft = ft_memcmp(s1, s2, 4);
    ret_std = memcmp(s1, s2, 4);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 11: Comparing with zero bytes
    printf("Test 11: Comparing with zero bytes\n");
    s1 = "any string";
    s2 = "any other string";
    ret_ft = ft_memcmp(s1, s2, 0);
    ret_std = memcmp(s1, s2, 0);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 12: Comparing binary data with zero difference
    printf("Test 12: Comparing binary data with zero difference\n");
    unsigned char data3[] = {0xFF, 0xFE, 0xFD};
    unsigned char data4[] = {0xFF, 0xFE, 0xFD};
    ret_ft = ft_memcmp(data3, data4, 3);
    ret_std = memcmp(data3, data4, 3);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 13: Comparing binary data with difference
    printf("Test 13: Comparing binary data with difference\n");
    unsigned char data5[] = {0x00, 0x01, 0x02};
    unsigned char data6[] = {0x00, 0x01, 0x03};
    ret_ft = ft_memcmp(data5, data6, 3);
    ret_std = memcmp(data5, data6, 3);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);

    // Test 14: n is larger than the length of s1 and s2
    printf("Test 14: n is larger than the length of s1 and s2\n");
    s1 = "short";
    s2 = "short";
    ret_ft = ft_memcmp(s1, s2, 50);
    ret_std = memcmp(s1, s2, 50);
    IM_ASSERT_INT_EQUAL(ret_ft, ret_std);
/*
    // Test 15: Both parameters are NULL and size is non-zero
    printf("Test 15: Both dest and src are NULL with non-zero size\n");
    result = ft_memcpy(NULL, NULL, 10);
    IM_ASSERT_PTR_NULL(result);
*/
}

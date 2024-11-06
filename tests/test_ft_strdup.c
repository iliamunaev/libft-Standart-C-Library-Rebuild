#include "../imtest42/imtest42.h"
#include "tests.h"
#include <string.h>   // For comparison with the standard strdup
#include <stdlib.h>   // For malloc and free
//#include <errno.h>    // For errno

void test_ft_strdup(void)
{
    const char *str;
    char *dup_ft;
    char *dup_std;

    // Test 1: Duplicate a normal string
    str = "Hello, World!";
    dup_ft = ft_strdup(str);
    dup_std = strdup(str);
    IM_ASSERT_PTR_NOT_NULL(dup_ft);
    IM_ASSERT_PTR_NOT_NULL(dup_std);
    IM_ASSERT_STR_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);

    // Test 2: Duplicate an empty string
    str = "";
    dup_ft = ft_strdup(str);
    dup_std = strdup(str);
    IM_ASSERT_PTR_NOT_NULL(dup_ft);
    IM_ASSERT_PTR_NOT_NULL(dup_std);
    IM_ASSERT_STR_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);

    // Test 3: Duplicate a string with special characters
    str = "Line1\nLine2\tTabbed";
    dup_ft = ft_strdup(str);
    dup_std = strdup(str);
    IM_ASSERT_PTR_NOT_NULL(dup_ft);
    IM_ASSERT_PTR_NOT_NULL(dup_std);
    IM_ASSERT_STR_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);

    // Test 4: Duplicate a very long string
    char *long_str = malloc(101);
    memset(long_str, 'A', 100);
    long_str[10000] = '\0';
    dup_ft = ft_strdup(long_str);
    dup_std = strdup(long_str);
    IM_ASSERT_PTR_NOT_NULL(dup_ft);
    IM_ASSERT_PTR_NOT_NULL(dup_std);
    IM_ASSERT_STR_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);
    free(long_str);

    // Test 5: Modify original string after duplication
    char original_str[] = "Original";
    dup_ft = ft_strdup(original_str);
    IM_ASSERT_PTR_NOT_NULL(dup_ft);
    strcpy(original_str, "Changed");
    IM_ASSERT_STR_NOT_EQUAL(dup_ft, original_str);
    free(dup_ft);

    // Test 6: Modify duplicate string
    char *modifiable_dup = ft_strdup("Modify me");
    IM_ASSERT_PTR_NOT_NULL(modifiable_dup);
    strcpy(modifiable_dup, "Modified");
    IM_ASSERT_STR_EQUAL(modifiable_dup, "Modified");
    free(modifiable_dup);
}

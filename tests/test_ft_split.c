#include <string.h>
#include <stdlib.h>
#include "../imtest42/imtest42.h"
#include "../libft.h"

void test_ft_split(void)
{
    char **result;

    printf("\nTest 1: Basic split\n");
    result = ft_split("hello world example", ' ');
    IM_ASSERT_STR_EQUAL(result[0], "hello");
    IM_ASSERT_STR_EQUAL(result[1], "world");
    IM_ASSERT_STR_EQUAL(result[2], "example");
    IM_ASSERT_TRUE(result[3] == NULL); // Expect NULL as the last element
    free(result[0]); free(result[1]); free(result[2]); free(result[3]); free(result);

    printf("\nTest 2: Consecutive delimiters\n");
    result = ft_split("hello,,world,,example", ',');
    IM_ASSERT_STR_EQUAL(result[0], "hello");
    IM_ASSERT_STR_EQUAL(result[1], "world");
    IM_ASSERT_STR_EQUAL(result[2], "example");
    IM_ASSERT_TRUE(result[3] == NULL);
    free(result[0]); free(result[1]); free(result[2]); free(result[3]); free(result);

    printf("\nTest 3: Delimiter at the start\n");
    result = ft_split(",hello,world,example", ',');
    IM_ASSERT_STR_EQUAL(result[0], "hello");
    IM_ASSERT_STR_EQUAL(result[1], "world");
    IM_ASSERT_STR_EQUAL(result[2], "example");
    IM_ASSERT_TRUE(result[3] == NULL);
    free(result[0]); free(result[1]); free(result[2]); free(result[3]); free(result);

    printf("\nTest 4: Delimiter at the end\n");
    result = ft_split("hello,world,example,", ',');
    IM_ASSERT_STR_EQUAL(result[0], "hello");
    IM_ASSERT_STR_EQUAL(result[1], "world");
    IM_ASSERT_STR_EQUAL(result[2], "example");
    IM_ASSERT_TRUE(result[3] == NULL);
    free(result[0]); free(result[1]); free(result[2]); free(result[3]); free(result);

    printf("\nTest 5: Delimiter at both ends\n");
    result = ft_split(",hello,world,example,", ',');
    IM_ASSERT_STR_EQUAL(result[0], "hello");
    IM_ASSERT_STR_EQUAL(result[1], "world");
    IM_ASSERT_STR_EQUAL(result[2], "example");
    IM_ASSERT_TRUE(result[3] == NULL);
    free(result[0]); free(result[1]); free(result[2]); free(result[3]); free(result);

    printf("\nTest 6: Single word with no delimiters\n");
    result = ft_split("hello", ',');
    IM_ASSERT_STR_EQUAL(result[0], "hello");
    IM_ASSERT_TRUE(result[1] == NULL);
    free(result[0]); free(result[1]); free(result);

    printf("\nTest 7: Empty input string\n");
    result = ft_split("", ',');
    IM_ASSERT_TRUE(result[0] == NULL);
    free(result);

    printf("\nTest 8: String with only delimiters\n");
    result = ft_split(",,,,", ',');
    IM_ASSERT_TRUE(result[0] == NULL);
    free(result);
}

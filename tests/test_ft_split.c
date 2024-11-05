#include "../test42lib/test42lib.h"
#include "tests.h"

static void free_split_result(char **result) {
    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            free(result[i]);
        }
        free(result);
    }
}

void test_ft_split(void)
{
    // Basic test
    const char *expected1[] = {"hive", "42"};
    char **result1 = ft_split("hive 42", ' ');
    ASSERT_SPLIT_RESULT(result1, expected1, 2);
    free_split_result(result1);

    // Empty string
    const char *expected2[] = {NULL};
    char **result2 = ft_split("", ' ');
    ASSERT_SPLIT_RESULT(result2, expected2, 0);
    free_split_result(result2);

    // String with no delimiters
    const char *expected3[] = {"hive42"};
    char **result3 = ft_split("hive42", ' ');
    ASSERT_SPLIT_RESULT(result3, expected3, 1);
    free_split_result(result3);

    // Only delimiters
    const char *expected4[] = {NULL};
    char **result4 = ft_split(":::::", ':');
    ASSERT_SPLIT_RESULT(result4, expected4, 0);
    free_split_result(result4);

    // Continuous delimiters
    const char *expected5[] = {"Finland", "Helsinki", "42"};
    char **result5 = ft_split("Finland+++Helsinki+42", '+');
    ASSERT_SPLIT_RESULT(result5, expected5, 3);
    free_split_result(result5);

    // Delimiters at start and end
    const char *expected6[] = {"Finland", "Helsinki", "42"};
    char **result6 = ft_split("!!Finland!Helsinki!42!", '!');
    ASSERT_SPLIT_RESULT(result6, expected6, 3);
    free_split_result(result6);

    // Single character, non-delimiter
    const char *expected7[] = {"a"};
    char **result7 = ft_split("a", 'z');
    ASSERT_SPLIT_RESULT(result7, expected7, 1);
    free_split_result(result7);

    // Single character, delimiter
    const char *expected8[] = {NULL};
    char **result8 = ft_split("@", '@');
    ASSERT_SPLIT_RESULT(result8, expected8, 0);
    free_split_result(result8);

    // Mixed single and continuous delimiters
    const char *expected9[] = {"1", "2", "3", "4", "5"};
    char **result9 = ft_split("1:2::3:::4::::5", ':');
    ASSERT_SPLIT_RESULT(result9, expected9, 5);
    free_split_result(result9);

    // Long string with delimiters
    const char *expected10[] = {"to", "be", "or", "not", "to", "be"};
    char **result10 = ft_split("to@@be@@or@@not@to@@@@be", '@');
    ASSERT_SPLIT_RESULT(result10, expected10, 6);
    free_split_result(result10);
}

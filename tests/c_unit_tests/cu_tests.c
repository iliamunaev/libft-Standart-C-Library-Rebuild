#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../../libft.h"

// Test cases for Part 1 - Libc functions

void test_ft_isalpha(void) {
    CU_ASSERT_TRUE(ft_isalpha('a'));
    CU_ASSERT_TRUE(ft_isalpha('Z'));
    CU_ASSERT_TRUE(ft_isalpha('A'));
    CU_ASSERT_TRUE(ft_isalpha('z'));
    CU_ASSERT_FALSE(ft_isalpha('1'));
    CU_ASSERT_FALSE(ft_isalpha('@'));
    CU_ASSERT_FALSE(ft_isalpha('['));
    CU_ASSERT_FALSE(ft_isalpha('`'));
    CU_ASSERT_FALSE(ft_isalpha('\n'));
}

void test_ft_isdigit(void) {
    CU_ASSERT_TRUE(ft_isdigit('0'));
    CU_ASSERT_TRUE(ft_isdigit('5'));
    CU_ASSERT_TRUE(ft_isdigit('9'));
    CU_ASSERT_FALSE(ft_isdigit('a'));
    CU_ASSERT_FALSE(ft_isdigit('/'));
    CU_ASSERT_FALSE(ft_isdigit(':'));
    CU_ASSERT_FALSE(ft_isdigit(' '));
}

void test_ft_strlen(void) {
    CU_ASSERT_EQUAL(ft_strlen("hello"), 5);
    CU_ASSERT_EQUAL(ft_strlen(""), 0);
    CU_ASSERT_EQUAL(ft_strlen(" "), 1);
    CU_ASSERT_EQUAL(ft_strlen("A long string for testing purposes"), 34);
    CU_ASSERT_EQUAL(ft_strlen("😀"), 4);  // Unicode character length in bytes
    CU_ASSERT_EQUAL(ft_strlen("©"), 2);
}

void test_ft_memset(void) {
    char buffer[10];
    ft_memset(buffer, 'A', 10);
    for (int i = 0; i < 10; i++) {
        CU_ASSERT_EQUAL(buffer[i], 'A');
    }
    ft_memset(buffer, 'B', 0);
    CU_ASSERT_EQUAL(buffer[0], 'A');
}

void test_ft_bzero(void) {
    char buffer[10] = "123456789";
    ft_bzero(buffer, 5);
    for (int i = 0; i < 5; i++) {
        CU_ASSERT_EQUAL(buffer[i], 0);
    }
    CU_ASSERT_EQUAL(buffer[5], '6');
    ft_bzero(buffer, 0);
    CU_ASSERT_EQUAL(buffer[5], '6');
}

void test_ft_memcpy(void) {
    char src[] = "abcdef";
    char dest[7];
    ft_memcpy(dest, src, 7);
    CU_ASSERT_STRING_EQUAL(dest, src);
    ft_memcpy(dest, "xyz", 4);
    CU_ASSERT_STRING_EQUAL(dest, "xyz");
}

void test_ft_memmove(void) {
    char buffer[] = "123456789";
    ft_memmove(buffer + 2, buffer, 5);
    CU_ASSERT_STRING_EQUAL(buffer, "121234589");
    ft_memmove(buffer, buffer + 2, 5);
    CU_ASSERT_STRING_EQUAL(buffer, "123454589");
}

void test_ft_strlcpy(void) {
    char dest[10];
    size_t len = ft_strlcpy(dest, "hello", 10);
    CU_ASSERT_STRING_EQUAL(dest, "hello");
    CU_ASSERT_EQUAL(len, 5);
    len = ft_strlcpy(dest, "world", 0);
    CU_ASSERT_EQUAL(len, 5);
}

void test_ft_strlcat(void) {
    char dest[10] = "hi";
    size_t len = ft_strlcat(dest, " there", 10);
    CU_ASSERT_STRING_EQUAL(dest, "hi there");
    CU_ASSERT_EQUAL(len, 8);

    len = ft_strlcat(dest, "!", 0);
    CU_ASSERT_STRING_EQUAL(dest, "hi there");
    CU_ASSERT_EQUAL(len, 9);

    char dest2[10] = "hi";
    len = ft_strlcat(dest2, " there", 5);
    CU_ASSERT_STRING_EQUAL(dest2, "hi t");
    CU_ASSERT_EQUAL(len, 8);

    char dest3[6] = "hi";
    len = ft_strlcat(dest3, " there", 6);
    CU_ASSERT_STRING_EQUAL(dest3, "hi th");
    CU_ASSERT_EQUAL(len, 8);
}

void test_ft_strchr(void) {
    CU_ASSERT_PTR_EQUAL(ft_strchr("hello", 'e'), "hello" + 1);
    CU_ASSERT_PTR_NULL(ft_strchr("hello", 'z'));
    CU_ASSERT_PTR_EQUAL(ft_strchr("hello", '\0'), "hello" + 5);
}

void test_ft_strrchr(void) {
    CU_ASSERT_PTR_EQUAL(ft_strrchr("hello", 'l'), "hello" + 3);
    CU_ASSERT_PTR_NULL(ft_strrchr("hello", 'z'));
    CU_ASSERT_PTR_EQUAL(ft_strrchr("hello", '\0'), "hello" + 5);
}

void test_ft_strncmp(void) {
    CU_ASSERT_EQUAL(ft_strncmp("hello", "hello", 5), 0);
    CU_ASSERT_NOT_EQUAL(ft_strncmp("hello", "world", 5), 0);
    CU_ASSERT_EQUAL(ft_strncmp("hello", "he", 2), 0);
    CU_ASSERT_EQUAL(ft_strncmp("he", "hello", 2), 0);
}

void test_ft_memchr(void) {
    char arr[] = {0, 1, 2, 3, 4, 5};
    CU_ASSERT_PTR_EQUAL(ft_memchr(arr, 3, 6), &arr[3]);
    CU_ASSERT_PTR_NULL(ft_memchr(arr, 6, 6));
}

void test_ft_memcmp(void) {
    char arr1[] = {0, 1, 2, 3, 4};
    char arr2[] = {0, 1, 2, 3, 5};
    CU_ASSERT_EQUAL(ft_memcmp(arr1, arr1, 5), 0);
    CU_ASSERT_NOT_EQUAL(ft_memcmp(arr1, arr2, 5), 0);
    CU_ASSERT_EQUAL(ft_memcmp(arr1, arr2, 3), 0);
}

void test_ft_atoi(void) {
    CU_ASSERT_EQUAL(ft_atoi("42"), 42);
    CU_ASSERT_EQUAL(ft_atoi("   -42"), -42);
    CU_ASSERT_EQUAL(ft_atoi("4193 with words"), 4193);
    CU_ASSERT_EQUAL(ft_atoi("words and 987"), 0);
    CU_ASSERT_EQUAL(ft_atoi("-2147483648"), -2147483648);
    CU_ASSERT_EQUAL(ft_atoi("2147483647"), 2147483647);
}

void test_ft_substr(void) {
    char *sub = ft_substr("hello", 1, 3);
    CU_ASSERT_STRING_EQUAL(sub, "ell");
    free(sub);
    sub = ft_substr("hello", 10, 3);
    CU_ASSERT_STRING_EQUAL(sub, "");
    free(sub);
}

void test_ft_strjoin(void) {
    char *joined = ft_strjoin("hello", " world");
    CU_ASSERT_STRING_EQUAL(joined, "hello world");
    free(joined);
    joined = ft_strjoin("", "world");
    CU_ASSERT_STRING_EQUAL(joined, "world");
    free(joined);
}

void test_ft_strtrim(void) {
    char *trimmed = ft_strtrim("  hello  ", " ");
    CU_ASSERT_STRING_EQUAL(trimmed, "hello");
    free(trimmed);
    trimmed = ft_strtrim("   ", " ");
    CU_ASSERT_STRING_EQUAL(trimmed, "");
    free(trimmed);
}

void test_ft_split(void) {
    char **result = ft_split("a,b,c", ',');
    CU_ASSERT_STRING_EQUAL(result[0], "a");
    CU_ASSERT_STRING_EQUAL(result[1], "b");
    CU_ASSERT_STRING_EQUAL(result[2], "c");
    CU_ASSERT_PTR_NULL(result[3]);
    for (int i = 0; result[i]; i++) free(result[i]);
    free(result);
}

void test_ft_itoa(void) {
    char *str = ft_itoa(-1234);
    CU_ASSERT_STRING_EQUAL(str, "-1234");
    free(str);
    str = ft_itoa(0);
    CU_ASSERT_STRING_EQUAL(str, "0");
    free(str);
}

static char map_function(unsigned int i, char c) {
    return c + i;
}

void test_ft_strmapi(void) {
    char *result = ft_strmapi("abc", map_function);
    CU_ASSERT_STRING_EQUAL(result, "ace");
    free(result);
}

// Register tests and run them
int main() {
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    CU_pSuite suite = CU_add_suite("Libft Test Suite", 0, 0);
    if (!suite) { CU_cleanup_registry(); return CU_get_error(); }

    // Add tests
    CU_add_test(suite, "test ft_isalpha", test_ft_isalpha);
    CU_add_test(suite, "test ft_isdigit", test_ft_isdigit);
    CU_add_test(suite, "test ft_strlen", test_ft_strlen);
    CU_add_test(suite, "test ft_memset", test_ft_memset);
    CU_add_test(suite, "test ft_bzero", test_ft_bzero);
    CU_add_test(suite, "test ft_memcpy", test_ft_memcpy);
    CU_add_test(suite, "test ft_memmove", test_ft_memmove);
    CU_add_test(suite, "test ft_strlcpy", test_ft_strlcpy);
    CU_add_test(suite, "test ft_strlcat", test_ft_strlcat);
    CU_add_test(suite, "test ft_strchr", test_ft_strchr);
    CU_add_test(suite, "test ft_strrchr", test_ft_strrchr);
    CU_add_test(suite, "test ft_strncmp", test_ft_strncmp);
    CU_add_test(suite, "test ft_memchr", test_ft_memchr);
    CU_add_test(suite, "test ft_memcmp", test_ft_memcmp);
    CU_add_test(suite, "test ft_atoi", test_ft_atoi);
    CU_add_test(suite, "test ft_substr", test_ft_substr);
    CU_add_test(suite, "test ft_strjoin", test_ft_strjoin);
    CU_add_test(suite, "test ft_strtrim", test_ft_strtrim);
    CU_add_test(suite, "test ft_split", test_ft_split);
    CU_add_test(suite, "test ft_itoa", test_ft_itoa);
    CU_add_test(suite, "test ft_strmapi", test_ft_strmapi);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return CU_get_error();
}

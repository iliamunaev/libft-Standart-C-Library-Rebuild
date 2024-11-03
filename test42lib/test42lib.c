#include "test42lib.h"
#include <stdio.h>
#include <string.h>

// Integer comparison
void ASSERT_EQUAL_INT(int expected, int actual)
{
    if (expected == actual)
        printf("PASS.\n");
    else
        printf("!-----FAIL-----!: (expected %d, got %d)\n", expected, actual);
}

// String comparison
void ASSERT_EQUAL_STR(const char *expected, const char *actual)
{
    if (strcmp(expected, actual) == 0)
        printf("PASS.\n");
    else
        printf("!-----FAIL-----!: (expected \"%s\", got \"%s\")\n", expected, actual);
}

// Character comparison
void ASSERT_EQUAL_CHAR(char expected, char actual)
{
    if (expected == actual)
        printf("PASS.\n");
    else
        printf("!-----FAIL-----!: (expected '%c', got '%c')\n", expected, actual);
}

// Null pointer check
void ASSERT_EQUAL_NULL(const void *ptr)
{
    if (ptr == NULL)
        printf("PASS.\n");
    else
        printf("!-----FAIL-----!: (expected NULL, got %p)\n", ptr);
}

// Memory comparison using a while loop
void ASSERT_EQUAL_MEM(const void *expected, const void *actual, size_t size)
{
    if (memcmp(expected, actual, size) == 0)
    {
        printf("PASS.\n");
    }
    else
    {
        printf("!-----FAIL-----!: (memory comparison failed)\n");
        const unsigned char *exp = expected;
        const unsigned char *act = actual;
        size_t i = 0;

        // Loop through each byte until a mismatch is found
        while (i < size)
        {
            if (exp[i] != act[i])
            {
                printf("Mismatch at byte %zu: expected 0x%02x, got 0x%02x\n", i, exp[i], act[i]);
                break;
            }
            i++;
        }
    }
}

// Range comparison using strncmp
void ASSERT_STRNCMP(const char *s1, const char *s2, size_t n, int expected)
{
    int result = strncmp(s1, s2, n);
    if ((result == 0 && expected == 0) || (result < 0 && expected < 0) || (result > 0 && expected > 0))
        printf("PASS.\n");
    else
        printf("!-----FAIL-----!: (expected %d, got %d)\n", expected, result);
}

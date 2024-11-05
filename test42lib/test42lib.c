#include "test42lib.h"


// Integer comparison
void    ASSERT_EQUAL_INT(int expected, int actual)
{
    if (expected == actual)
        printf("PASS: (expected %d, got %d)\n", expected, actual);
    else
        printf("!-----FAIL-----!: (expected %d, got %d)\n", expected, actual);
}

// nonzero return
void    ASSERT_RETURN_NONZERO(int ret)
{
    if (ret != 0 )
        printf("PASS: (expected 'NONZERO', got '%d')\n", ret);
    else
        printf("!-----FAIL-----!: (expected 'NONZERO', got %d)\n", ret);
}

// zero return
void    ASSERT_RETURN_ZERO(int ret)
{
    if (ret == 0 )
        printf("PASS: (expected 'ZERO', got '%d')\n", ret);
    else
        printf("!-----FAIL-----!: (expected 'ZERO', got %d)\n", ret);
}

// String comparison
void ASSERT_EQUAL_STR(const char *expected, const char *actual)
{
    if (strcmp(expected, actual) == 0)
        printf("PASS: (expected \"%s\", got \"%s\")\n", expected, actual);
    else
        printf("!-----FAIL-----!: (expected \"%s\", got \"%s\")\n", expected, actual);
}

// Character comparison
void ASSERT_EQUAL_CHAR(char expected, char actual)
{
    if (expected == actual)
        printf("PASS: expected '%c', actual '%c'\n", expected, actual);
    else
        printf("!-----FAIL-----!: expected '%c', got '%c'\n", expected, actual);
}

// Pointer comparison
void ASSERT_EQUAL_PTR(const void *expected, const void *actual)
{
    if (expected == actual)
        printf("PASS: expected '%p', got '%p'\n", expected, actual);
    else
        printf("!-----FAIL-----!: expected '%p', got '%p'\n", expected, actual);
}

// Null pointer check
void ASSERT_EQUAL_NULL(const void *ptr)
{
    if (ptr == NULL)
        printf("PASS: (expected NULL, got NULL)\n");
    else
        printf("!-----FAIL-----!: (expected NULL, got %p)\n", ptr);
}

// Memory comparison using a while loop
void ASSERT_EQUAL_MEM(const void *expected, const void *actual, size_t size)
{
    if (memcmp(expected, actual, size) == 0)
    {
        printf("PASS: memory comparison successful\n");
    }
    else
    {
        printf("!-----FAIL-----!: memory comparison failed\n");
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

// File descriptor output comparision
void	FD_OUTPUT_TO_FILE(void (*func)(int fd), const char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
    {
        printf("Error creating file: %s", filename);
        return ;
    }

	// Redirect output to the file
    func(fd);
    close(fd);

	printf("Output saved to: '%s':\n", filename);
}

// Split string
void    ASSERT_SPLIT_RESULT(char **result, const char *expected[], int expected_count)
{
    int i = 0;

    // Check each substring
    while (i < expected_count)
    {
        ASSERT_EQUAL_STR(expected[i], result[i]);
        i++;
    }    
    // Check for NULL pointer at the end of the arr
    ASSERT_EQUAL_NULL(result[i]);
}

void ASSERT_EQUAL_INT_TO_CHAR(char *(*f)(int), int n, const char *expected)
{
    char *result = f(n); // Call the function with the integer n
    if (strcmp(result, expected) == 0)
        printf("PASS: (expected \"%s\", got \"%s\")\n", expected, result);
    else
        printf("!-----FAIL-----!: (expected \"%s\", got \"%s\")\n", expected, result);
    free(result);
}
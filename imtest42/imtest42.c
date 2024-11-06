#include "imtest42.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// String comparison for equality
void IM_ASSERT_STR_EQUAL(const char *expected, const char *actual) {
    // Check for null pointers
    if (expected == NULL || actual == NULL) {
        printf("!-----FAIL-----!: (One of the strings is NULL)\n");
        return;
    }

    // Check if the strings are equal
    if (strcmp(expected, actual) == 0) {
        printf("PASS: (expected: \"%s\", actual: \"%s\")\n", expected, actual);
    } else {
        printf("!-----FAIL-----!: (expected: \"%s\", actual: \"%s\")\n", expected, actual);
    }
}

// String comparison for inequality
void IM_ASSERT_STR_NOT_EQUAL(const char *expected, const char *actual) {
    // Check for null pointers
    if (expected == NULL || actual == NULL) {
        printf("!-----FAIL-----!: (One of the strings is NULL)\n");
        return;
    }

    // Check if the strings are not equal
    if (strcmp(expected, actual) != 0) {
        printf("PASS: (expected not equal to: \"%s\", actual: \"%s\")\n", expected, actual);
    } else {
        printf("!-----FAIL-----!: (expected not equal to: \"%s\", actual: \"%s\")\n", expected, actual);
    }
}

// Integer comparison for equality
void IM_ASSERT_INT_EQUAL(int expected, int actual) {
    if (expected == actual) {
        printf("PASS: (expected: %d, actual: %d)\n", expected, actual);
    } else {
        printf("!-----FAIL-----!: (expected: %d, actual: %d)\n", expected, actual);
    }
}

// Integer comparison for inequality
void IM_ASSERT_INT_NOT_EQUAL(int expected, int actual) {
    if (expected != actual) {
        printf("PASS: (expected not equal to: %d, actual: %d)\n", expected, actual);
    } else {
        printf("!-----FAIL-----!: (expected not equal to: %d, actual: %d)\n", expected, actual);
    }
}

// True value check
void IM_ASSERT_TRUE(int value) {
    if (value > 0) {
        printf("PASS: (value is greater than zero: %d)\n", value);
    } else {
        printf("!-----FAIL-----!: (expected greater than zero, got: %d)\n", value);
    }
}

// Non-zero return check
void IM_ASSERT_NONZERO(int ret) {
    if (ret != 0) {
        printf("PASS: (expected 'NONZERO', got '%d')\n", ret);
    } else {
        printf("!-----FAIL-----!: (expected 'NONZERO', got %d)\n", ret);
    }
}

// Zero return check
void IM_ASSERT_ZERO(int ret) {
    if (ret == 0) {
        printf("PASS: (expected 'ZERO', got '%d')\n", ret);
    } else {
        printf("!-----FAIL-----!: (expected 'ZERO', got %d)\n", ret);
    }
}

// Character comparison
void IM_ASSERT_CHAR_EQUAL(char expected, char actual) {
    if (expected == actual) {
        printf("PASS: expected '%c', got '%c'\n", expected, actual);
    } else {
        printf("!-----FAIL-----!: expected '%c', got '%c'\n", expected, actual);
    }
}

// Pointer comparison
void IM_ASSERT_PTR_EQUAL(const void *expected, const void *actual) {
    if (expected == actual) {
        printf("PASS: expected '%p', got '%p'\n", expected, actual);
    } else {
        printf("!-----FAIL-----!: expected '%p', got '%p'\n", expected, actual);
    }
}

// Null pointer check
void IM_ASSERT_PTR_NULL(const void *ptr) {
    if (ptr == NULL) {
        printf("PASS: (expected NULL, got %p)\n", ptr);
    } else {
        printf("!-----FAIL-----!: (expected NULL, got %p)\n", ptr);
    }
}

// Pointer not null check
void IM_ASSERT_PTR_NOT_NULL(const void *ptr) {
    if (ptr == NULL) {
        printf("!-----FAIL-----!: Pointer is NULL\n");
        exit(EXIT_FAILURE);
    } else {
        printf("PASS: Pointer is not NULL\n");
    }
}

// Memory comparison using a while loop
void IM_ASSERT_MEM_EQUAL(const void *expected, const void *actual, size_t size) {
    if (memcmp(expected, actual, size) == 0)
    {
        printf("PASS: expected '%p', got '%p'\n", expected, actual);
    } else {
        printf("!-----FAIL-----!: expected '%p', got '%p'\n", expected, actual);
        const unsigned char *exp = expected;
        const unsigned char *act = actual;
        size_t i = 0;

        // Loop through each byte until a mismatch is found
        while (i < size) {
            if (exp[i] != act[i]) {
                printf("Mismatch at byte %zu: expected 0x%02x, got 0x%02x\n", i, exp[i], act[i]);
                break;
            }
            i++;
        }
    }
}

// File descriptor output comparison
void IM_FD_OUTPUT_TO_FILE(void (*func)(int fd), const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error creating file: %s\n", filename);
        return;
    }

    // Redirect output to the file
    func(fd);
    close(fd);

    printf("Output saved to: '%s'\n", filename);
}

// Split string comparison
void IM_ASSERT_SPLIT_RESULT(char **result, const char *expected[], int expected_count) {
    int i = 0;

    // Check each substring
    while (i < expected_count) {
        IM_ASSERT_STR_EQUAL(expected[i], result[i]);
        i++;
    }
    // Check for NULL pointer at the end of the array
    IM_ASSERT_PTR_NULL(result[i]);
}

// Integer to string conversion comparison
void IM_ASSERT_INT_TO_STR_EQUAL(char *(*func)(int), int n, const char *expected) {
    char *result = func(n); // Call the function with the integer n
    if (strcmp(result, expected) == 0) {
        printf("PASS: (expected \"%s\", got \"%s\")\n", expected, result);
    } else {
        printf("!-----FAIL-----!: (expected \"%s\", got \"%s\")\n", expected, result);
    }
    free(result);
}

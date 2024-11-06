#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


#include "../../libft.h"

// ----- Start here ----- //

void	test_ft_isalpha(void)
{
	// Test lowercase alphabetic characters
	CU_ASSERT_TRUE(ft_isalpha('a'));
	CU_ASSERT_TRUE(ft_isalpha('m'));
	CU_ASSERT_TRUE(ft_isalpha('z'));

	// Test uppercase alphabetic characters
	CU_ASSERT_TRUE(ft_isalpha('A'));
	CU_ASSERT_TRUE(ft_isalpha('N'));
	CU_ASSERT_TRUE(ft_isalpha('Z'));

	// Test digits
	CU_ASSERT_FALSE(ft_isalpha('0'));
	CU_ASSERT_FALSE(ft_isalpha('5'));
	CU_ASSERT_FALSE(ft_isalpha('9'));

	// Test special characters
	CU_ASSERT_FALSE(ft_isalpha('@'));
	CU_ASSERT_FALSE(ft_isalpha('['));
	CU_ASSERT_FALSE(ft_isalpha('`'));
	CU_ASSERT_FALSE(ft_isalpha('{'));

	// Test whitespace characters
	CU_ASSERT_FALSE(ft_isalpha(' '));
	CU_ASSERT_FALSE(ft_isalpha('\n'));
	CU_ASSERT_FALSE(ft_isalpha('\t'));
}

void test_ft_isdigit(void)
{
	// Test digit characters
	CU_ASSERT_TRUE(ft_isdigit('0'));
	CU_ASSERT_TRUE(ft_isdigit('5'));
	CU_ASSERT_TRUE(ft_isdigit('9'));

	// Test lowercase alphabetic characters
	CU_ASSERT_FALSE(ft_isdigit('a'));
	CU_ASSERT_FALSE(ft_isdigit('m'));
	CU_ASSERT_FALSE(ft_isdigit('z'));

	// Test uppercase alphabetic characters
	CU_ASSERT_FALSE(ft_isdigit('A'));
	CU_ASSERT_FALSE(ft_isdigit('N'));
	CU_ASSERT_FALSE(ft_isdigit('Z'));

	// Test special characters
	CU_ASSERT_FALSE(ft_isdigit('@'));
	CU_ASSERT_FALSE(ft_isdigit('['));
	CU_ASSERT_FALSE(ft_isdigit('`'));
	CU_ASSERT_FALSE(ft_isdigit('{'));

	// Test whitespace characters
	CU_ASSERT_FALSE(ft_isdigit(' '));
	CU_ASSERT_FALSE(ft_isdigit('\n'));
	CU_ASSERT_FALSE(ft_isdigit('\t'));
}

void	test_ft_isalnum(void)
{
	// Test digits
	CU_ASSERT_TRUE(ft_isalnum('0'));
	CU_ASSERT_TRUE(ft_isalnum('5'));
	CU_ASSERT_TRUE(ft_isalnum('9'));

	// Test lowercase alphabetic characters
	CU_ASSERT_TRUE(ft_isalnum('a'));
	CU_ASSERT_TRUE(ft_isalnum('m'));
	CU_ASSERT_TRUE(ft_isalnum('z'));

	// Test uppercase alphabetic characters
	CU_ASSERT_TRUE(ft_isalnum('A'));
	CU_ASSERT_TRUE(ft_isalnum('N'));
	CU_ASSERT_TRUE(ft_isalnum('Z'));

	// Test non-alphanumeric characters (special characters)
	CU_ASSERT_FALSE(ft_isalnum('@'));
	CU_ASSERT_FALSE(ft_isalnum('['));
	CU_ASSERT_FALSE(ft_isalnum('`'));
	CU_ASSERT_FALSE(ft_isalnum('{'));

	// Test whitespace characters
	CU_ASSERT_FALSE(ft_isalnum(' '));
	CU_ASSERT_FALSE(ft_isalnum('\n'));
	CU_ASSERT_FALSE(ft_isalnum('\t'));
}

void test_ft_isascii(void)
{
	int c;

	// Test ASCII characters (0 to 127)
	for (c = 0; c <= 127; c++)
	{
		CU_ASSERT_TRUE(ft_isascii(c));
	}

	// Test values just outside the ASCII range
	CU_ASSERT_FALSE(ft_isascii(-1));   // Just below ASCII range
	CU_ASSERT_FALSE(ft_isascii(128));  // Just above ASCII range

	// Test negative values
	CU_ASSERT_FALSE(ft_isascii(-128));

	// Test values well outside the ASCII range
	CU_ASSERT_FALSE(ft_isascii(255));
	CU_ASSERT_FALSE(ft_isascii(1024));
}

void test_ft_isprint(void)
{
	int c;

	// Test printable characters (32 to 127)
	for (c = 32; c <= 127; c++)
	{
		CU_ASSERT_TRUE(ft_isprint(c));
	}

	// Test non-printable characters (0 to 31)
	for (c = 0; c < 32; c++)
	{
		CU_ASSERT_FALSE(ft_isprint(c));
	}

	// Test negative values
	CU_ASSERT_FALSE(ft_isprint(-1));
	CU_ASSERT_FALSE(ft_isprint(-128));
}

void	test_ft_strlen(void)
{
	// Test normal strings
	CU_ASSERT_EQUAL(ft_strlen("Hello, World!"), 13);
	CU_ASSERT_EQUAL(ft_strlen(""), 0);
	CU_ASSERT_EQUAL(ft_strlen("42"), 2);

	// Test special characters
	CU_ASSERT_EQUAL(ft_strlen("\n\t\r"), 3);
	CU_ASSERT_EQUAL(ft_strlen("foo\0bar"), 3);
}

void test_ft_memset(void)
{
	char	buffer1[50];
	char	buffer2[50];
	void	*result_ft;
	void	*result_std;

	// Test 1: Basic usage
	memset(buffer1, 'A', 10);
	ft_memset(buffer2, 'A', 10);
	CU_ASSERT_NSTRING_EQUAL(buffer1, buffer2, 10);

	// Test 2: Zero bytes
	memset(buffer1, 'B', 0);
	ft_memset(buffer2, 'B', 0);
	// No need to compare memory for zero bytes, but ensure buffers are unchanged
	CU_ASSERT_NSTRING_EQUAL(buffer1, buffer2, 0);

	// Test 3: Entire buffer
	memset(buffer1, 'C', sizeof(buffer1));
	ft_memset(buffer2, 'C', sizeof(buffer2));
	CU_ASSERT_NSTRING_EQUAL(buffer1, buffer2, sizeof(buffer1));

	// Test 4: Return value
	result_std = memset(buffer1, 'D', 5);
	result_ft = ft_memset(buffer2, 'D', 5);
	CU_ASSERT_PTR_EQUAL(buffer1, result_std);
	CU_ASSERT_PTR_EQUAL(buffer2, result_ft);

	// Test 5: Non-printable characters
	memset(buffer1, '\n', 5);
	ft_memset(buffer2, '\n', 5);
	CU_ASSERT_NSTRING_EQUAL(buffer1, buffer2, 5);

	// Test 6: Negative value for 'c'
	memset(buffer1, -1, 5);
	ft_memset(buffer2, -1, 5);
	CU_ASSERT_NSTRING_EQUAL(buffer1, buffer2, 5);

	// Test 7: Large value for 'c'
	memset(buffer1, 300, 5);
	ft_memset(buffer2, 300, 5);
	CU_ASSERT_NSTRING_EQUAL(buffer1, buffer2, 5);
}

void test_ft_bzero(void)
{
    char buffer1[50];
    char buffer2[50];

    // Initialize buffers with non-zero values
    memset(buffer1, 'A', sizeof(buffer1));
    memset(buffer2, 'A', sizeof(buffer2));

    // Test 1: Basic usage
    bzero(buffer1, 10);
    ft_bzero(buffer2, 10);
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Basic usage: Buffers are equal after zeroing.");
    } else {
        CU_FAIL("Basic usage: Buffers are not equal after zeroing.");
    }

    // Test 2: Zero bytes
    bzero(buffer1, 0);
    ft_bzero(buffer2, 0);
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Zero bytes: Buffers are equal after zeroing.");
    } else {
        CU_FAIL("Zero bytes: Buffers are not equal after zeroing.");
    }

    // Test 3: Entire buffer
    bzero(buffer1, sizeof(buffer1));
    ft_bzero(buffer2, sizeof(buffer2));
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Entire buffer: Buffers are equal after zeroing.");
    } else {
        CU_FAIL("Entire buffer: Buffers are not equal after zeroing.");
    }

    // Test 4: Partial zeroing
    bzero(buffer1 + 20, 10);
    ft_bzero(buffer2 + 20, 10);
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Partial zeroing: Buffers are equal after zeroing.");
    } else {
        CU_FAIL("Partial zeroing: Buffers are not equal after zeroing.");
    }
}

void test_ft_memcpy(void)
{
    char src[100];
    char dest1[100];
    char dest2[100];

    memset(src, 'A', sizeof(src)); // Initialize src with 'A'

    // Test 1: Basic Copy
    memcpy(dest1, src, 50);
    ft_memcpy(dest2, src, 50);
    if (memcmp(dest1, dest2, 50) == 0) {
        CU_PASS("Basic Copy: Buffers are equal after copying.");
    } else {
        CU_FAIL("Basic Copy: Buffers are not equal after copying.");
    }

    // Test 2: Zero Bytes
    memcpy(dest1, src, 0);
    ft_memcpy(dest2, src, 0);
    // Ensure dest1 and dest2 remain unchanged
    if (memcmp(dest1, src, sizeof(src)) == 0 && memcmp(dest2, src, sizeof(src)) == 0) {
        CU_PASS("Zero Bytes: Buffers remain unchanged.");
    } else {
        CU_FAIL("Zero Bytes: Buffers have changed unexpectedly.");
    }

    // Test 3: Full Buffer Copy
    memcpy(dest1, src, sizeof(src));
    ft_memcpy(dest2, src, sizeof(src));
    if (memcmp(dest1, dest2, sizeof(src)) == 0) {
        CU_PASS("Full Buffer Copy: Buffers are equal after full copying.");
    } else {
        CU_FAIL("Full Buffer Copy: Buffers are not equal after full copying.");
    }

    // Test 4: Null Pointers with n = 0
    CU_ASSERT_PTR_NULL(ft_memcpy(NULL, NULL, 0)); // Should return NULL or handle gracefully

    // Test 5: Return Value
    char *ret1 = memcpy(dest1, src, 10);
    char *ret2 = ft_memcpy(dest2, src, 10);
    CU_ASSERT_PTR_EQUAL(ret1, dest1); // Check return value of standard memcpy
    CU_ASSERT_PTR_EQUAL(ret2, dest2); // Check return value of ft_memcpy
}

void test_ft_memmove(void)
{
    char buffer1[100];
    char buffer2[100];
    char *src;
    char *dest1;
    char *dest2;

    memset(buffer1, 'A', sizeof(buffer1));
    memcpy(buffer2, buffer1, sizeof(buffer1)); // Initialize buffer2 with buffer1's content

    // Test 1: Basic Copy without Overlap
    src = buffer1;
    dest1 = buffer1 + 20;
    dest2 = buffer2 + 20;
    memmove(dest1, src, 30);
    ft_memmove(dest2, src, 30);
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Basic Copy without Overlap: Buffers are equal after moving.");
    } else {
        CU_FAIL("Basic Copy without Overlap: Buffers are not equal after moving.");
    }

    // Test 2: Overlapping Regions (dest < src)
    src = buffer1 + 10;
    dest1 = buffer1;
    dest2 = buffer2;
    memmove(dest1, src, 50);
    ft_memmove(dest2, src, 50);
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Overlapping Regions (dest < src): Buffers are equal after moving.");
    } else {
        CU_FAIL("Overlapping Regions (dest < src): Buffers are not equal after moving.");
    }

    // Test 3: Overlapping Regions (dest > src)
    src = buffer1;
    dest1 = buffer1 + 10;
    dest2 = buffer2 + 10;
    memmove(dest1, src, 50);
    ft_memmove(dest2, src, 50);
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Overlapping Regions (dest > src): Buffers are equal after moving.");
    } else {
        CU_FAIL("Overlapping Regions (dest > src): Buffers are not equal after moving.");
    }

    // Test 4: Zero Bytes
    memmove(buffer1, buffer1 + 5, 0);
    ft_memmove(buffer2, buffer2 + 5, 0);
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Zero Bytes: Buffers remain unchanged.");
    } else {
        CU_FAIL("Zero Bytes: Buffers have changed unexpectedly.");
    }

    // Test 5: Null Pointers with n = 0
    CU_ASSERT_PTR_NULL(ft_memmove(NULL, NULL, 0));  // Should handle gracefully

    // Test 6: Self-Copy
    memmove(buffer1, buffer1, sizeof(buffer1));
    ft_memmove(buffer2, buffer2, sizeof(buffer2));
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
        CU_PASS("Self-Copy: Buffers are equal after self-copying.");
    } else {
        CU_FAIL("Self-Copy: Buffers are not equal after self-copying.");
    }
}

void test_ft_strlcpy(void)
{
    char dest1[10];
    char dest2[10];
    size_t ret_ft;
    size_t ret_std;

    // Test 1: Basic Copy
    memset(dest1, 'A', sizeof(dest1));
    memset(dest2, 'A', sizeof(dest2));
    ret_ft = ft_strlcpy(dest1, "Hello", sizeof(dest1));
    // Since we are not using strlcpy, we'll just assume ret_std matches the expected behavior
    ret_std = strlen("Hello"); // Expected length
    CU_ASSERT_STRING_EQUAL(dest1, "Hello"); // Compare with expected value
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 2: Size Zero
    strcpy(dest1, "Existing");
    strcpy(dest2, "Existing");
    ret_ft = ft_strlcpy(dest1, "Hello", 0);
    ret_std = 0; // No copy happens
    CU_ASSERT_STRING_EQUAL(dest1, "Existing"); // Should remain unchanged
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value is 0

    // Test 3: Size Less Than src_len
    memset(dest1, 0, sizeof(dest1));
    memset(dest2, 0, sizeof(dest2));
    ret_ft = ft_strlcpy(dest1, "HelloWorld", 5);
    ret_std = strlen("HelloWorld"); // Expected length
    CU_ASSERT_STRING_EQUAL(dest1, "Hello"); // Should copy up to 5 characters
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 4: Exact Buffer Size
    memset(dest1, 0, sizeof(dest1));
    memset(dest2, 0, sizeof(dest2));
    ret_ft = ft_strlcpy(dest1, "Hello", 6);
    ret_std = strlen("Hello"); // Expected length
    CU_ASSERT_STRING_EQUAL(dest1, "Hello"); // Should copy the entire string
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 5: Empty Source String
    memset(dest1, 0, sizeof(dest1));
    memset(dest2, 0, sizeof(dest2));
    ret_ft = ft_strlcpy(dest1, "", sizeof(dest1));
    ret_std = 0; // Expected length when copying an empty string
    CU_ASSERT_STRING_EQUAL(dest1, ""); // Should remain an empty string
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value is 0
}

void test_ft_strlcat(void)
{
    char dest1[20];
    char dest2[20];
    size_t ret_ft;
    size_t ret_std;

    // Test 1: Basic Append
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, " World", sizeof(dest1));
    ret_std = strlen(dest2) + strlen(" World"); // Expected return value
    strcat(dest2, " World"); // Perform the standard behavior
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Compare results
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 2: Size Zero
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, " World", 0);
    ret_std = strlen(dest2); // No changes, expected return length
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Should remain unchanged
    CU_ASSERT_EQUAL(ret_ft, 6); // Check if the return value matches

    // Test 3: Size Less Than dest Length
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, " World", 3);
    ret_std = strlen(dest2); // Should not append " World"
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Should remain unchanged
    CU_ASSERT_EQUAL(ret_ft, 9); // Check if the return value matches

    // Test 4: Exact Buffer Size
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, " World", 12);
    ret_std = strlen(dest2) + strlen(" World"); // Total length
    strcat(dest2, " World"); // Append normally
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Compare results
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 5: Insufficient Space
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, " World", 10);
    ret_std = strlen(dest2); // Not enough space to append
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Should remain unchanged
    CU_ASSERT_EQUAL(ret_ft, 11); // Check if the return value matches

    // Test 6: Empty Source String
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, "", sizeof(dest1));
    ret_std = strlen(dest2); // No changes, expected return length
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Should remain unchanged
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 7: Empty Destination String
    strcpy(dest1, "");
    strcpy(dest2, "");
    ret_ft = ft_strlcat(dest1, "Hello", sizeof(dest1));
    ret_std = strlen("Hello"); // Expected return value
    strcat(dest2, "Hello"); // Append normally
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Compare results
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 8: Both Source and Destination Empty
    strcpy(dest1, "");
    strcpy(dest2, "");
    ret_ft = ft_strlcat(dest1, "", sizeof(dest1));
    ret_std = 0; // Nothing appended, length is 0
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Should remain unchanged
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 9: Size Less Than or Equal to Zero
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, " World", 0); // Attempting to append with size 0
    ret_std = strlen(dest2); // No changes, expected return length
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Should remain unchanged
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches

    // Test 10: Large Size Value
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret_ft = ft_strlcat(dest1, " World", 1000); // Large enough buffer
    ret_std = strlen(dest2) + strlen(" World"); // Total length
    strcat(dest2, " World"); // Append normally
    CU_ASSERT_STRING_EQUAL(dest1, dest2); // Compare results
    CU_ASSERT_EQUAL(ret_ft, ret_std); // Check if the return value matches
}

void test_ft_toupper(void)
{
    int c;

    for (c = 97; c <= 122; c++)
    {
        CU_ASSERT_EQUAL(ft_toupper(c), toupper(c));
    }
}

// Test function for ft_tolower
void test_ft_tolower(void)
{
    int c;

    for (c = 65; c <= 90; c++)
    {
        CU_ASSERT_EQUAL(ft_tolower(c), tolower(c));
    }
}

void test_ft_strchr(void)
{
    const char *s;
    char *result_ft;
    char *result_std;

    // Test 1: Character present in string
    s = "hello world";
    result_ft = ft_strchr(s, 'o');
    result_std = strchr(s, 'o');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 2: Character not present in string
    s = "hello world";
    result_ft = ft_strchr(s, 'x');
    result_std = strchr(s, 'x');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 3: Search for null terminator
    s = "hello world";
    result_ft = ft_strchr(s, '\0');
    result_std = strchr(s, '\0');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 4: Empty string
    s = "";
    result_ft = ft_strchr(s, 'a');
    result_std = strchr(s, 'a');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 5: Character at the beginning
    s = "abcde";
    result_ft = ft_strchr(s, 'a');
    result_std = strchr(s, 'a');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 6: Character at the end
    s = "abcde";
    result_ft = ft_strchr(s, 'e');
    result_std = strchr(s, 'e');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 8: Character with value greater than 127
    s = "hello\xFFworld";
    result_ft = ft_strchr(s, '\xFF');
    result_std = strchr(s, '\xFF');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 9: Character code greater than 255
    s = "abc";
    result_ft = ft_strchr(s, 300);
    result_std = strchr(s, 300);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 10: Negative character code
    s = "abc";
    result_ft = ft_strchr(s, -1);
    result_std = strchr(s, -1);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);
}

void test_ft_strrchr(void)
{
    const char *s;
    char *result_ft;
    char *result_std;

    // Test 1: Character present in string
    s = "hello world";
    result_ft = ft_strrchr(s, 'o');
    result_std = strrchr(s, 'o');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 2: Character not present in string
    s = "hello world";
    result_ft = ft_strrchr(s, 'x');
    result_std = strrchr(s, 'x');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 3: Search for null terminator
    s = "hello world";
    result_ft = ft_strrchr(s, '\0');
    result_std = strrchr(s, '\0');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 4: Empty string
    s = "";
    result_ft = ft_strrchr(s, 'a');
    result_std = strrchr(s, 'a');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 5: Character at the beginning
    s = "abcde";
    result_ft = ft_strrchr(s, 'a');
    result_std = strrchr(s, 'a');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 6: Character at the end
    s = "abcde";
    result_ft = ft_strrchr(s, 'e');
    result_std = strrchr(s, 'e');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 7: Multiple occurrences
    s = "banana";
    result_ft = ft_strrchr(s, 'a');
    result_std = strrchr(s, 'a');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 9: Character with value greater than 127
    s = "hello\xFFworld";
    result_ft = ft_strrchr(s, '\xFF');
    result_std = strrchr(s, '\xFF');
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 10: Negative character code
    s = "abc";
    result_ft = ft_strrchr(s, -1);
    result_std = strrchr(s, -1);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);
}

void test_ft_strncmp(void)
{
    int ret_ft;
    int ret_std;

    // Test 1: Identical strings
    ret_ft = ft_strncmp("hello", "hello", 5);
    ret_std = strncmp("hello", "hello", 5);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 2: Different strings
    ret_ft = ft_strncmp("hello", "world", 5);
    ret_std = strncmp("hello", "world", 5);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 3: Partial comparison
    ret_ft = ft_strncmp("hello", "helicopter", 3);
    ret_std = strncmp("hello", "helicopter", 3);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 4: String with null characters
    ret_ft = ft_strncmp("abc\0def", "abc\0xyz", 7);
    ret_std = strncmp("abc\0def", "abc\0xyz", 7);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 5: One string is prefix of the other
    ret_ft = ft_strncmp("hello", "hello world", 11);
    ret_std = strncmp("hello", "hello world", 11);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 6: Empty strings
    ret_ft = ft_strncmp("", "", 5);
    ret_std = strncmp("", "", 5);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 7: n is zero
    ret_ft = ft_strncmp("hello", "world", 0);
    ret_std = strncmp("hello", "world", 0);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 8: Strings differ at last character
    ret_ft = ft_strncmp("abcd", "abce", 4);
    ret_std = strncmp("abcd", "abce", 4);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 9: Non-ASCII characters
    ret_ft = ft_strncmp("héllo", "héllö", 5);
    ret_std = strncmp("héllo", "héllö", 5);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 10: Large n value
    ret_ft = ft_strncmp("hello", "hello", 1000);
    ret_std = strncmp("hello", "hello", 1000);
    CU_ASSERT_EQUAL(ret_ft, ret_std);
}

void test_ft_memchr(void)
{
    const char *s;
    void *result_ft;
    void *result_std;

    // Test 1: Character present in memory area
    s = "hello world";
    result_ft = ft_memchr(s, 'o', 11);
    result_std = memchr(s, 'o', 11);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 2: Character not present in memory area
    s = "hello world";
    result_ft = ft_memchr(s, 'x', 11);
    result_std = memchr(s, 'x', 11);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 3: Search for null terminator
    s = "hello\0world";
    result_ft = ft_memchr(s, '\0', 11);
    result_std = memchr(s, '\0', 11);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 4: n is zero
    s = "hello world";
    result_ft = ft_memchr(s, 'h', 0);
    result_std = memchr(s, 'h', 0);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 5: Empty memory area
    s = "";
    result_ft = ft_memchr(s, 'a', 1);
    result_std = memchr(s, 'a', 1);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 6: Character at beginning of memory area
    s = "abcde";
    result_ft = ft_memchr(s, 'a', 5);
    result_std = memchr(s, 'a', 5);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 7: Character at end of memory area
    s = "abcde";
    result_ft = ft_memchr(s, 'e', 5);
    result_std = memchr(s, 'e', 5);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 9: Character with value greater than 127
    unsigned char data1[] = {0xFF, 0xFE, 0xFD};
    result_ft = ft_memchr(data1, 0xFE, 3);
    result_std = memchr(data1, 0xFE, 3);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 10: Binary data
    unsigned char data2[] = {0x00, 0x01, 0x02, 0x03, 0x04};
    result_ft = ft_memchr(data2, 0x03, 5);
    result_std = memchr(data2, 0x03, 5);
    CU_ASSERT_PTR_EQUAL(result_ft, result_std);
}

void test_ft_memcmp(void)
{
    int ret_ft;
    int ret_std;
    const char *s1;
    const char *s2;

    // Test 1: Identical memory areas
    s1 = "hello world";
    s2 = "hello world";
    ret_ft = ft_memcmp(s1, s2, 11);
    ret_std = memcmp(s1, s2, 11);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 2: Different memory areas
    s1 = "hello world";
    s2 = "hello there";
    ret_ft = ft_memcmp(s1, s2, 11);
    ret_std = memcmp(s1, s2, 11);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 3: Partial comparison
    s1 = "hello world";
    s2 = "hello there";
    ret_ft = ft_memcmp(s1, s2, 5);
    ret_std = memcmp(s1, s2, 5);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 4: n is zero
    s1 = "abc";
    s2 = "def";
    ret_ft = ft_memcmp(s1, s2, 0);
    ret_std = memcmp(s1, s2, 0);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 5: Empty memory areas
    s1 = "";
    s2 = "";
    ret_ft = ft_memcmp(s1, s2, 1);
    ret_std = memcmp(s1, s2, 1);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 6: Binary data
    unsigned char data1[] = {0x00, 0x01, 0x02, 0x03};
    unsigned char data2[] = {0x00, 0x01, 0x02, 0x04};
    ret_ft = ft_memcmp(data1, data2, 4);
    ret_std = memcmp(data1, data2, 4);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 7: Non-ASCII characters
    s1 = "héllo";
    s2 = "héllö";
    ret_ft = ft_memcmp(s1, s2, 5);
    ret_std = memcmp(s1, s2, 5);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 8: Large n value
    s1 = "test";
    s2 = "test";
    ret_ft = ft_memcmp(s1, s2, 1000);
    ret_std = memcmp(s1, s2, 1000);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 9: One memory area is prefix of the other
    s1 = "hello";
    s2 = "hello world";
    ret_ft = ft_memcmp(s1, s2, 11);
    ret_std = memcmp(s1, s2, 11);
    CU_ASSERT_EQUAL(ret_ft, ret_std);

    // Test 10: Difference at last byte
    s1 = "abcd";
    s2 = "abce";
    ret_ft = ft_memcmp(s1, s2, 4);
    ret_std = memcmp(s1, s2, 4);
    CU_ASSERT_EQUAL(ret_ft, ret_std);
}

void test_ft_strnstr(void)
{
    const char *big;
    const char *little;
    char *result_ft;

    // Test 1: Little string is empty
    big = "hello world";
    little = "";
    result_ft = ft_strnstr(big, little, 11);
    CU_ASSERT_PTR_EQUAL(result_ft, big); // If little is empty, ft_strnstr should return big

    // Test 2: Little string not found
    big = "hello world";
    little = "planet";
    result_ft = ft_strnstr(big, little, 11);
    CU_ASSERT_PTR_EQUAL(result_ft, NULL); // Not found, should return NULL

    // Test 3: Little string found at the beginning
    big = "hello world";
    little = "hello";
    result_ft = ft_strnstr(big, little, 11);
    CU_ASSERT_PTR_EQUAL(result_ft, big); // Should return pointer to the beginning of big

    // Test 4: Little string found in the middle
    big = "say hello to the world";
    little = "hello";
    result_ft = ft_strnstr(big, little, 20);
    CU_ASSERT_PTR_EQUAL(result_ft, big + 4); // Should return pointer to "hello"

    // Test 5: Little string found at the end
    big = "say hello";
    little = "hello";
    result_ft = ft_strnstr(big, little, 9);
    CU_ASSERT_PTR_EQUAL(result_ft, big + 4); // Should return pointer to "hello"

    // Test 6: Little string larger than big string
    big = "hi";
    little = "hello";
    result_ft = ft_strnstr(big, little, 2);
    CU_ASSERT_PTR_EQUAL(result_ft, NULL); // Not found, should return NULL

    // Test 7: len smaller than little string length
    big = "hello world";
    little = "world";
    result_ft = ft_strnstr(big, little, 3);
    CU_ASSERT_PTR_EQUAL(result_ft, NULL); // Not found, should return NULL

    // Test 8: len is zero
    big = "hello world";
    little = "hello";
    result_ft = ft_strnstr(big, little, 0);
    CU_ASSERT_PTR_EQUAL(result_ft, NULL); // Should return NULL for zero length

    // Test 9: Big string contains little string after len
    big = "hello world";
    little = "world";
    result_ft = ft_strnstr(big, little, 5);
    CU_ASSERT_PTR_EQUAL(result_ft, NULL); // Not found, should return NULL

    // Test 10: Searching for null terminator
    big = "hello";
    little = "\0";
    result_ft = ft_strnstr(big, little, 5);
    CU_ASSERT_PTR_EQUAL(result_ft, big); // Should return pointer to the beginning of big
}

void test_ft_atoi(void)
{
    const char *str;
    int result_ft;
    int result_std;

    // Test 1: Valid positive number
    str = "12345";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 2: Valid negative number
    str = "-54321";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 3: Leading whitespace
    str = "   42";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 4: Leading plus sign
    str = "+100";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 5: Non-digit characters at the end
    str = "123abc";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 6: Invalid string (no digits)
    str = "abc";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 7: Empty string
    str = "";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);
/*
    // Test 8: Number exceeding INT_MAX
    str = "2147483648";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 9: Number less than INT_MIN
    str = "-2147483649";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);
*/
    // Test 10: Leading zeros
    str = "0000123";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 11: Only whitespace
    str = "   ";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 12: Number with intermediate spaces
    str = "12 34";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 13: Multiple signs
    str = "--123";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);

    // Test 14: Non-printable characters
    str = "\n\t\v\f\r42";
    result_ft = ft_atoi(str);
    result_std = atoi(str);
    CU_ASSERT_EQUAL(result_ft, result_std);
}

void test_ft_calloc(void)
{
    void *ptr_ft;
    void *ptr_std;
    size_t nmemb, size;
    int cmp_result;

    // Test 1: Normal allocation
    nmemb = 10;
    size = sizeof(int);
    ptr_ft = ft_calloc(nmemb, size);
    ptr_std = calloc(nmemb, size);
    CU_ASSERT_PTR_NOT_NULL(ptr_ft);
    CU_ASSERT_PTR_NOT_NULL(ptr_std);
    cmp_result = memcmp(ptr_ft, ptr_std, nmemb * size);
    CU_ASSERT_EQUAL(cmp_result, 0);
    free(ptr_ft);
    free(ptr_std);

   /* // Test 2: Zero elements
    nmemb = 0;
    size = sizeof(int);
    ptr_ft = ft_calloc(nmemb, size);
    ptr_std = calloc(nmemb, size);
    CU_ASSERT_EQUAL(ptr_ft == NULL, ptr_std == NULL);
    free(ptr_ft);
    free(ptr_std);

    // Test 3: Zero size
    nmemb = 10;
    size = 0;
    ptr_ft = ft_calloc(nmemb, size);
    ptr_std = calloc(nmemb, size);
    CU_ASSERT_EQUAL(ptr_ft == NULL, ptr_std == NULL);
    free(ptr_ft);
    free(ptr_std);

    // Test 4: Both zero
    nmemb = 0;
    size = 0;
    ptr_ft = ft_calloc(nmemb, size);
    ptr_std = calloc(nmemb, size);
    CU_ASSERT_EQUAL(ptr_ft == NULL, ptr_std == NULL);
    free(ptr_ft);
    free(ptr_std);
/*

    // Test 5: Maximum allocation (should fail)
    nmemb = 2147483647;
    size = 1;
    ptr_ft = ft_calloc(nmemb, size);
    CU_ASSERT_PTR_NULL(ptr_ft);

    // Test 6: Multiplication overflow (should fail)
    nmemb = 2147483647 / 2 + 1;
    size = 2;
    ptr_ft = ft_calloc(nmemb, size);
    CU_ASSERT_PTR_NULL(ptr_ft);
*/
    // Test 7: Large allocation (may fail depending on system)
    nmemb = 1000000;
    size = 1000;
    ptr_ft = ft_calloc(nmemb, size);
    if (ptr_ft)
    {
        // Memory allocated successfully
        memset(ptr_ft, 1, nmemb * size); // Use the memory
        free(ptr_ft);
    }
    else
    {
        // Allocation failed
        CU_ASSERT_TRUE(errno == ENOMEM);
    }


    // Test 8: Memory initialization check
    nmemb = 50;
    size = sizeof(char);
    ptr_ft = ft_calloc(nmemb, size);
    CU_ASSERT_PTR_NOT_NULL(ptr_ft);
    for (size_t i = 0; i < nmemb * size; i++)
    {
        CU_ASSERT_EQUAL(((unsigned char *)ptr_ft)[i], 0);
    }
    free(ptr_ft);


    // Test 10: Non-zero memory before allocation
    nmemb = 20;
    size = sizeof(int);
    ptr_ft = malloc(nmemb * size);
    memset(ptr_ft, 0xFF, nmemb * size); // Set to non-zero
    free(ptr_ft);
    ptr_ft = ft_calloc(nmemb, size);
    CU_ASSERT_PTR_NOT_NULL(ptr_ft);
    for (size_t i = 0; i < nmemb * size; i++)
    {
        CU_ASSERT_EQUAL(((unsigned char *)ptr_ft)[i], 0);
    }
    free(ptr_ft);
}

void test_ft_strdup(void)
{
    const char *str;
    char *dup_ft;
    char *dup_std;

    // Test 1: Duplicate a normal string
    str = "Hello, World!";
    dup_ft = ft_strdup(str);
    dup_std = strdup(str);
    CU_ASSERT_PTR_NOT_NULL(dup_ft);
    CU_ASSERT_PTR_NOT_NULL(dup_std);
    CU_ASSERT_STRING_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);

    // Test 2: Duplicate an empty string
    str = "";
    dup_ft = ft_strdup(str);
    dup_std = strdup(str);
    CU_ASSERT_PTR_NOT_NULL(dup_ft);
    CU_ASSERT_PTR_NOT_NULL(dup_std);
    CU_ASSERT_STRING_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);

    // Test 3: Duplicate a string with special characters
    str = "Line1\nLine2\tTabbed";
    dup_ft = ft_strdup(str);
    dup_std = strdup(str);
    CU_ASSERT_PTR_NOT_NULL(dup_ft);
    CU_ASSERT_PTR_NOT_NULL(dup_std);
    CU_ASSERT_STRING_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);

    // Test 4: Duplicate a very long string
    char *long_str = malloc(10001);
    memset(long_str, 'A', 10000);
    long_str[10000] = '\0';
    dup_ft = ft_strdup(long_str);
    dup_std = strdup(long_str);
    CU_ASSERT_PTR_NOT_NULL(dup_ft);
    CU_ASSERT_PTR_NOT_NULL(dup_std);
    CU_ASSERT_STRING_EQUAL(dup_ft, dup_std);
    free(dup_ft);
    free(dup_std);
    free(long_str);

    // Test 5: Simulate memory allocation failure
    // Skipping this test as it's complex to simulate malloc failure

    // Test 6: Input string is NULL (undefined behavior)
    // Skipping as standard strdup does not handle NULL input

    // Test 7: Modify original string after duplication
    char original_str[] = "Original";
    dup_ft = ft_strdup(original_str);
    CU_ASSERT_PTR_NOT_NULL(dup_ft);
    strcpy(original_str, "Changed");
    CU_ASSERT_STRING_NOT_EQUAL(dup_ft, original_str);
    free(dup_ft);

    // Test 8: Modify duplicate string
    char *modifiable_dup = ft_strdup("Modify me");
    CU_ASSERT_PTR_NOT_NULL(modifiable_dup);
    strcpy(modifiable_dup, "Modified");
    CU_ASSERT_STRING_EQUAL(modifiable_dup, "Modified");
    free(modifiable_dup);
}

// ----- End here ----- //




// Register tests and run them
int main()
{
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	CU_pSuite suite = CU_add_suite("Libft Test Suite", 0, 0);
	if (!suite) { CU_cleanup_registry(); return CU_get_error(); }

	// Add tests
	CU_add_test(suite, "test_ft_atoi", test_ft_atoi);
    CU_add_test(suite, "test_ft_bzero", test_ft_bzero);
    CU_add_test(suite, "test_ft_calloc", test_ft_calloc);
    CU_add_test(suite, "test_ft_isalnum", test_ft_isalnum);
    CU_add_test(suite, "test_ft_isalpha", test_ft_isalpha);
    CU_add_test(suite, "test_ft_isascii", test_ft_isascii);
    CU_add_test(suite, "test_ft_isdigit", test_ft_isdigit);
    CU_add_test(suite, "test_ft_isprint", test_ft_isprint);
    CU_add_test(suite, "test_ft_memchr", test_ft_memchr);
    CU_add_test(suite, "test_ft_memcmp", test_ft_memcmp);
    CU_add_test(suite, "test_ft_memcpy", test_ft_memcpy);
    CU_add_test(suite, "test_ft_memmove", test_ft_memmove);
    CU_add_test(suite, "test_ft_memset", test_ft_memset);
    CU_add_test(suite, "test_ft_strchr", test_ft_strchr);
    CU_add_test(suite, "test_ft_strdup", test_ft_strdup);
    CU_add_test(suite, "test_ft_strlcat", test_ft_strlcat);
    CU_add_test(suite, "test_ft_strlcpy", test_ft_strlcpy);
    CU_add_test(suite, "test_ft_strlen", test_ft_strlen);
    CU_add_test(suite, "test_ft_strncmp", test_ft_strncmp);
    CU_add_test(suite, "test_ft_strnstr", test_ft_strnstr);
    CU_add_test(suite, "test_ft_strrchr", test_ft_strrchr);
    CU_add_test(suite, "test_ft_tolower", test_ft_tolower);
    CU_add_test(suite, "test_ft_toupper", test_ft_toupper);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return (CU_get_error());
}

#include "../imtest42/imtest42.h"
#include "tests.h"

#include <stdio.h>
#include <ctype.h>

// Helpers
static char	toupper_test(unsigned int index, char c)
{
	(void)index; // Index not needed in this function
	return toupper(c);
}

static char	tolower_test(unsigned int index, char c)
{
	(void)index; // Index not needed in this function
	return tolower(c);
}

static char capitalize_even(unsigned int index, char c)
{
    if (index % 2 == 0) // Only capitalize if index is even
        return toupper(c);
    else
        return c;
}

void	test_ft_strmapi(void)
{
	printf("\nTest 1: toupper on lowercase string\n");
	char s1[] = "hive";
	char *result1 = ft_strmapi(s1, toupper_test);
	IM_ASSERT_STR_EQUAL("HIVE", result1);
	free(result1);

	printf("\nTest 2: tolower on uppercase string\n");
	char s2[] = "HIVE";
	char *result2 = ft_strmapi(s2, tolower_test);
	IM_ASSERT_STR_EQUAL("hive", result2);
	free(result2);

	printf("\nTest 3: toupper on mixed case string\n");
	char s3[] = "HeLLo WoRLD";
	char *result3 = ft_strmapi(s3, toupper_test);
	IM_ASSERT_STR_EQUAL("HELLO WORLD", result3);
	free(result3);

	printf("\nTest 4: tolower on mixed case string\n");
	char s4[] = "HeLLo WoRLD";
	char *result4 = ft_strmapi(s4, tolower_test);
	IM_ASSERT_STR_EQUAL("hello world", result4);
	free(result4);

	printf("\nTest 5: toupper on empty string\n");
	char s5[] = "";
	char *result5 = ft_strmapi(s5, toupper_test);
	IM_ASSERT_STR_EQUAL("", result5);
	free(result5);

	printf("\nTest 6: toupper on single character\n");
	char s6[] = "a";
	char *result6 = ft_strmapi(s6, toupper_test);
	IM_ASSERT_STR_EQUAL("A", result6);
	free(result6);

	printf("\nTest 7: tolower on single character\n");
	char s7[] = "A";
	char *result7 = ft_strmapi(s7, tolower_test);
	IM_ASSERT_STR_EQUAL("a", result7);
	free(result7);

	printf("\nTest 8: toupper on numeric string\n");
	char s8[] = "12345";
	char *result8 = ft_strmapi(s8, toupper_test);
	IM_ASSERT_STR_EQUAL("12345", result8);
	free(result8);

	printf("\nTest 9: tolower on numeric string\n");
	char s9[] = "12345";
	char *result9 = ft_strmapi(s9, tolower_test);
	IM_ASSERT_STR_EQUAL("12345", result9);
	free(result9);

	printf("\nTest 10: capitalize even-indexed characters\n");
	char s10[] = "hive helsinki";
	char *result10 = ft_strmapi(s10, capitalize_even);
	IM_ASSERT_STR_EQUAL("HiVe hElSiNkI", result10);
	free(result10);
}

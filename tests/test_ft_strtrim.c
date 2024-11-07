#include "../imtest42/imtest42.h"
#include "tests.h"

#include <stdlib.h>
#include <stdio.h>

// char *ft_strtrim(char const *s1, char const *set);

void test_ft_strtrim(void)
{
	printf("\nTest 1: Trimming '.' from both ends\n");
	const char s1[] = ".hive.";
	char *trimmed_str1 = ft_strtrim(s1, ".");
	IM_ASSERT_STR_EQUAL("hive", trimmed_str1);
	free(trimmed_str1);

	printf("\nTest 2: Trimming multiple '.' characters from both ends\n");
	const char s2[] = "..hive..";
	char *trimmed_str2 = ft_strtrim(s2, ".");
	IM_ASSERT_STR_EQUAL("hive", trimmed_str2);
	free(trimmed_str2);

	printf("\nTest 3: Trimming '.' and '-' characters\n");
	const char s3[] = "-.hive.-";
	char *trimmed_str3 = ft_strtrim(s3, ".-");
	IM_ASSERT_STR_EQUAL("hive", trimmed_str3);
	free(trimmed_str3);

	printf("\nTest 4: Trimming '+' and '.' characters\n");
	const char s4[] = "+++.hive.";
	char *trimmed_str4 = ft_strtrim(s4, ".+");
	IM_ASSERT_STR_EQUAL("hive", trimmed_str4);
	free(trimmed_str4);

	printf("\nTest 5: Trimming all '.' characters\n");
	const char s5[] = "....";
	char *trimmed_str5 = ft_strtrim(s5, ".");
	IM_ASSERT_STR_EQUAL("", trimmed_str5); // Expect an empty string
	free(trimmed_str5);

	printf("\nTest 6: No trimming needed\n");
	const char s6[] = "hive";
	char *trimmed_str6 = ft_strtrim(s6, ".");
	IM_ASSERT_STR_EQUAL("hive", trimmed_str6); // Expect the original string unchanged
	free(trimmed_str6);

	printf("\nTest 7: Trimming whitespace characters\n");
	const char s7[] = "   hive   ";
	char *trimmed_str7 = ft_strtrim(s7, " ");
	IM_ASSERT_STR_EQUAL("hive", trimmed_str7);
	free(trimmed_str7);

	printf("\nTest 8: Empty string\n");
	const char s8[] = "";
	char *trimmed_str8 = ft_strtrim(s8, ".");
	IM_ASSERT_STR_EQUAL("", trimmed_str8); // Expect an empty string
	free(trimmed_str8);

	printf("\nTest 9: Empty set, no trimming\n");
	const char s9[] = ".hive.";
	char *trimmed_str9 = ft_strtrim(s9, "");
	IM_ASSERT_STR_EQUAL(".hive.", trimmed_str9); // Expect the original string unchanged
	free(trimmed_str9);
}

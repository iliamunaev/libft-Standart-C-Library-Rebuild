#include "../imtest42/imtest42.h"
#include "tests.h"

#include <stdio.h>
#include <ctype.h>

void	toupper_test(unsigned int index, char *c)
{
	(void)index; // Index not needed in this function
	*c = toupper(*c);
}

void	tolower_test(unsigned int index, char *c)
{
	(void)index; // Index not needed in this function
	*c = tolower(*c);
}

void capitalize_even(unsigned int index, char *c)
{
    if (index % 2 == 0) // Only capitalize if index is even
        *c = toupper(*c);
}

void	test_ft_striteri(void)
{
	printf("\nTest 1: toupper on lowercase string\n");
	char s1[] = "hive";
	ft_striteri(s1, toupper_test);
	IM_ASSERT_STR_EQUAL("HIVE", s1);

	printf("\nTest 2: tolower on uppercase string\n");
	char s2[] = "HIVE";
	ft_striteri(s2, tolower_test);
	IM_ASSERT_STR_EQUAL("hive", s2);

	printf("\nTest 3: toupper on mixed case string\n");
	char s3[] = "HeLLo WoRLD";
	ft_striteri(s3, toupper_test);
	IM_ASSERT_STR_EQUAL("HELLO WORLD", s3);

	printf("\nTest 4: tolower on mixed case string\n");
	char s4[] = "HeLLo WoRLD";
	ft_striteri(s4, tolower_test);
	IM_ASSERT_STR_EQUAL("hello world", s4);

	printf("\nTest 5: toupper on empty string\n");
	char s5[] = "";
	ft_striteri(s5, toupper_test);
	IM_ASSERT_STR_EQUAL("", s5);

	printf("\nTest 6: toupper on single character\n");
	char s8[] = "a";
	ft_striteri(s8, toupper_test);
	IM_ASSERT_STR_EQUAL("A", s8);

	printf("\nTest 7: tolower on single character\n");
	char s9[] = "A";
	ft_striteri(s9, tolower_test);
	IM_ASSERT_STR_EQUAL("a", s9);

	printf("\nTest 8: toupper on numeric string\n");
	char s10[] = "12345";
	ft_striteri(s10, toupper_test);
	IM_ASSERT_STR_EQUAL("12345", s10);

	printf("\nTest 9: tolower on numeric string\n");
	char s11[] = "12345";
	ft_striteri(s11, tolower_test);
	IM_ASSERT_STR_EQUAL("12345", s11);

	printf("\nTest 10: capitalize even-indexed characters\n");
	char s12[] = "hive helsinki";
	ft_striteri(s12, capitalize_even);
	IM_ASSERT_STR_EQUAL("HiVe hElSiNkI", s12);
}

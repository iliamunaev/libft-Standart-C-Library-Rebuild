#include "test42lib.h"

/*
* Compares two int values: expected to actual.
*/
void	ASSERT_EQUAL_INT(int exp_int, int act_int)
{
	if(exp_int == act_int)
	{
		printf("PASS.\n");
	}
	else
	{
		printf("!-----FAIL-----!: (expected %d, got %d)\n", exp_int, act_int);
	}
}

/*
* Compares two strings value: expected to actual
*/

void	ASSERT_EQUAL_STR(const char *act_str, const char *exp_str)
{
	if (strcmp(act_str, exp_str) == 0)
	{
		printf("PASS.\n");
	}
	else
	{
		printf("!-----FAIL-----!: (expected \"%s\", got \"%s\")\n", exp_str, act_str);
	}
}


/*
* Compares two chars: expected to actual
*/

void	ASSERT_EQUAL_CHAR(int exp_char, int act_char)
{
	if(exp_char == act_char)
	{
		printf("PASS.\n");
	}
	else
	{
		printf("!-----FAIL-----!: (expected %c, got %c)\n", exp_char, act_char);
	}
}

/*
* Asserts that the given pointer is NULL.
*/
void	ASSERT_EQUAL_NULL(const void *ptr)
{
	if (ptr == NULL)
	{
		printf("PASS.\n");
	}
	else
	{
		printf("!-----FAIL-----!: (expected NULL, got %p)\n", ptr);
	}
}

void	ASSERT_STRNCMP(const char *s1, const char *s2, size_t n, int expected)
{
    int result = ft_strncmp(s1, s2, n);
    printf("Comparing \"%s\" and \"%s\" with n = %zu:\n", s1, s2, n);
    
    if (result == expected)
    {
        printf("PASS.\n");
    }
    else
    {
        printf("!-----FAIL-----!: (expected %d, got %d)\n", expected, result);
    }
}
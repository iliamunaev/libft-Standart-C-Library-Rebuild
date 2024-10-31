//#include <stdio.h>
//#include <string.h>
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

void	ASSERT_EQUAL_STR(const char *exp_str, const char *act_str)
{
	if (strcmp(exp_str, act_str) == 0)
	{
		printf("PASS\n");
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
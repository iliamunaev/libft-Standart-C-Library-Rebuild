#include "test42lib.h"
#include <stdio.h>

/*
* Compares an expected integer value to an actual integer value
* produced by the function under test.
*/
void	ASSERT_EQUAL_INT(int expected, int actual, const char *test_name)
{
	if(expected == actual)
	{
		printf("PASS: %s\n", test_name);
	}
	else
	{
		printf("---FAIL: %s (expected %d, got %d)\n", test_name, expected, actual);
	}
}

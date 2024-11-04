#include "../test42lib/test42lib.h"
#include "tests.h"

void	test_ft_strrchr(void)
{
	// char exists in str
	ASSERT_EQUAL_PTR("abcdefg" + 5, ft_strrchr("abcdefg", 'f'));

	// no char in str
	ASSERT_EQUAL_PTR(NULL, ft_strrchr("abcdefg", 'h'));

	// find '\0'
	ASSERT_EQUAL_PTR("afbcdefg" + 8, ft_strrchr("afbcdefg", '\0'));

	// two instances of the same char in str
	ASSERT_EQUAL_PTR("afbcdefg" + 6, ft_strrchr("afbcdefg", 'f'));

	// empty string, looking for '\0'
	ASSERT_EQUAL_PTR("", ft_strrchr("", '\0'));
}

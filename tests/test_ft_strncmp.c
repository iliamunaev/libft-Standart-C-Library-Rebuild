#include "../test42lib/test42lib.h"
#include "tests.h"

void	test_ft_strncmp(void)
{
    // Equal strings, full comparison
    ASSERT_EQUAL_INT('e' - 'e', ft_strncmp("hive", "hive", 4));

    // Different strings, first differing character
	ASSERT_EQUAL_INT('e' - 'v', ft_strncmp("hive", "hivv", 4));

    // One string shorter than the other
	ASSERT_EQUAL_INT('e' - 0, ft_strncmp("hive", "hiv", 5));
	ASSERT_EQUAL_INT(0 - 'e', ft_strncmp("hiv", "hive", 5));

    // Case sensitivity
	ASSERT_EQUAL_INT('H' - 'h', ft_strncmp("Hive", "hive", 5));
	ASSERT_EQUAL_INT('h' - 'H', ft_strncmp("hive", "Hive", 5));

    // 'n' shorter than string length
	ASSERT_EQUAL_INT('H' - 'h', ft_strncmp("Hive", "hive", 3));
	ASSERT_EQUAL_INT('H' - 'h', ft_strncmp("Hive", "hive", 1));

	// 'n' is equal zero
	ASSERT_EQUAL_INT(0, ft_strncmp("Hive", "hive", 0));

    // Empty string comparison
	ASSERT_EQUAL_INT(0, ft_strncmp("", "", 5));
	ASSERT_EQUAL_INT('h' - 0, ft_strncmp("hive", "", 5));
    ASSERT_EQUAL_INT(0 - 'h', ft_strncmp("", "hive", 5));
}
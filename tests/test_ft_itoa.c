#include "../test42lib/test42lib.h"
#include "../libft.h"

void	test_ft_itoa(void)
{
    ASSERT_EQUAL_STR("0", ft_itoa(0));

	// max / min
    ASSERT_EQUAL_STR("2147483647", ft_itoa(2147483647));
    ASSERT_EQUAL_STR("-2147483648", ft_itoa(2147483648));

	// one digit num
    ASSERT_EQUAL_STR("1", ft_itoa(1));
    ASSERT_EQUAL_STR("-1", ft_itoa(-1));
	ASSERT_EQUAL_STR("9", ft_itoa(9));
    ASSERT_EQUAL_STR("-9", ft_itoa(-9));

	// two digit num
	ASSERT_EQUAL_STR("10", ft_itoa(10));
    ASSERT_EQUAL_STR("-10", ft_itoa(-10));
    ASSERT_EQUAL_STR("99", ft_itoa(99));
    ASSERT_EQUAL_STR("-99", ft_itoa(-99));

	// many digits num
    ASSERT_EQUAL_STR("12345", ft_itoa(12345));
    ASSERT_EQUAL_STR("-12345", ft_itoa(-12345));
}

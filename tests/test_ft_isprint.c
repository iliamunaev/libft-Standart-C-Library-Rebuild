#include "../test42lib/test42lib.h"
#include "../libft.h"

void	test_ft_isprint(void)
{
    // Test printble chars
    ASSERT_EQUAL_INT(1, ft_isprint(32), "test_ft_isprint_SP_32");
    ASSERT_EQUAL_INT(1, ft_isprint(127), "test_ft_isprint_DEL_127");
    ASSERT_EQUAL_INT(1, ft_isprint('a'), "test_ft_isprint_a");
    ASSERT_EQUAL_INT(1, ft_isprint('Z'), "test_ft_isprint_Z");
    ASSERT_EQUAL_INT(1, ft_isprint('@'), "test_ft_isprint_@");
    ASSERT_EQUAL_INT(1, ft_isprint('}'), "test_ft_isprint_}");

    // Test unprintble chars
    ASSERT_EQUAL_INT(0, ft_isprint(31), "test_ft_isprint_US_31");
    ASSERT_EQUAL_INT(0, ft_isprint(128), "test_ft_isprint_€_128");
}


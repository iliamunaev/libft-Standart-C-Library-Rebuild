#include "../imtest42/imtest42.h"
#include "tests.h"

void    test_ft_isdigit(void)
{
    // Test valid digits '0' to '9'
    int c;
    for (c = '0'; c <= '9'; c++)
    {
        IM_ASSERT_NONZERO(ft_isdigit(c));
    }
    // Test characters just before '0' and after '9'
    IM_ASSERT_ZERO(ft_isdigit('0' - 1)); // Character before '0' (ASCII value 47 '/')
    IM_ASSERT_ZERO(ft_isdigit('9' + 1)); // Character after '9' (ASCII value 58 ':')

    // Test non-digit characters (letters)
    IM_ASSERT_ZERO(ft_isdigit('a'));
    IM_ASSERT_ZERO(ft_isdigit('Z'));

    // Test whitespace characters
    IM_ASSERT_ZERO(ft_isdigit(' '));
    IM_ASSERT_ZERO(ft_isdigit('\n'));
    IM_ASSERT_ZERO(ft_isdigit('\t'));

    // Test special characters
    IM_ASSERT_ZERO(ft_isdigit('@'));
    IM_ASSERT_ZERO(ft_isdigit('['));
    IM_ASSERT_ZERO(ft_isdigit('`'));
    IM_ASSERT_ZERO(ft_isdigit('{'));

    // Test extended ASCII characters
    IM_ASSERT_ZERO(ft_isdigit(128));
    IM_ASSERT_ZERO(ft_isdigit(255));

    // Test negative values
    IM_ASSERT_ZERO(ft_isdigit(-1));
    IM_ASSERT_ZERO(ft_isdigit(-128));

    // Test EOF value
    IM_ASSERT_ZERO(ft_isdigit(EOF)); // EOF is typically defined as -1
}

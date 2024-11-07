#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_isprint(void)
{
    int c;

    // Test printable characters (32 to 127)

    IM_ASSERT_NONZERO(ft_isprint(32));
    IM_ASSERT_NONZERO(ft_isprint(127));

    // Test non-printable characters (0 to 31)
    IM_ASSERT_ZERO(ft_isprint(0));
    IM_ASSERT_ZERO(ft_isprint(3));

    // Test DEL character (127)
    IM_ASSERT_NONZERO(ft_isprint(127));

    // Test extended ASCII characters (128 to 255)

    IM_ASSERT_ZERO(ft_isprint(128));
    IM_ASSERT_ZERO(ft_isprint(255));


    // Test negative values
    IM_ASSERT_ZERO(ft_isprint(-1));
    IM_ASSERT_ZERO(ft_isprint(-128));
}


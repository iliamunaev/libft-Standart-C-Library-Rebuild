#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_isprint(void)
{
    int c;

    // Test printable characters (32 to 127)
    for (c = 32; c <= 127; c++)
    {
        IM_ASSERT_NONZERO(ft_isprint(c));
    }

    // Test non-printable characters (0 to 31)
    for (c = 0; c < 32; c++)
    {
        IM_ASSERT_ZERO(ft_isprint(c));
    }

    // Test DEL character (127)
    IM_ASSERT_NONZERO(ft_isprint(127));

    // Test extended ASCII characters (128 to 255)
    for (c = 128; c <= 255; c++)
    {
        IM_ASSERT_ZERO(ft_isprint(c));
    }

    // Test negative values
    IM_ASSERT_ZERO(ft_isprint(-1));
    IM_ASSERT_ZERO(ft_isprint(-128));
}


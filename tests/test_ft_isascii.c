#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_isascii(void)
    {
        int c;

        // Test ASCII characters (0 to 127)
        for (c = 0; c <= 127; c++)
        {
            IM_ASSERT_NONZERO(ft_isascii(c));
        }

        // Test values just outside the ASCII range
        IM_ASSERT_ZERO(ft_isascii(-1));   // Just below ASCII range
        IM_ASSERT_ZERO(ft_isascii(128));  // Just above ASCII range

        // Test negative values
        IM_ASSERT_ZERO(ft_isascii(-128));

        // Test values well outside the ASCII range
        IM_ASSERT_ZERO(ft_isascii(255));
        IM_ASSERT_ZERO(ft_isascii(1024));
    }

#include <ctype.h>
#include "../libft.h"
#include "../imtest42/imtest42.h"

void test_ft_toupper(void)
{
    int c;

    // Test 0 to 127 ASCII values
    for (c = 0; c <= 127; c++)
    {
        int result_ft = ft_toupper(c);
        int result_std = toupper(c);
        IM_ASSERT_INT_EQUAL(result_ft, result_std);
    }
}

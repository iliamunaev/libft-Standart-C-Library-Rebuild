#include <ctype.h>
#include "../libft.h"
#include "../imtest42/imtest42.h"

void test_ft_tolower(void)
{
    int c;
    int result_ft;
    int result_std;

    // Test 65 to 90 ASCII values
    for (c = 65; c <= 90; c++)
    {
        result_ft = ft_tolower(c);
        result_std = tolower(c);
        IM_ASSERT_INT_EQUAL(result_ft, result_std);
    }
}

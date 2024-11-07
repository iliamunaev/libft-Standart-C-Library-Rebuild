#include <ctype.h>

#include "../libft.h"
#include "../imtest42/imtest42.h"

void test_ft_tolower(void)
{
    int result_ft;
    int result_std;

    // Test 'A'
    result_ft = ft_tolower(65);
    result_std = tolower(65);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 'Z'
    result_ft = ft_tolower(90);
    result_std = tolower(90);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 'M'
    result_ft = ft_tolower(77);
    result_std = tolower(77);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

}

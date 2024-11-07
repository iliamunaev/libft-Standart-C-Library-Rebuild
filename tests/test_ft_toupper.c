#include <ctype.h>

#include "../libft.h"
#include "../imtest42/imtest42.h"

void test_ft_toupper(void)
{

    int result_ft;
    int result_std;

    // Test 'a'
    result_ft = ft_toupper(97);
    result_std = toupper(97);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 'z'
    result_ft = ft_toupper(122);
    result_std = toupper(122);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);

    // Test 'm'
    result_ft = ft_toupper(109);
    result_std = toupper(109);
    IM_ASSERT_INT_EQUAL(result_ft, result_std);
}

#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_isalpha(void)
{
    // alpha edge cases
	IM_ASSERT_NONZERO(ft_isalpha('a'));
	IM_ASSERT_NONZERO(ft_isalpha('A'));
	IM_ASSERT_NONZERO(ft_isalpha('z'));
	IM_ASSERT_NONZERO(ft_isalpha('Z'));

	// non-alpha edge cases
	IM_ASSERT_ZERO(ft_isalpha('@'));
	IM_ASSERT_ZERO(ft_isalpha('['));
	IM_ASSERT_ZERO(ft_isalpha('`'));
	IM_ASSERT_ZERO(ft_isalpha('{'));

    //alpha middle
    IM_ASSERT_NONZERO(ft_isalpha('m'));
	IM_ASSERT_NONZERO(ft_isalpha('N'));

	// non-alpha
	IM_ASSERT_ZERO(ft_isalpha('1'));
	IM_ASSERT_ZERO(ft_isalpha('@'));
	IM_ASSERT_ZERO(ft_isalpha(' '));

    // non-alpha (non-printable)
    IM_ASSERT_ZERO(ft_isalpha('\n'));
    IM_ASSERT_ZERO(ft_isalpha('\t'));

    // non-alpha (beyond 127)
    IM_ASSERT_ZERO(ft_isalpha(128));
    IM_ASSERT_ZERO(ft_isalpha(255));

    // non-alpha (negative)
    IM_ASSERT_ZERO(ft_isalpha(-1));
    IM_ASSERT_ZERO(ft_isalpha(-128));
}

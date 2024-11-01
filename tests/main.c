#include "../test42lib/test42lib.h"
#include "tests.h"

int	main(void)
{
    printf("Running tests...\n\n");

	/*---Add tests below---------------*/
	printf("***Running tests for ft_isalpha()***\n");
    test_ft_isalpha();

	printf("***Running tests for ft_isprint()***\n");
	test_ft_isprint();

	printf("***Running tests for ft_isdigit()***\n");
	test_ft_isdigit();

	printf("***Running tests for ft_isascii()***\n");
	test_ft_isascii();

	printf("***Running tests for ft_tolower()***\n");
	test_ft_tolower();

	printf("***Running tests for ft_toupper()***\n");
	test_ft_toupper();

	printf("***Running tests for ft_strlen()***\n");
	test_ft_strlen();

	printf("***Running tests for ft_strlcat()***\n");
	test_ft_strlcat();

	printf("***Running tests for ft_strnstr()***\n");
	test_ft_strnstr();

	printf("***Running tests for ft_strncmp()***\n");
	test_ft_strncmp();

	/*---End--------------------------*/

    printf("Tests completed.\n");
    return (0);
}
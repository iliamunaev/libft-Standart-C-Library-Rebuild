#include "../test42lib/test42lib.h"
#include "tests.h"


/*---Add tests functions below------------------------*/


/*---End----------------------------------------------*/

int	main()
{
    printf("Running tests...\n\n");

	/*---Add tests below---------------*/
	printf("***Running tests for test_ft_isalpha()***\n");
    test_ft_isalpha();

	printf("***Running tests for test_ft_isprint()***\n");
	test_ft_isprint();

	printf("***Running tests for test_ft_strlcat()***\n");
	test_ft_strlcat();

	printf("***Running tests for test_ft_tolower()***\n");
	test_ft_tolower();

	printf("***Running tests for test_ft_toupper()***\n");
	test_ft_toupper();
	
	printf("***Running tests for test_ft_isdigit()***\n");
	test_ft_isdigit();

	printf("***Running tests for test_ft_isascii()***\n");
	test_ft_isascii();

	printf("***Running tests for test_ft_strlen()***\n");
	test_ft_strlen();

	/*---End--------------------------*/

    printf("Tests completed.\n");
    return (0);
}
#include <stdio.h>
#include "test42lib/test42lib.h"
#include "../libft.h"

/*---Add tests functions below------------------------*/
void	test_ft_isalpha();
int	test_ft_isprint();

/*---End----------------------------------------------*/

int	main()
{
    printf("Running tests...\n");

	/*---Add tests below---------------*/
	printf("Running tests for test_ft_isalpha()\n");
    test_ft_isalpha();

	printf("Running tests for test_ft_isprint()\n");
	test_ft_isprint();

	/*---End--------------------------*/

    printf("Tests completed.\n");
    return (0);
}
#include <string.h>
#include "../imtest42/imtest42.h"
#include "../libft.h"
#include <stdlib.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len);

void	test_ft_substr(void)
{
	printf("\nTest 1: Basic substring within bounds\n");
	char str1[] = "Hello, world!";
	char *substr1 = ft_substr(str1, 7, 5); // Expected result: "world"
	IM_ASSERT_STR_EQUAL("world", substr1);
	free(substr1);

	printf("\nTest 2: Start index beyond string length\n");
	char str2[] = "Hello, world!";
	char *substr2 = ft_substr(str2, 20, 5); // Expected result: ""
	IM_ASSERT_STR_EQUAL("", substr2);
	free(substr2);

	printf("\nTest 3: Length exceeds remaining characters\n");
	char str3[] = "Hello, world!";
	char *substr3 = ft_substr(str3, 7, 50); // Expected result: "world!"
	IM_ASSERT_STR_EQUAL("world!", substr3);
	free(substr3);

	printf("\nTest 4: Length of zero\n");
	char str4[] = "Hello, world!";
	char *substr4 = ft_substr(str4, 5, 0); // Expected result: ""
	IM_ASSERT_STR_EQUAL("", substr4);
	free(substr4);

	printf("\nTest 5: Empty input string\n");
	char str5[] = "";
	char *substr5 = ft_substr(str5, 0, 5); // Expected result: ""
	IM_ASSERT_STR_EQUAL("", substr5);
	free(substr5);

	printf("\nTest 6: Start at the beginning of the string\n");
	char str6[] = "Hello, world!";
	char *substr6 = ft_substr(str6, 0, 5); // Expected result: "Hello"
	IM_ASSERT_STR_EQUAL("Hello", substr6);
	free(substr6);

	printf("\nTest 7: Start at the end of the string\n");
	char str7[] = "Hello, world!";
	char *substr7 = ft_substr(str7, strlen(str7), 5); // Expected result: ""
	IM_ASSERT_STR_EQUAL("", substr7);
	free(substr7);
}

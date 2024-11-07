#include "../imtest42/imtest42.h"
#include "tests.h"
#include <stdio.h>

void	test_ft_strjoin(void)
{
	const char	*jstr;
	int		jstr_len;
	char		*nul_term;

	printf("\nTest 1: Both strings are non-empty\n");
	jstr = ft_strjoin("a", "b");
	IM_ASSERT_TRUE(jstr != NULL);
	jstr_len = ft_strlen(jstr);
	nul_term = ft_strrchr(jstr, '\0');
	IM_ASSERT_TRUE(nul_term != NULL);
	IM_ASSERT_INT_EQUAL(2, jstr_len);
	IM_ASSERT_STR_EQUAL("ab", jstr);
	free((char *)jstr);

	printf("\nTest 2: Both strings are empty\n");
	jstr = ft_strjoin("", "");
	IM_ASSERT_TRUE(jstr != NULL);
	jstr_len = ft_strlen(jstr);
	IM_ASSERT_INT_EQUAL(0, jstr_len);
	IM_ASSERT_STR_EQUAL("", jstr);
	free((char *)jstr);

	printf("\nTest 3: First string is empty, second string is non-empty\n");
	jstr = ft_strjoin("", "hive");
	IM_ASSERT_TRUE(jstr != NULL);
	jstr_len = ft_strlen(jstr);
	IM_ASSERT_INT_EQUAL(4, jstr_len);
	IM_ASSERT_STR_EQUAL("hive", jstr);
	free((char *)jstr);

	printf("\nTest 4: First string is non-empty, second string is empty\n");
	jstr = ft_strjoin("hive", "");
	IM_ASSERT_TRUE(jstr != NULL);
	jstr_len = ft_strlen(jstr);
	IM_ASSERT_INT_EQUAL(4, jstr_len);
	IM_ASSERT_STR_EQUAL("hive", jstr);
	free((char *)jstr);

	printf("\nTest 5: Both strings are long\n");
	const char *str1 = "This is a long string. ";
	const char *str2 = "And this is another long string.";
	jstr = ft_strjoin(str1, str2);
	IM_ASSERT_TRUE(jstr != NULL);
	jstr_len = ft_strlen(jstr);
	IM_ASSERT_INT_EQUAL(strlen(str1) + strlen(str2), jstr_len);
	IM_ASSERT_STR_EQUAL("This is a long string. And this is another long string.", jstr);
	free((char *)jstr);
}

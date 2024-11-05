#include <stdio.h>

int	count_substr(char const *s, char delim)
{
	int	count;
	int	in_substr;
	
	count = 0;
	in_substr = 0;
	while (*s)
	{
		if (*s != delim && !in_substr)
		{
			in_substr = 1;
			count++;
		}
		else if (*s == delim)
		{
			in_substr = 0;
		}
		s++;
	}
	return (count);
}

void	test_count_substr(void)
{
	// Basic with two words
	printf("2 = %i\n", count_substr("hive 42", ' '));

	// Empty string
	printf("0 = %i\n", count_substr("", '.'));

	// No delimiters 
	printf("1 = %i\n", count_substr("hive42", ' '));

	// String with only delimiters, no substrings
	printf("0 = %i\n", count_substr("!!!!!!", '!'));

	// Continuous delimiters between words
	printf("3 = %i\n", count_substr("hello,,,,,world,42", ','));

	// Delimiter at the beginning and end of the string
	printf("3 = %i\n", count_substr(".hello.world.42.", '.'));

	// Single character which is not a delimiter
	printf("1 = %i\n", count_substr("a", '.'));

	// Single character which is a delimiter
	printf("0 = %i\n", count_substr(".", '.'));

	// Mixed single and continuous delimiters
	printf("5 = %i\n", count_substr("one.two..three...four....five", '.'));

	// Long string with random placement of delimiters
	printf("4 = %i\n", count_substr("apple@@banana@@cherry@@date", '@'));
}

void	main(void)
{
	test_count_substr();
}
/*
 * The fnction allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end
 * with a NULL pointer.
 * Return: the array of new strings resulting from the split;
 * NULL if the allocation fails.
 */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count = 0;
	int	in_word = 0;

	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*dup_word(const char *s, int start, int end)
{
	char	*word = malloc((end - start + 1) * sizeof(char));
	int		i = 0;

	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i = 0;
	int		start = -1;
	int		word_count = count_words(s, c);

	if (!s)
		return (NULL);

	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);

	for (int j = 0; s[j]; j++)
	{
		if (s[j] != c && start == -1)
			start = j;
		else if ((s[j] == c || s[j + 1] == '\0') && start != -1)
		{
			arr[i++] = dup_word(s, start, (s[j] == c ? j : j + 1));
			start = -1;
		}
	}
	arr[i] = NULL;
	return (arr);
}

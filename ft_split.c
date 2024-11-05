/*
 * The fnction allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter.
 * The array must end with a NULL pointer.
 * Return: the array of new strings resulting from the split;
 * NULL if the allocation fails.
 */

#include "libft.h"

static int	count_substr(char const *s, char delim)
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
			in_substr = 0;
		s++;
	}
	return (count);
}

static char	*create_substr(char const *start, int len)
{
	char	*substr;
	int	i;
	
	substr = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = start[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static void	free_all_mem(char **arr, int index)
{
	while (index >= 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		substr_count;
	int		index;
	int		len;

	substr_count = count_substr(s, c);
	arr = (char **)malloc((substr_count + 1) * sizeof(char *));
	index = 0;
	if (!s || !(arr))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c) // Skip delimiters
				s++;
		len = 0;
		while (s[len] && s[len] != c) // Find length of next substring
				len++;
		if (len > 0)
		{
			if (!(arr[index++] = create_substr(s, len)))
			{
				free_all_mem(arr, index - 1);
				return (NULL);
			}
			s += len;
		}
	}
	arr[index] = NULL;
	return (arr);
}

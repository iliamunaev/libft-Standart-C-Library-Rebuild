/* Applies the function ’f’ to each character of the
 * string ’s’, and passing its index as first argument
 * to create a new string (with malloc(3)) resulting
 * from successive applications of ’f’.
 * s: The string on which to iterate.
 * f: The function to apply to each character.
 * Return: String created, NULL if the allocation fails.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nstr;
	unsigned int	i;
	unsigned int	slen;

	i = 0;
	slen = ft_strlen(s);

	if (!s || !f)
	{
		return (NULL);
	}
	nstr = malloc((slen + 1) * sizeof(char));
	if (!nstr)
	{
		return (NULL);
	}
	while (i < slen)
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

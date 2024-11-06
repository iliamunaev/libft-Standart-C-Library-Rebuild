/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:35:18 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/06 23:35:27 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_strnstr() locates the first occurrence of the null-terminated
 * string 'little' in the string 'big', where not more than 'len' characters
 * are searched.
 * Return: 'big', if 'little' is an empty string;
 * NULL if 'little' occurs nowhere in 'big';
 * a pointer to the first character of the first occurrence of 'little'.
 */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (!little)
		return ((char *)big);
	if (len == 0 || len < little_len)
		return (NULL);
	while (big && len >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

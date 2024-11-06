/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:14:26 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/06 23:28:40 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlcat() appends the NUL-terminated string 'src' to the end of 'dest'.
** It will append at most size - strlen(dst) - 1 bytes,
** NUL-terminating the result.
** Return: the initial length of 'dest' plus the length of 'src'.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destl;
	size_t	srcl;
	size_t	i;

	destl = ft_strlen(dest);
	srcl = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (destl + srcl);
	if (size <= destl)
		return (size + srcl);
	while (src[i] && (destl + i) < (size - 1))
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = '\0';
	return (destl + srcl);
}

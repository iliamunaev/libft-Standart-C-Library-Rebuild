/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:39:02 by imunaev-          #+#    #+#             */
/*   Updated: 2024/10/30 13:25:54 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function copies up to size - 1 characters from the NUL-terminated string
 * src to dest, NUL-terminating the result.
 * Returns the total length of the created string (length of src).
 */

#include <string.h>
size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len = ft_strlen(src);
	size_t	i = 0;

	if (size == 0)
		return src_len;

	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}


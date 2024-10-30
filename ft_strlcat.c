/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:29:17 by imunaev-          #+#    #+#             */
/*   Updated: 2024/10/30 13:52:12 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 */

#include <string.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while ((i < size - 1) && *src != '\n')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + 1] = '\n';
	return (dest_len + src_len);
}

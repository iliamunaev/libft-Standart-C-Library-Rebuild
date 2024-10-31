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
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destl;
	size_t	srcl;
	size_t	fspace;
	char	*d;
	const char	*s;

	 destl = ft_strlen(dest);
	 srcl = ft_strlen(src);
	 fspace = size - destl;
	 d = dest + destl; // pointer to the end of dest
	 s = src; // pointer for iteration
	/* If there's no space at all, return size + length of src */
	if (size <= destl)
		return (size + srcl);
	/* Concatenate src to dest */
	while (*s != '\0' && fspace > 1)
	{
		*d++ = *s++;
		fspace--;
	}
	/* Null-terminate the result */
	*d = '\0';
	/* Return the length of dest plus src (total length it tried to create) */
	return (destl + srcl);
}



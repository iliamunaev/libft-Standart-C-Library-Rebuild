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
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destl = ft_strlen(dest);
	size_t	srcl = ft_strlen(src);
	size_t	i = 0;

	// If size is 0, return length of src plus length of dest (without altering dest)
	if (size == 0)
		return (destl + srcl);

	// If size <= destl, return size + srcl directly without modifying dest
	if (size <= destl)
		return (size + srcl);

	// Start appending src to dest from where dest ends
	while (src[i] && (destl + i) < (size - 1))
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = '\0';  // Null-terminate

	// Return the combined length of initial dest and full src
	return (destl + srcl);
}

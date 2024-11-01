/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:40:38 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/01 12:26:55 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function  copies  n bytes from memory area src to memory area dest.
 * Returns a pointer to dest.
 */

#include "string.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

#include "stdio.h"
int	main()
{
	char dest[10] = "aaaaaaaaaa";
	char src[10] = "bcdefg";
	

	printf("Dest befor: %s\n", dest);
	ft_memcpy(dest+1, src, 3);

	printf("dest after: %s\n", dest);

	return (0);
}







/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:54:35 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/05 14:24:40 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function copies n bytes from memory area src to memory area dest.
** The memory areas may overlap: copying takes place as though the bytes in src
** are first copied into a temporary array that does  not  overlap src or dest,
** and the bytes are then copied from the temporary array to dest.
** Returns a pointer to dest.
*/

#include "libft.h"


void	*ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char	*d;
    const unsigned char	*s;
    unsigned char	temp[n];
	const unsigned char 	*t;

	d = dest;
	s = src;
	t = temp;
	ft_memcpy(temp, s, n);
    while (n--)
    {
        *d++ = *t++;
    }
    return (dest);
}

#include <stdio.h>
int main()
{
    unsigned char d[10] = "aaa bbbbb";
    const unsigned char *s = d + 4; // Example overlap scenario

    printf("Dest before: %s\n", d);
    ft_memmove(d, s, 7); // Moving "bbbbb" over "aaa "
    printf("Dest after: %s\n", d);

    return 0;
}

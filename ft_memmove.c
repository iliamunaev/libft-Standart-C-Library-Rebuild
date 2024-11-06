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

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (d == s || n == 0)
        return dest;

    if (d < s)
    {
        // Non-overlapping or forward copy
        while (n--)
            *d++ = *s++;
    }
    else
    {
        // Overlapping regions, copy backwards one byte at a time
        d += n;
        s += n;
        while (n--)
            *--d = *--s;
    }
    return dest;
}

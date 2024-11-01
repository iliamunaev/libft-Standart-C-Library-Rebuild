/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:31:35 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/01 11:44:57 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 * Returns a pointer to the memory area s.
 */

#include <string.h>


void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *buffer;

    buffer = s;
    while (n--)
    {
        *buffer++ = (unsigned char)c;
    }
    return s;
}

#include <stdio.h>
int main(void)
{
    char s[20] = "aaaaaaaaaaaa";
    int c = 'b';
    size_t n = 5;  // Set only the first 5 characters to 'b'

    printf("S before: %s\n", s);

    ft_memset(s, c, n);  // Use ft_memset

    printf("S after: %s\n", s);

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:30:35 by imunaev-          #+#    #+#             */
/*   Updated: 2024/10/30 11:56:23 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The function calculates the length of the string pointed to by s, 
 * excluding the terminating null byte ('\0').
 * Returns the number of bytes in the string pointed to by s.
 */
 #include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;
	count = 0;

	while(*s++)
		count++;
	return (count);
}

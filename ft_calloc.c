/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:38:01 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/06 23:38:26 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_calloc() allocates memory for an array of 'nmemb' elements of
** 'size' bytes each. The memory is set to zero.
** Return:  a pointer to the allocated memory;
** if 'nmemb' or 'size' is  0,  then  calloc()  returns  either NULL, or
** a unique pointer value that can later be successfully passed to free();
** if the multiplication of 'nmemb' and 'size' would result in integer overflow,
** then calloc() returns an error.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	memptr = malloc(nmemb * size);
	if (!memptr)
		return (NULL);
	ft_memset(memptr, 0, nmemb * size);
	return (memptr);
}

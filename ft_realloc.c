/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:40:49 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/06 21:52:22 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Custom implementation of `realloc`.
 *
 * - If `ptr == NULL`, behaves like `malloc(new_size)`.
 * - If `new_size == 0` and `ptr != NULL`, behaves like `free(ptr)`,
 *   returning `NULL`.
 * - If `new_size > old_size`, copies old content and
 *   leaves new memory **uninitialized**.
 * - If `new_size < old_size`, preserves only `new_size` bytes.
 * - If memory is moved, `ptr` is freed automatically.
 *
 * @param ptr      Pointer to previously allocated memory.
 * @param old_size The currently allocated size.
 * @param new_size The desired new size.
 * @return         void* Pointer to the newly allocated memory block or
 *                `NULL` on failure.
 */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	bytes_to_copy;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		bytes_to_copy = old_size;
	else
		bytes_to_copy = new_size;
	ft_memcpy(new_ptr, ptr, bytes_to_copy);
	free(ptr);
	return (new_ptr);
}

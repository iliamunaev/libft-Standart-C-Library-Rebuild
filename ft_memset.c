/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: imunaev- <imunaev-@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/01 10:31:35 by imunaev-		  #+#	#+#			 */
/*   Updated: 2024/11/06 23:22:48 by imunaev-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

/*
** ft_memset() fills the first n bytes of the memory area pointed to by 's'
** with the constant byte 'c'.
** Return: a pointer to the memory area 's'.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buffer;

	buffer = (unsigned char *)s;
	while (n--)
		*buffer++ = (unsigned char)c;
	return (s);
}

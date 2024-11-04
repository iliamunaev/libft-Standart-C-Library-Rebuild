/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:06:22 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/04 14:25:12 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function converts upercasw letters to lowercase.
 * Returns lowercase version of 'c', if the conversion was not possible 'c'.
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

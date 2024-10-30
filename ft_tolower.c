/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:06:22 by imunaev-          #+#    #+#             */
/*   Updated: 2024/10/30 11:13:36 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function converts upercasw letters to lowercase.
 * Returns lowercase version of c or unmodified c if no lowercase version
 * is listed in the current C locale.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'a')
		return (c + ('a' - 'A'));
	else
		return (c);
}

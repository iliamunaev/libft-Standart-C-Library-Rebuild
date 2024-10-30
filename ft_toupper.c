/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:58:26 by imunaev-          #+#    #+#             */
/*   Updated: 2024/10/30 11:56:59 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The function converts upercasw letters to lowercase.
 * Returns uppercase version of c or unmodified c if no uppercase version 
 * is listed in the current C locale.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'A')
		return (c - ('a' - 'A'));
	else
		return (c);
}

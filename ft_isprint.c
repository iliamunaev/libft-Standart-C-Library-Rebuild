/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:13:06 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/04 13:23:12 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* ft_isprint() checks for any printable character including space.
* Return: nonzero if the character c falls into the tested class, else zero.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 127);
}

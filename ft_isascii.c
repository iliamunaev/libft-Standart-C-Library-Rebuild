/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:20:59 by imunaev-          #+#    #+#             */
/*   Updated: 2024/10/30 10:29:45 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * The function tests for an ASCII character (in the range 0 to 127). 
 * Returns: Nonzero if c is an ASCII character; otherwise, zero. 
 */

int	ft_isascii(int ch)
{
	return (ch >= 0 && ch <= 127);
}

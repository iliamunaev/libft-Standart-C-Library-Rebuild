/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:58:26 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/04 14:07:18 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The function converts upercasw letters to lowercase.
 * Return: uppercase version of 'c', if the conversion was not possible 'c'.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

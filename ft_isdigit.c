/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:53:37 by imunaev-          #+#    #+#             */
/*   Updated: 2024/10/30 10:57:37 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The function checks if the given character is a numeric 
 * character (0123456789).
 * Returns non-zero value if the character is a numeric character, 
 * zero otherwise.
 */

int	ft_isdigit(int ch)
{
	return (ch >= 0 && ch <= 9);
}

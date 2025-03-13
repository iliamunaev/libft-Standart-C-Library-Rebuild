/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:48:35 by imunaev-          #+#    #+#             */
/*   Updated: 2025/03/13 11:33:53 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is a whitespace character.
 *
 * This function determines whether the given character is a
 * whitespace character, which includes:
 * - Space (' ')
 * - Newline ('\n')
 * - Form feed ('\f')
 * - Carriage return ('\r')
 * - Horizontal tab ('\t')
 * - Vertical tab ('\v')
 *
 * @param c The character to check.
 * @return int 1 if the character is a whitespace character, 0 otherwise.
 */

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\f' || c == '\r'
		|| c == '\t' || c == '\v');
}

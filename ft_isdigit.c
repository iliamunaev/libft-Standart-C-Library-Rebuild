/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:53:37 by imunaev-          #+#    #+#             */
/*   Updated: 2025/03/13 11:32:57 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is a numeric digit.
 *
 * This function tests whether the given character `c` is a numeric
 * digit (characters '0' through '9').
 *
 * @param c The character to check.
 * @return int Nonzero if the character is a numeric digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:23:44 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/01 10:25:16 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test42lib/test42lib.h"
#include "../libft.h"

void	test_ft_isprint(void)
{
    // Test printble chars
    ASSERT_EQUAL_INT(1, ft_isprint(32));
    ASSERT_EQUAL_INT(1, ft_isprint(127));
    ASSERT_EQUAL_INT(1, ft_isprint('a'));
    ASSERT_EQUAL_INT(1, ft_isprint('Z'));
    ASSERT_EQUAL_INT(1, ft_isprint('@'));
    ASSERT_EQUAL_INT(1, ft_isprint('}'));

    // Test unprintble chars
    ASSERT_EQUAL_INT(0, ft_isprint(31));
    ASSERT_EQUAL_INT(0, ft_isprint(128));
}


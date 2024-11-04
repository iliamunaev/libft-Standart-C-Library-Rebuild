/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:23:44 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/04 13:21:12 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test42lib/test42lib.h"
#include "tests.h"

void	test_ft_isprint(void)
{
    // Printble chars
    ASSERT_RETURN_NONZERO(ft_isprint(32));
    ASSERT_RETURN_NONZERO(ft_isprint(127));
    ASSERT_RETURN_NONZERO(ft_isprint('a'));
    ASSERT_RETURN_NONZERO(ft_isprint('Z'));
    ASSERT_RETURN_NONZERO(ft_isprint('@'));
    ASSERT_RETURN_NONZERO(ft_isprint('}'));

    // printable 'space'
    ASSERT_RETURN_NONZERO(ft_isprint(' '));

    // Unprintble chars
    ASSERT_RETURN_ZERO(ft_isprint(31));
    ASSERT_RETURN_ZERO(ft_isprint(128));
}


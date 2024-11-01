#ifndef TEST42LIB_H
#define TEST42LIB_H

#include <stdio.h>
#include <string.h>

#include "../libft.h"

void	ASSERT_EQUAL_INT(int exp_int, int act_int);
void	ASSERT_EQUAL_STR(const char *exp_str, const char *act_str);
void	ASSERT_EQUAL_CHAR(int exp_char, int act_char);
void	ASSERT_EQUAL_NULL(const void *ptr);
void	ASSERT_STRNCMP(const char *s1, const char *s2, size_t n, int expected);

#endif // TEST42LIB_H

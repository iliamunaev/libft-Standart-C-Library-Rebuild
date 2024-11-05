#ifndef TEST42LIB_H
#define TEST42LIB_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// Integer comparison
void ASSERT_EQUAL_INT(int expected, int actual);

// String comparison
void	ASSERT_EQUAL_STR(const char *expected, const char *actual);

// Character comparison
void	ASSERT_EQUAL_CHAR(char expected, char actual);

// Nonzero return
void	ASSERT_RETURN_NONZERO(int ret);

// Zero return
void	ASSERT_RETURN_ZERO(int ret);

// Pointer comparison
void	ASSERT_EQUAL_PTR(const void *expected, const void *actual);

// Null pointer check
void	ASSERT_EQUAL_NULL(const void *ptr);

// Memory comparison
void	ASSERT_EQUAL_MEM(const void *expected, const void *actual, size_t size);

// Range comparison using strncmp
void	ASSERT_STRNCMP(const char *s1, const char *s2, size_t n, int expected);

// File descriptor output comparision
void	FD_OUTPUT_TO_FILE(void (*func)(int fd), const char *filename);

#endif // TEST42LIB_H

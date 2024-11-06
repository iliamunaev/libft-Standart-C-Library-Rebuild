#ifndef IMTEST42_H
#define IMTEST42_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void IM_ASSERT_INT_EQUAL(int expected, int actual);

void IM_ASSERT_NONZERO(int ret);
void IM_ASSERT_ZERO(int ret);

void IM_ASSERT_STR_EQUAL(const char *expected, const char *actual);
void IM_ASSERT_STR_NOT_EQUAL(const char *expected, const char *actual);

void IM_ASSERT_CHAR_EQUAL(char expected, char actual);

void IM_ASSERT_PTR_NOT_NULL(const void *ptr);
void IM_ASSERT_PTR_NULL(const void *ptr);
void IM_ASSERT_PTR_EQUAL(const void *expected, const void *actual);

void IM_ASSERT_MEM_EQUAL(const void *expected, const void *actual, size_t size);

void IM_FD_OUTPUT_TO_FILE(void (*func)(int fd), const char *filename);
void IM_ASSERT_SPLIT_RESULT(char **result, const char *expected[], int expected_count);
void IM_ASSERT_INT_TO_STR_EQUAL(char *(*func)(int), int n, const char *expected);

#endif //IMTEST42_H

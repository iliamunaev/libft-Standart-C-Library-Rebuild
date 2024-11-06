#include <string.h> // For comparison with the standard bzero
#include <stdlib.h> // For memory allocation functions

#include "../imtest42/imtest42.h"
#include "tests.h"

void	test_ft_bzero(void)
{
	char buffer1[50];
	char buffer2[50];

	// Initialize buffers with non-zero values
	memset(buffer1, 'A', sizeof(buffer1));
	memset(buffer2, 'A', sizeof(buffer2));

	// Test 1: Basic usage
	bzero(buffer1, 10);
	ft_bzero(buffer2, 10);
	IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

	// Test 2: Zero bytes
	bzero(buffer1, 0);
	ft_bzero(buffer2, 0);
	IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

	// Test 3: Entire buffer
	bzero(buffer1, sizeof(buffer1));
	ft_bzero(buffer2, sizeof(buffer2));
	IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));

	// Test 4: Partial zeroing
	bzero(buffer1 + 20, 10);
	ft_bzero(buffer2 + 20, 10);
	IM_ASSERT_MEM_EQUAL(buffer1, buffer2, sizeof(buffer1));
}

#include "../imtest42/imtest42.h"
#include "tests.h"

// Helper
void	putendl_fd(int fd)
{
    ft_putendl_fd("hive", fd);
    ft_putendl_fd("42", fd);
	ft_putendl_fd("nice job!", fd);
}

void	test_ft_putendl_fd(void)
{
    IM_FD_OUTPUT_TO_FILE(putendl_fd, "ft_putendl_fd_test.txt");
}

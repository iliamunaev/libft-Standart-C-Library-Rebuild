#include "../imtest42/imtest42.h"
#include "tests.h"

// Helper
void	putchar_fd(int fd)
{
    ft_putchar_fd('h', fd);
    ft_putchar_fd('i', fd);
    ft_putchar_fd('v', fd);
    ft_putchar_fd('e', fd);
	ft_putchar_fd(' ', fd);
    ft_putchar_fd('4', fd);
	ft_putchar_fd('2', fd);
}

void	test_ft_putchar_fd(void)
{
    IM_FD_OUTPUT_TO_FILE(putchar_fd, "ft_putchar_fd_test.txt");
}

#include "../test42lib/test42lib.h"
#include "tests.h"

// Helper
void	putstr_fd(int fd)
{
    ft_putstr_fd("hive", fd);
    ft_putstr_fd("-! !-", fd);
    ft_putstr_fd("42", fd);
}

void	test_ft_putstr_fd(void)
{
    FD_OUTPUT_TO_FILE(putstr_fd, "ft_putstr_fd_test.txt");
}
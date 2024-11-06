 
 /* The function converts the initial portion of the string pointed to by str to int.
 * Return: the converted value or 0 on error.
 */
 #include "libft.h"

int	ft_atoi(const char *str)
{
    long num = 0;  // Use long to detect overflow
    int sign = 1;
    // Skip whitespace characters
    while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r'
           || *str == '\t' || *str == '\v')
    {
        str++;
    }

    // Handle optional sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Convert digits to integer, checking for overflow
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');

        // Check for overflow or underflow
        if (num * sign > 2147483647)
            return 2147483647;
        if (num * sign < -2147483648)
            return -2147483648;

        str++;
    }

    return (int)(num * sign);
}

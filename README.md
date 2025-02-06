# **Libft-C Library**

The **Libft-C** library is a custom implementation of essential C library functions, developed as part of the Hive Helsinki (School 42) curriculum.

This library provides functions for **memory manipulation, string handling, character classification, data conversion, and file descriptor operations**, among others.

__The library is used in all my C projects.__


## **Function Categories**

### **Memory Manipulation Functions**
- **ft_bzero**: Sets all bytes in a memory block to zero.
- **ft_calloc**: Allocates and zeroes a memory block.
- **ft_memchr**: Locates a byte in a memory block.
- **ft_memcmp**: Compares two memory blocks.
- **ft_memcpy**: Copies bytes between non-overlapping memory blocks.
- **ft_memmove**: Safely copies bytes between potentially overlapping memory blocks.
- **ft_memset**: Sets a memory block to a specific byte value.
- **ft_realloc**: Reallocates memory to a new size.

### **String Manipulation Functions**
- **ft_strlen**: Calculates the length of a string.
- **ft_strdup**: Duplicates a string.
- **ft_strcpy**: Copies a string.
- **ft_strncpy**: Copies a string with a specified limit.
- **ft_strcmp**: Compares two strings.
- **ft_strcat** / **ft_strlcat**: Concatenates strings with length limits.
- **ft_strjoin**: Joins two strings into a new one.
- **ft_strtrim**: Trims characters from the start and end of a string.
- **ft_split**: Splits a string by a specified delimiter.
- **ft_substr**: Extracts a substring from a string.
- **ft_strmapi**: Applies a function to each character of a string to create a new one.
- **ft_striteri**: Applies a function to each character in a string (modifies the original string).
- **ft_strnstr**: Locates a substring in a string, up to a given length.

### **Character Classification and Conversion Functions**
- **ft_isalpha**: Checks if a character is alphabetic.
- **ft_isdigit**: Checks if a character is a digit.
- **ft_isalnum**: Checks if a character is alphanumeric.
- **ft_isascii**: Checks if a character is an ASCII character.
- **ft_isprint**: Checks if a character is printable.
- **ft_isspace**: Checks if a character is a whitespace.
- **ft_is_upper_alpha**: Checks if a character is an uppercase letter.
- **ft_is_lower_alpha**: Checks if a character is a lowercase letter.
- **ft_tolower**: Converts a character to lowercase.
- **ft_toupper**: Converts a character to uppercase.

### **String to Integer and Number Conversion**
- **ft_atoi**: Converts a string to an integer.
- **ft_itoa**: Converts an integer to a string.
- **ft_atoi_base**: Converts a string number in a given base to an integer.

### **File Descriptor Functions**
- **ft_putchar_fd**: Writes a character to a file descriptor.
- **ft_putstr_fd**: Writes a string to a file descriptor.
- **ft_putendl_fd**: Writes a string followed by a newline to a file descriptor.
- **ft_putnbr_fd**: Writes an integer to a file descriptor.
- **get_next_line**: Reads the next line from a file descriptor.
- **ft_printf**: A formatted printing function similar to `printf`.

### **Advanced String Operations**
- **ft_strchr** / **ft_strrchr**: Finds a character in a string.
- **ft_strncmp**: Compares strings up to a specified length.
- **ft_strlcpy**: Copies a string up to a given size.
- **ft_parse_char_arr**: Parses a character array for a specific character.
- **ft_parse_char_2d_arr**: Parses a 2D character array for a specific character.
- **ft_is_char_arr_solid**: Checks if a character array is fully filled with a given character.

### **Bitwise and Debugging Functions**
- **ft_print_bits_int**: Prints the binary representation of an integer.

---

## **Additional Notes**
- This library follows the **C standard library behavior** and extends it with additional helper functions.
- `ft_printf` supports **formatted output**, similar to `printf`, making it useful for debugging.
- `get_next_line` helps read files **line by line** efficiently.
- `ft_realloc` mimics `realloc()` but allows manual tracking of memory block sizes.

---

# <span style="color: SteelBlue;">Libft-C Library + "test42lib.h" Test Library</span>

The **Libft-C** library is a custom implementation of essential C library functions, developed as part of the Hive Helsinki (School 42) curriculum. This library provides tools for memory manipulation, string handling, character classification, and data conversion.

## <span style="color: SteelBlue;"> "test42lib.h" Test Library</span>

The **"test42lib.h"** test library was developed to validate the accuracy and robustness of the **Libft-C** functions.

## Function Categories

### Memory Manipulation Functions

These functions allow for precise control over memory blocks, such as setting specific values, copying data between memory areas, and ensuring safe handling of overlapping memory regions.

### String Manipulation Functions

Functions in this category provide operations for C strings (null-terminated character arrays), including length calculation, copying, appending, and safe manipulation of substrings within specified limits.

### Character Classification and Conversion Functions

This group of functions includes utilities for determining character types (such as alphabetic, numeric, or alphanumeric) and for converting characters to uppercase or lowercase as needed.

### String to Integer Conversion Function

This function enables conversion of strings to integers, handling details like leading whitespace and optional signs for compatibility with various numeric formats.

### Check Memory Leaks

To check for memory leaks in your program, you can use Valgrind. Follow the steps below:

1. **Install Valgrind**:
   ```bash
   sudo apt-get install valgrind
   ```

   ```bash
   valgrind --leak-check=full ./test_me
   ```
## Tests
//// in progress

### 1. Tests with CUnit

   ```bash
cc cu_tests.c -o test_cu ../../libft.a -lcunit
   ```


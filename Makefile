NAME = libft.a

CC = cc

# The CFLAGS variable sets compile flags for cc:
# -Wall   : Give verbose compiler warnings
# -Wextra : Enables extra warning flags that are not enabled by -Wall
# -Werror : Make all warnings into errors
CFLAGS = -Wall -Wextra -Werror

# Source files (add your actual .c filenames here, or use wildcard to grab all .c files in the directory)
SRC = $(wildcard *.c)
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Header file
HEADER = libft.h

# Default rule to create the library
all: $(NAME)

# Main target to create the library
#  - 'r': Replace or add files into the archive
#  - 'c': Create the archive if it does not exist
#  - 's': Write an index (symbol table) into the archive for faster linking
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to compile source files into object files in the obj directory
$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Ensure the obj directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Phony targets to prevent make from thinking these are files
.PHONY: all clean fclean re

# Clean object files and directory
clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

# Clean all generated files (including the library)
fclean: clean
	rm -f $(NAME)

# Clean and rebuild the project
re: fclean all
# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Target executable
TARGET = test_me

# Directories
TEST42_DIR = ../test42lib
LIBFT_DIR = ..  # Assuming libft.a is in the parent directory
OBJ_DIR = obj

# Include paths
INCLUDES = -I$(TEST42_DIR) -I$(LIBFT_DIR)

# Source files
SRC = $(wildcard *.c $(TEST42_DIR)/*.c)
# Object files
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Default rule to build the target
all: $(OBJ_DIR) $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft  # Link against libft.a

# Rule to compile all .c files into .o files in the obj directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Phony targets for cleaning
.PHONY: all clean fclean re

# Clean object files
clean:
	rm -f $(OBJ)  # Clean individual object files

# Clean all generated files (including the executable)
fclean: clean
	rm -f $(TARGET)

# Clean and rebuild the project
re: fclean all

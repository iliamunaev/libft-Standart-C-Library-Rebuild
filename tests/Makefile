# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Target executable
TARGET = test_me

# Directories
LIB_DIR = ../test42lib
LIBFT_DIR = ..
OBJ_DIR = obj

# Source files
SRC_TESTS = $(wildcard *.c)
SRC_LIB = $(wildcard $(LIB_DIR)/*.c)
SRC_FUNCS = $(wildcard $(LIBFT_DIR)/*.c)
SRC = $(SRC_TESTS) $(SRC_LIB) $(SRC_FUNCS)

# Object files (located in obj directory)
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Default rule to build the target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .c files from current directory, LIB_DIR, and LIBFT_DIR into obj directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Rule to create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Phony targets for cleaning
.PHONY: all clean fclean re

# Clean object files and directory
clean:
	rm -rf $(OBJ_DIR)

# Clean all generated files (including the executable)
fclean: clean
	rm -f $(TARGET)

# Clean and rebuild the project
re: fclean all

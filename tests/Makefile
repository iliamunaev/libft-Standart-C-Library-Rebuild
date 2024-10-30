CC = cc
CFLAGS = -Wall -Wextra -Werror

# Target executable
TARGET = test

SRC_TESTS = $(wildcard *.c)
SRC_FUNCS = $(wildcard ../*.c)
SRC = $(SRC_TESTS) $(SRC_FUNCS)

# Object files (generated from source files)
OBJ = $(SRC:.c=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

# Rebuild
re: fclean all

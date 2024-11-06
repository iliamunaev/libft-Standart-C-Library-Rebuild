#!/bin/bash

LIBFT_DIR="."
TESTS_DIR="tests"

# Function to compile a directory
compile() {
    local dir=$1
    echo "Cleaning and compiling in $dir..."
    (cd "$dir" && make clean && make) || { echo "Error: Failed to compile in $dir"; exit 1; }
}

# Compile libft
compile "$LIBFT_DIR"

# Compile tests
compile "$TESTS_DIR"

echo "All components compiled successfully."
